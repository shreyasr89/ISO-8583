/*
 * TestEchoRequestResponseResponse.cpp
 *
 *  Created on: 17 juil. 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/MSG/TestEchoRequestResponse.h"

namespace ISO_8583 {
namespace MSG {
		const Bitmaps		TestEchoRequestResponse::mandatoryBits(0);
		const Bitmaps		TestEchoRequestResponse::optionalBits(0);

		const Bitmaps& TestEchoRequestResponse::mandatory() const {
			return mandatoryBits;
		}
		const Bitmaps& TestEchoRequestResponse::optional() const {
			return optionalBits;
		}
		void TestEchoRequestResponse::indication(InputStream& is, OutputStream& os) {
		}
		BinaryInputStream& TestEchoRequestResponse::decode(BinaryInputStream& is) {
			is >> *this;
			return is;
		}
		BinaryOutputStream& TestEchoRequestResponse::encode(BinaryOutputStream& os) const {
			os << *this;
			return os;
		}
		MSG_API_SCOPE BinaryInputStream& operator>>(BinaryInputStream& is, TestEchoRequestResponse& ar) {
			is >> static_cast<Message&>(ar);
			return is;
		}
		MSG_API_SCOPE BinaryOutputStream& operator<<(BinaryOutputStream& os, const TestEchoRequestResponse& ar) {
			os << static_cast<const Message&>(ar);
			return os;
		}
		void TestEchoRequestResponse::dump(ostream& os) {
		}
}
}
