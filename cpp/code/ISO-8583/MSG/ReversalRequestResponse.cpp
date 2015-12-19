/*
 * ReversalRequestResponse.cpp
 *
 *  Created on: 7 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTT/Bitmaps.h"
#include "ISO-8583/MSG/ReversalRequestResponse.h"
using namespace ISO_8583::DTE;

namespace ISO_8583 {
	namespace MSG {
		const Bitmaps		ReversalRequestResponse::mandatoryBits(0);

		const Bitmaps		ReversalRequestResponse::optionalBits(0);

		const Bitmaps& ReversalRequestResponse::mandatory() const {
			return mandatoryBits;
		}
		const Bitmaps& ReversalRequestResponse::optional() const {
			return optionalBits;
		}
		BinaryInputStream& ReversalRequestResponse::decode(BinaryInputStream& is) {
			is >> *this;
			return is;
		}
		BinaryOutputStream& ReversalRequestResponse::encode(BinaryOutputStream& os) const {
			os << *this;
			return os;
		}
		MSG_API_SCOPE BinaryInputStream& operator>>(BinaryInputStream& is, ReversalRequestResponse& rrr) {
			is >> static_cast<Message&>(rrr);
			return is;
		}
		MSG_API_SCOPE BinaryOutputStream& operator<<(BinaryOutputStream& os, const ReversalRequestResponse& rrr) {
			os << static_cast<const Message&>(rrr);
			return os;
		}
		void ReversalRequestResponse::dump(ostream& os) {
		}
	}
}
