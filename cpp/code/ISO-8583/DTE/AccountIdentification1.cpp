/*
 * AccountIdentification1.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/AccountIdentification1.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(AccountIdentification1)
			string AccountIdentification1::toString() const {
			string s(str());
			return s;
		}
	}
}
