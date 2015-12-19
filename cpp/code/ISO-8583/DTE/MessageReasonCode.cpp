/*
 * MessageReasonCode.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/MessageReasonCode.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(MessageReasonCode)
			string MessageReasonCode::toString() const {
			string s(str());

			return s;
		}
	}
}
