/*
 * Factory.cpp
 *
 *  Created on: 2 août 2015
 *      Author: FrancisANDRE
 */

#include <iostream>

#include "Poco/ClassLoader.h"
#include "Poco/Manifest.h"

#include "ISO-8583/MSG/Message.h"
#include "ISO-8583/MSG/Factory.h"
#include "ISO-8583/MSG/AuthorizationRequestResponse.h"
#include "ISO-8583/MSG/ReversalRequestResponse.h"
#include "ISO-8583/MSG/NetworkRequestResponse.h"

using namespace std;
using namespace ISO_8583::DTE;

namespace ISO_8583 {
	namespace MSG {

		const char* Factory::RequestInterface								= "Request";
		const char* Factory::NotificationInterface							= "Notification";
		const char* Factory::AdviceInterface								= "Advice";
		const char* Factory::InstructionInterface							= "Instruction";

		const char* Factory::RequestResponseInterface						= "RequestResponse";
		const char* Factory::NotificationAcknowledgeInterface				= "NotificationAcknowledge";
		const char* Factory::AdviceResponseInterface						= "AdviceResponse";
		const char* Factory::InstructionAcknowledgeInterface				= "InstructionAcknowledge";

		const char* Factory::AuthorizationRequestInterface					= "AuthorizationRequest";
		const char* Factory::FinancialRequestInterface						= "FinancialRequest";
		const char* Factory::FileActionRequestInterface 					= "FileActionRequest";
		const char* Factory::ReversalRequestInterface     					= "ReversalRequest";
		const char* Factory::ReconciliationRequestInterface    				= "ReconciliationRequest";
		const char* Factory::AdministrativeRequestInterface     			= "AdministrativeRequest";
		const char* Factory::NetworkRequestInterface     					= "NetworkRequest";

		const char* Factory::AuthorizationRequestResponseInterface			= "AuthorizationRequestResponse";
		const char* Factory::FinancialRequestResponseInterface				= "FinancialRequestResponse";
		const char* Factory::FileActionRequestResponseInterface				= "FileActionRequestResponse";
		const char* Factory::ReversalRequestResponseInterface				= "ReversalRequestResponse";
		const char* Factory::ReconciliationRequestResponseInterface			= "ReconciliationRequestResponse";
		const char* Factory::AdministrativeRequestResponseInterface			= "AdministrativeRequestResponse";
		const char* Factory::NetworkRequestResponseInterface     			= "NetworkRequestResponse";

		const char* Factory::AuthorizationAdviceInterface     				= "AuthorizationAdvice";
		const char* Factory::FinancialAdviceInterface     					= "FinancialAdvice";
		const char* Factory::FileActionAdviceInterface     					= "FileActionAdvice";
		const char* Factory::ReversalAdviceInterface     					= "ReversalAdvice";
		const char* Factory::ReconciliationAdviceInterface     				= "ReconciliationAdvice";
		const char* Factory::AdministrativeAdviceInterface     				= "AdministrativeAdvice";
		const char* Factory::NetworkAdviceInterface     					= "NetworkAdvice";

		const char* Factory::AuthorizationAdviceResponseInterface			= "AuthorizationAdviceResponse";
		const char* Factory::FinancialAdviceResponseInterface				= "FinancialAdviceResponse";
		const char* Factory::FileActionAdviceResponseInterface				= "FileActionAdviceResponse";
		const char* Factory::ReversalAdviceResponseInterface				= "ReversalAdviceResponse";
		const char* Factory::ReconciliationAdviceResponseInterface			= "ReconciliationAdviceResponse";
		const char* Factory::AdministrativeAdviceResponseInterface			= "AdministrativeAdviceResponse";
		const char* Factory::NetworkAdviceResponseInterface					= "NetworkAdviceResponse";

		const char* Factory::AuthorizationNotificationInterface  			= "AuthorizationNotification";
		const char* Factory::FinancialNotificationInterface  				= "FinancialNotification";
		const char* Factory::FileActionNotificationInterface  				= "FileActionNotification";
		const char* Factory::ReversalNotificationInterface  				= "ReversalNotification";
		const char* Factory::ReconciliationNotificationInterface  			= "ReconciliationNotification";
		const char* Factory::AdministrativeNotificationInterface  			= "AdministrativeNotification";
		const char* Factory::NetworkNotificationInterface  					= "NetworkNotification";

		const char* Factory::AuthorizationNotificationAcknowledgeInterface	= "AuthorizationNotificationAcknowledge";
		const char* Factory::FinancialNotificationAcknowledgeInterface		= "FinancialNotificationAcknowledge";
		const char* Factory::FileActionNotificationAcknowledgeInterface		= "FileActionNotificationAcknowledge";
		const char* Factory::ReversalNotificationAcknowledgeInterface		= "ReversalNotificationAcknowledge";
		const char* Factory::ReconciliationNotificationAcknowledgeInterface	= "ReconciliationNotificationAcknowledge";
		const char* Factory::AdministrativeNotificationAcknowledgeInterface	= "AdministrativeNotificationAcknowledge";
		const char* Factory::NetworkNotificationAcknowledgeInterface		= "NetworkNotificationAcknowledge";

		const char* Factory::AuthorizationInstructionInterface				= "AuthorizationInstruction";
		const char* Factory::FinancialInstructionInterface					= "FinancialInstruction";
		const char* Factory::FileActionInstructionInterface					= "FileActionInstruction";
		const char* Factory::ReversalInstructionInterface					= "ReversalInstruction";
		const char* Factory::ReconciliationInstructionInterface				= "ReconciliationInstruction";
		const char* Factory::AdministrativeInstructionInterface				= "AdministrativeInstruction";
		const char* Factory::NetworkInstructionInterface					= "NetworkInstruction";

		const char* Factory::AuthorizationInstructionAcknowledgeInterface   = "AuthorizationInstructionAcknowledge";
		const char* Factory::FinancialInstructionAcknowledgeInterface		= "FinancialInstructionAcknowledge";
		const char* Factory::FileActionInstructionAcknowledgeInterface		= "FileActionInstructionAcknowledge";
		const char* Factory::ReversalInstructionAcknowledgeInterface		= "ReversalInstructionAcknowledge";
		const char* Factory::ReconciliationInstructionAcknowledgeInterface  = "ReconciliationInstructionAcknowledge";
		const char* Factory::AdministrativeInstructionAcknowledgeInterface  = "AdministrativeInstructionAcknowledge";
		const char* Factory::NetworkInstructionAcknowledgeInterface			= "NetworkInstructionAcknowledge";


		Factory::Factory(const string& libname) {
#if POCO_OS == POCO_OS_CYGWIN
//			library = Poco::SharedLibrary::prefix();
			library = "cyg";
#endif
			library += libname;
			library += Poco::SharedLibrary::suffix();

			cout << "library=" << library << endl;
			requestLoader.loadLibrary(library, RequestInterface);
			notificationLoader.loadLibrary(library, NotificationInterface);
			adviceLoader.loadLibrary(library, AdviceInterface);
			instructionLoader.loadLibrary(library, InstructionInterface);

			requestResponseLoader.loadLibrary(library, RequestResponseInterface);
			adviceResponseLoader.loadLibrary(library, AdviceResponseInterface);
			notificationAcknowledgeLoader.loadLibrary(library, NotificationAcknowledgeInterface);
			instructionAcknowledgeLoader.loadLibrary(library, InstructionAcknowledgeInterface);
			
		}
		Factory::~Factory() {
			requestLoader.unloadLibrary(library);
			notificationLoader.unloadLibrary(library);
			adviceLoader.unloadLibrary(library);
			instructionLoader.unloadLibrary(library);

			requestResponseLoader.loadLibrary(library);
			adviceResponseLoader.loadLibrary(library);
			notificationAcknowledgeLoader.loadLibrary(library);
			instructionAcknowledgeLoader.loadLibrary(library);
		}




		Message* Factory::newMessage(BinaryInputStream& is) const {
			Message*	message = NULL;

			MTI mti;
			is.markit();
			is >> mti;
			is.reset();

			Version version = mti.version();
			Class klass = mti.klass();
			Function function = mti.function();
			Origin origin = mti.origin();

			switch (version) {

			case Version::ISO_8583_1_1987:
				switch (klass) {

				case Class::Authorization:
					switch (function) {

					case Function::Request:
						message = dynamic_cast<Message*>(newAuthorizationRequest(origin));
						break;
					case Function::RequestResponse:
						message = dynamic_cast<Message*>(newAuthorizationRequestResponse(origin));
						break;
					case Function::Advice:
						message = dynamic_cast<Message*>(newAuthorizationAdvice(origin));
						break;
					case Function::AdviceResponse:
						message = dynamic_cast<Message*>(newAuthorizationAdviceResponse(origin));
						break;
					case Function::Notification:
						message = dynamic_cast<Message*>(newAuthorizationNotification(origin));
						break;
					case Function::NotificationAcknowledge:
						message = dynamic_cast<Message*>(newAuthorizationNotificationAcknowledge(origin));
						break;
					case Function::Instruction:
						message = dynamic_cast<Message*>(newAuthorizationInstruction(origin));
						break;
					case Function::InstructionAcknowledge:
						message = dynamic_cast<Message*>(newAuthorizationInstructionAcknowledge(origin));
						break;
					default:
						throw invalid_argument("Message: unsupported function");
						break;
					}
					break;

				case Class::Reversal:
					switch (function) {

					case Function::Request:
						message = dynamic_cast<Message*>(newReversalRequest(origin));
						break;
					case Function::RequestResponse:
						message = dynamic_cast<Message*>(newReversalRequestResponse(origin));
						break;
					case Function::Advice:
						message = dynamic_cast<Message*>(newReversalAdvice(origin));
						break;
					case Function::AdviceResponse:
						message = dynamic_cast<Message*>(newReversalAdviceResponse(origin));
						break;
					case Function::Notification:
						message = dynamic_cast<Message*>(newReversalNotification(origin));
						break;
					case Function::NotificationAcknowledge:
						message = dynamic_cast<Message*>(newReversalNotificationAcknowledge(origin));
						break;
					case Function::Instruction:
						message = dynamic_cast<Message*>(newReversalInstruction(origin));
						break;
					case Function::InstructionAcknowledge:
						message = dynamic_cast<Message*>(newReversalInstructionAcknowledge(origin));
						break;
					default:
						throw invalid_argument("Message: unsupported function");
						break;
					}
					break;

				case Class::Network:
					switch (function) {

					case Function::Request:
						message = dynamic_cast<Message*>(newNetworkRequest(origin));
						break;
					case Function::RequestResponse:
						message = dynamic_cast<Message*>(newNetworkRequestResponse(origin));
						break;
					case Function::Advice:
						message = dynamic_cast<Message*>(newNetworkAdvice(origin));
						break;
					case Function::AdviceResponse:
						message = dynamic_cast<Message*>(newNetworkAdviceResponse(origin));
						break;
					case Function::Notification:
						message = dynamic_cast<Message*>(newNetworkNotification(origin));
						break;
					case Function::NotificationAcknowledge:
						message = dynamic_cast<Message*>(newNetworkNotificationAcknowledge(origin));
						break;
					case Function::Instruction:
						message = dynamic_cast<Message*>(newNetworkInstruction(origin));
						break;
					case Function::InstructionAcknowledge:
						message = dynamic_cast<Message*>(newNetworkInstructionAcknowledge(origin));
						break;
					default:
						throw invalid_argument("Message: unsupported function");
						break;
					}
					break;
				case Class::Financial:
					switch (function) {
					case Function::Request:
						message = dynamic_cast<Message*>(newFinancialRequest(origin));
						break;
					case Function::RequestResponse:
						message = dynamic_cast<Message*>(newFinancialRequestResponse(origin));
						break;
					case Function::Advice:
						message = dynamic_cast<Message*>(newFinancialAdvice(origin));
						break;
					case Function::AdviceResponse:
						message = dynamic_cast<Message*>(newFinancialAdviceResponse(origin));
						break;
					case Function::Notification:
						message = dynamic_cast<Message*>(newFinancialNotification(origin));
						break;
					case Function::NotificationAcknowledge:
						message = dynamic_cast<Message*>(newFinancialNotificationAcknowledge(origin));
						break;
					case Function::Instruction:
						message = dynamic_cast<Message*>(newFinancialInstruction(origin));
						break;
					case Function::InstructionAcknowledge:
						message = dynamic_cast<Message*>(newFinancialInstructionAcknowledge(origin));
						break;
					default:
						throw invalid_argument("Message: unsupported function");
						break;
					}
				case Class::FileAction:
					switch (function) {
					case Function::Request:
						message = dynamic_cast<Message*>(newFileActionRequest(origin));
						break;
					case Function::RequestResponse:
						message = dynamic_cast<Message*>(newFileActionRequestResponse(origin));
						break;
					case Function::Advice:
						message = dynamic_cast<Message*>(newFileActionAdvice(origin));
						break;
					case Function::AdviceResponse:
						message = dynamic_cast<Message*>(newFileActionAdviceResponse(origin));
						break;
					case Function::Notification:
						message = dynamic_cast<Message*>(newFileActionNotification(origin));
						break;
					case Function::NotificationAcknowledge:
						message = dynamic_cast<Message*>(newFileActionNotificationAcknowledge(origin));
						break;
					case Function::Instruction:
						message = dynamic_cast<Message*>(newFileActionInstruction(origin));
						break;
					case Function::InstructionAcknowledge:
						message = dynamic_cast<Message*>(newFileActionInstructionAcknowledge(origin));
						break;
					default:
						throw invalid_argument("Message: unsupported function");
						break;
					}
				case Class::Reconciliation:
					switch (function) {
					case Function::Request:
						message = dynamic_cast<Message*>(newReconciliationRequest(origin));
						break;
					case Function::RequestResponse:
						message = dynamic_cast<Message*>(newReconciliationRequestResponse(origin));
						break;
					case Function::Advice:
						message = dynamic_cast<Message*>(newReconciliationAdvice(origin));
						break;
					case Function::AdviceResponse:
						message = dynamic_cast<Message*>(newReconciliationAdviceResponse(origin));
						break;
					case Function::Notification:
						message = dynamic_cast<Message*>(newReconciliationNotification(origin));
						break;
					case Function::NotificationAcknowledge:
						message = dynamic_cast<Message*>(newReconciliationNotificationAcknowledge(origin));
						break;
					case Function::Instruction:
						message = dynamic_cast<Message*>(newReconciliationInstruction(origin));
						break;
					case Function::InstructionAcknowledge:
						message = dynamic_cast<Message*>(newReconciliationInstructionAcknowledge(origin));
						break;
					default:
						throw invalid_argument("Message: unsupported function");
						break;
					}
				case Class::Administrative:
					switch (function) {
					case Function::Request:
						message = dynamic_cast<Message*>(newAdministrativeRequest(origin));
						break;
					case Function::RequestResponse:
						message = dynamic_cast<Message*>(newAdministrativeRequestResponse(origin));
						break;
					case Function::Advice:
						message = dynamic_cast<Message*>(newAdministrativeAdvice(origin));
						break;
					case Function::AdviceResponse:
						message = dynamic_cast<Message*>(newAdministrativeAdviceResponse(origin));
						break;
					case Function::Notification:
						message = dynamic_cast<Message*>(newAdministrativeNotification(origin));
						break;
					case Function::NotificationAcknowledge:
						message = dynamic_cast<Message*>(newAdministrativeNotificationAcknowledge(origin));
						break;
					case Function::Instruction:
						message = dynamic_cast<Message*>(newAdministrativeInstruction(origin));
						break;
					case Function::InstructionAcknowledge:
						message = dynamic_cast<Message*>(newAdministrativeInstructionAcknowledge(origin));
						break;
					default:
						throw invalid_argument("Message: unsupported function");
						break;
					}
				case Class::FeeCollection:
				case Class::RESERVED:
				default:
					throw invalid_argument("Message: unsupported class");
				}
				break;

			case Version::ISO_8583_1_1993:
			case Version::ISO_8583_1_2003:
			default:
				throw invalid_argument("Message: unsupported version");
				break;
			}

			if (message)
				message->decode(is);
			return message;
		}


// =============================================================================================
#define NEW(name, type, loader) \
	MSG::type*					Factory::new##name##type(Origin origin) const { \
		MSG::type* t = loader.create(name##type##Interface); \
		MSG::MTI* mti = dynamic_cast<MSG::MTI*>(t); \
		mti->origin(origin); \
		return t; \
	}
// =============================================================================================

		NEW(Authorization, Request, requestLoader)
		NEW(Financial, Request, requestLoader)
		NEW(FileAction, Request, requestLoader)
		NEW(Reversal, Request, requestLoader)
		NEW(Reconciliation, Request, requestLoader)
		NEW(Administrative, Request, requestLoader)
		NEW(Network, Request, requestLoader)

		NEW(Authorization, RequestResponse, requestResponseLoader)
		NEW(Financial, RequestResponse, requestResponseLoader)
		NEW(FileAction, RequestResponse, requestResponseLoader)
		NEW(Reversal, RequestResponse, requestResponseLoader)
		NEW(Reconciliation, RequestResponse, requestResponseLoader)
		NEW(Administrative, RequestResponse, requestResponseLoader)
		NEW(Network, RequestResponse, requestResponseLoader)

		NEW(Authorization, Advice, adviceLoader)
		NEW(Financial, Advice, adviceLoader)
		NEW(FileAction, Advice, adviceLoader)
		NEW(Reversal, Advice, adviceLoader)
		NEW(Reconciliation, Advice, adviceLoader)
		NEW(Administrative, Advice, adviceLoader)
		NEW(Network, Advice, adviceLoader)

		NEW(Authorization, AdviceResponse, adviceResponseLoader)
		NEW(Financial, AdviceResponse, adviceResponseLoader)
		NEW(FileAction, AdviceResponse, adviceResponseLoader)
		NEW(Reversal, AdviceResponse, adviceResponseLoader)
		NEW(Reconciliation, AdviceResponse, adviceResponseLoader)
		NEW(Administrative, AdviceResponse, adviceResponseLoader)
		NEW(Network, AdviceResponse, adviceResponseLoader)

		NEW(Authorization, Notification, notificationLoader)
		NEW(Financial, Notification, notificationLoader)
		NEW(FileAction, Notification, notificationLoader)
		NEW(Reversal, Notification, notificationLoader)
		NEW(Reconciliation, Notification, notificationLoader)
		NEW(Administrative, Notification, notificationLoader)
		NEW(Network, Notification, notificationLoader)

		NEW(Authorization, NotificationAcknowledge, notificationAcknowledgeLoader)
		NEW(Financial, NotificationAcknowledge, notificationAcknowledgeLoader)
		NEW(FileAction, NotificationAcknowledge, notificationAcknowledgeLoader)
		NEW(Reversal, NotificationAcknowledge, notificationAcknowledgeLoader)
		NEW(Reconciliation, NotificationAcknowledge, notificationAcknowledgeLoader)
		NEW(Administrative, NotificationAcknowledge, notificationAcknowledgeLoader)
		NEW(Network, NotificationAcknowledge, notificationAcknowledgeLoader)

		NEW(Authorization, Instruction, instructionLoader)
		NEW(Financial, Instruction, instructionLoader)
		NEW(FileAction, Instruction, instructionLoader)
		NEW(Reversal, Instruction, instructionLoader)
		NEW(Reconciliation, Instruction, instructionLoader)
		NEW(Administrative, Instruction, instructionLoader)
		NEW(Network, Instruction, instructionLoader)

		NEW(Authorization, InstructionAcknowledge, instructionAcknowledgeLoader)
		NEW(Financial, InstructionAcknowledge, instructionAcknowledgeLoader)
		NEW(FileAction, InstructionAcknowledge, instructionAcknowledgeLoader)
		NEW(Reversal, InstructionAcknowledge, instructionAcknowledgeLoader)
		NEW(Reconciliation, InstructionAcknowledge, instructionAcknowledgeLoader)
		NEW(Administrative, InstructionAcknowledge, instructionAcknowledgeLoader)
		NEW(Network, InstructionAcknowledge, instructionAcknowledgeLoader)

	}
}
