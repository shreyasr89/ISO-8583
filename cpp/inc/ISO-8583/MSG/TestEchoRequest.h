/*
 * TestEchoRequest.h
 *
 *  Created on: 17 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef TESTECHORequest_H_
#define TESTECHORequest_H_

#include <iostream>
using  std::istream;
using  std::ostream;

#include "ISO-8583/MSG/ISO-8583-MSG.h"

#include "ISO-8583/DTT/Bitmaps.h"
#include "ISO-8583/MSG/Message.h"
#include "ISO-8583/MSG/Request.h"

using ISO_8583::MSG::Message;
using ISO_8583::MSG::Origin;
using ISO_8583::MSG::Version;
using ISO_8583::MSG::Class;
using ISO_8583::MSG::Function;

namespace ISO_8583 {
	namespace MSG {

		class MSG_API_SCOPE TestEchoRequest : public Message, public Request  {
		private:
			static const Bitmaps	mandatoryBits;
			static const Bitmaps	optionalBits;

		public:
			TestEchoRequest() {
			}
			TestEchoRequest(Origin origin) :
				Message(Class::Network, Function::Request, origin){
			}
			virtual ~TestEchoRequest() {
			}
			virtual const Bitmaps& mandatory() const;
			virtual const Bitmaps& optional() const;

			virtual BinaryInputStream& decode(BinaryInputStream& is);
			virtual BinaryOutputStream& encode(BinaryOutputStream& os) const;

			friend MSG_API_SCOPE BinaryInputStream& operator>>(BinaryInputStream& is, TestEchoRequest& ar);
			friend MSG_API_SCOPE BinaryOutputStream& operator<<(BinaryOutputStream& os, const TestEchoRequest& ar);

			virtual RequestResponse* indication(InputStream& is, OutputStream& os);
			virtual bool exception(const Poco::Exception& exception) { return false; }
			virtual bool exception(const std::exception& exception) { return false; }
			virtual bool exception() { return false; }
			virtual void dump(ostream& os);

		};

	}
}

#endif
