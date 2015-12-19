/*
 * TestEchoRequest.cpp
 *
 *  Created on: 17 juil. 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/MSG/TestEchoRequest.h"

namespace ISO_8583 {
namespace MSG {
		const Bitmaps		TestEchoRequest::mandatoryBits(0);
		const Bitmaps		TestEchoRequest::optionalBits(0);

		const Bitmaps& TestEchoRequest::mandatory() const {
			return mandatoryBits;
		}
		const Bitmaps& TestEchoRequest::optional() const {
			return optionalBits;
		}
		RequestResponse* TestEchoRequest::indication(InputStream& is, OutputStream& os) {
			return NULL;// new TestEchoRequestResponse;
		}
		BinaryInputStream& TestEchoRequest::decode(BinaryInputStream& is) {
			is >> *this;
			return is;
		}
		BinaryOutputStream& TestEchoRequest::encode(BinaryOutputStream& os) const {
			os << *this;
			return os;
		}
		MSG_API_SCOPE BinaryInputStream& operator>>(BinaryInputStream& is, TestEchoRequest& ar) {
			is >> static_cast<Message&>(ar);
			return is;
		}
		MSG_API_SCOPE BinaryOutputStream& operator<<(BinaryOutputStream& os, const TestEchoRequest& ar) {
			os << static_cast<const Message&>(ar);
			return os;
		}
		void TestEchoRequest::dump(ostream& os) {
		}
}
}
