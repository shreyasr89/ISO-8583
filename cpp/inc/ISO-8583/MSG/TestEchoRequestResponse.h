/*
 * TestEchoRequestResponse.h
 *
 *  Created on: 17 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef TESTECHORequestRESPONSE_H_
#define TESTECHORequestRESPONSE_H_

#include <iostream>
using  std::istream;
using  std::ostream;

#if STD_CB2A == 150
#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 2003
#endif
#include "ISO-8583/MSG/ISO-8583-MSG.h"

#include "ISO-8583/DTT/Bitmaps.h"
#include "ISO-8583/MSG/Message.h"
#include "ISO-8583/MSG/RequestResponse.h"

using ISO_8583::MSG::Message;
using ISO_8583::MSG::Origin;
using ISO_8583::MSG::Version;
using ISO_8583::MSG::Class;
using ISO_8583::MSG::Function;

namespace ISO_8583 {
	namespace MSG {

		class MSG_API_SCOPE TestEchoRequestResponse : public Message , public RequestResponse  {
		private:
			static const Bitmaps	mandatoryBits;
			static const Bitmaps	optionalBits;

		public:
			TestEchoRequestResponse(Origin origin) :
				Message(Class::Network, Function::Request, origin){
			}
			virtual ~TestEchoRequestResponse() {
			}
			virtual const Bitmaps& mandatory() const;
			virtual const Bitmaps& optional() const;

			virtual BinaryInputStream& decode(BinaryInputStream& is);
			virtual BinaryOutputStream& encode(BinaryOutputStream& os) const;

			friend MSG_API_SCOPE BinaryInputStream& operator>>(BinaryInputStream& is, TestEchoRequestResponse& ar);
			friend MSG_API_SCOPE BinaryOutputStream& operator<<(BinaryOutputStream& os, const TestEchoRequestResponse& ar);

			virtual void indication(InputStream& is, OutputStream& os);

			virtual void dump(ostream& os);

		};

	}
}

#endif
