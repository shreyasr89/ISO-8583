#include <memory>
#include <typeinfo>

#include "Poco/Net/TCPServerConnectionFactory.h"
#include "Poco/Net/TCPServerConnection.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/TCPServerParams.h"
#include "Poco/Net/TCPServer.h"
#include "Poco/Net/TCPServerConnection.h"
#include "Poco/Logger.h"
#include "Poco/Exception.h"
#include "Poco/Thread.h"
#include "Poco/Delegate.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/ByteOrder.h"
#include "Poco/Timespan.h"

using Poco::Net::TCPServerConnectionFactoryImpl;
using Poco::Net::TCPServerConnectionFactory;
using Poco::Net::TCPServerConnection;
using Poco::Net::ServerSocket;
using Poco::Net::StreamSocket;
using Poco::Net::TCPServerParams;
using Poco::Net::TCPServer;
using Poco::Net::TCPServerConnection;
using Poco::Logger;
using Poco::AutoPtr;
using Poco::Thread;
using Poco::delegate;
using Poco::Util::ServerApplication;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;
using Poco::ByteOrder;
using Poco::Timespan;

#include "ISO-8583/MSG/Request.h"
#include "ISO-8583/MSG/Notification.h"
#include "ISO-8583/MSG/Advice.h"
#include "ISO-8583/MSG/Instruction.h"
#include "ISO-8583/MSG/RequestResponse.h"
#include "ISO-8583/MSG/AdviceResponse.h"
#include "ISO-8583/MSG/NotificationAcknowledge.h"
#include "ISO-8583/MSG/InstructionAcknowledge.h"

#include "ISO-8583/MSG/Message.h"
#include "ISO-8583/MSG/Factory.h"
#include "ISO-8583/MSG/SocketChannel.h"

using namespace std;
using namespace ISO_8583::COM;
using namespace ISO_8583::MSG;

template <class S, class Arg>
class ConnectionFactory : public TCPServerConnectionFactory {
private:
	const Arg& arg;

public:
	ConnectionFactory(const Arg& arg) : arg(arg) { }
	~ConnectionFactory() {	}
	
	TCPServerConnection* createConnection(const StreamSocket& socket) {
		return new S(socket, arg);
	}
};

class Connection : public TCPServerConnection {
private:
	const Factory& factory;

public:
    Connection(const StreamSocket& socket, const Factory& factory) :
        TCPServerConnection(socket),
		factory(factory){
    }

	void run() {
		Application& app = Application::instance();
		Logger& logger = app.logger();
		logger.information("Connection    from: " + socket().peerAddress().toString());

		SocketChannel socketChannel(&logger, socket());
		bool shutdown = false;
		Exception* exception = NULL;

		while (!shutdown) {
			int received = -1;
			BinaryInputStream is;
			try {
				received = socketChannel.recv(is);
				if (received == 0){
					shutdown = true;
				}
				else{
					BinaryOutputStream os(2048);
					unique_ptr<Message> message(factory.newMessage(is));
					logger.information(string("<<< ") + typeid(*message).name());

					if (message.get()) {

						switch (message.get()->function()) {
						case Function::Request: {
							Request* request = dynamic_cast<Request*>(message.get());
							exception = static_cast<Exception*>(request);
							if (logger.debug())
								request->dump(cout);

							RequestResponse* rr = request->indication(is, os);
							if (rr) {
								Message* message = dynamic_cast<Message*>(rr);
								logger.information(string(">>> ") + typeid(*message).name());
								if (logger.debug())
									message->dump(cout);
								message->encode(os);
								delete message;
							}}
							break;

						case Function::Advice: {
							Advice* advice = dynamic_cast<Advice*>(message.get());
							exception = static_cast<Exception*>(advice);
							if (logger.debug())
								advice->dump(cout);
							
							AdviceResponse* ar = advice->indication(is, os);
							if (ar) {
								Message* message = dynamic_cast<Message*>(ar);
								logger.information(string(">>> ") + typeid(*message).name());
								if (logger.debug())
									message->dump(cout);
								message->encode(os);
								delete message;
							}}
							break;

						case Function::Notification: {
							Notification* notification = dynamic_cast<Notification*>(message.get());
							exception = static_cast<Exception*>(notification);
							if (logger.debug())
								notification->dump(cout);
							
							NotificationAcknowledge* na = notification->indication(is, os);
							if (na) {
								Message* message = dynamic_cast<Message*>(na);
								logger.information(string(">>> ") + typeid(*message).name());
								if (logger.debug())
									message->dump(cout);
								message->encode(os);
								delete message;
							}}
							break;
						
						case Function::Instruction: {
							Instruction* instruction = dynamic_cast<Instruction*>(message.get());
							exception = static_cast<Exception*>(instruction);
							if (logger.debug())
								instruction->dump(cout);

							InstructionAcknowledge* ia = instruction->indication(is, os);
							if (ia) {
								Message* message = dynamic_cast<Message*>(ia);
								logger.information(string(">>> ") + typeid(*message).name());
								if (logger.debug())
									message->dump(cout);
								message->encode(os);
								delete message;
							}}
							break;
						default:
							logger.critical("invalid input message");
						}
						socketChannel.send(os);
					}
					else {
						logger.critical("invalid input message");
					}
				}
			}
			catch (Poco::Exception& exc) {
				logger.log(exc);
				if (exception)
					shutdown = exception->exception(exc);
			}
			catch (std::exception& exc) {
				logger.error(exc.what());
				shutdown = true;
				if (exception)
					shutdown = exception->exception(exc);
			}
			catch (...) {
				logger.error("Unknown exception");
				shutdown = true;
				if (exception)
					shutdown = exception->exception();
			}
		}
		socket().shutdown();
		logger.information("Disconnecting from: " + socket().peerAddress().toString());
	}
};

class ISO_8583_SRV_1987: public ServerApplication {
private:
	bool _helpRequested;

public:
	ISO_8583_SRV_1987() : _helpRequested(false)	{ }
	~ISO_8583_SRV_1987() { }

protected:
	void initialize(Application& self) {
		loadConfiguration(); 
		ServerApplication::initialize(self);
	}
		
	void uninitialize() {
		ServerApplication::uninitialize();
	}

	void defineOptions(OptionSet& options) {
		ServerApplication::defineOptions(options);
		
		options.addOption(
			Option("help", "h", "display help information on command line arguments")
				.required(false)
				.repeatable(false));
	}

	void handleOption(const std::string& name, const std::string& value) {
		ServerApplication::handleOption(name, value);

		if (name == "help")
			_helpRequested = true;
	}

	void displayHelp() {
		HelpFormatter helpFormatter(options());
		helpFormatter.setCommand(commandName());
		helpFormatter.setUsage("OPTIONS");
		helpFormatter.setHeader("A ISO_8583::1987 server.");
		helpFormatter.format(std::cout);
	}

	int main(const std::vector<std::string>& args) {
		if (_helpRequested)	{
			displayHelp();
		}
		else	{
			// get parameters from configuration file
			unsigned short port = (unsigned short)config().getInt("port", 9977);

			ServerSocket serverSocket(port);

			//Configure some server params.
			TCPServerParams* tcpParameters = new Poco::Net::TCPServerParams();
			tcpParameters->setMaxThreads(4);
			tcpParameters->setMaxQueued(4);
			tcpParameters->setThreadIdleTime(100);

			string library = config().getString("library", "ISO-8583-DFT-1987");
			Factory factory(library);
			//Create server 
			TCPServerConnectionFactory* connectionFactory;
			connectionFactory = new ConnectionFactory<Connection, Factory>(factory);
			TCPServer iso8583(connectionFactory, serverSocket, tcpParameters);
			iso8583.start();

			while (1);

		}
		return Application::EXIT_OK;
	}
};

POCO_SERVER_MAIN(ISO_8583_SRV_1987)

