/*
 * MessageErroIndicator.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/MessageErroIndicator.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(MessageErroIndicator)
			string MessageErroIndicator::toString() const {
			string s(str());

			return s;
		}
	}
}
