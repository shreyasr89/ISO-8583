/*
 * CardAcceptorIdentificationCode.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/CardAcceptorIdentificationCode.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(CardAcceptorIdentificationCode)
			string CardAcceptorIdentificationCode::toString() const {
			string s(str());

			return s;
		}
	}
}