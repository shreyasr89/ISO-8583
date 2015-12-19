/*
 * ReversalRequest.cpp
 *
 *  Created on: 7 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/MSG/ReversalRequest.h"
#include "ISO-8583/DTE/Bitmap.h"
using namespace ISO_8583::DTE;

namespace ISO_8583 {
	namespace MSG {
		const Bitmaps		ReversalRequest::mandatoryBits(0);

		const Bitmaps		ReversalRequest::optionalBits(0);

		const Bitmaps& ReversalRequest::mandatory() const {
			return mandatoryBits;
		}
		const Bitmaps& ReversalRequest::optional() const {
			return optionalBits;
		}
		BinaryInputStream& ReversalRequest::decode(BinaryInputStream& is) {
			is >> *this;
			return is;
		}
		BinaryOutputStream& ReversalRequest::encode(BinaryOutputStream& os) const {
			os << *this;
			return os;
		}
		MSG_API_SCOPE BinaryInputStream& operator>>(BinaryInputStream& is, ReversalRequest& rr) {
			is >> static_cast<Message&>(rr);
			return is;
		}
		MSG_API_SCOPE BinaryOutputStream& operator<<(BinaryOutputStream& os, const ReversalRequest& rr) {
			os << static_cast<const Message&>(rr);
			return os;
		}
		void ReversalRequest::dump(ostream& os) {
		}
	}
}
