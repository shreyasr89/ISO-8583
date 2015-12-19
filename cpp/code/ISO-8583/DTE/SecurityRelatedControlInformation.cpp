/*
 * SecurityRelatedControlInformation.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/SecurityRelatedControlInformation.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(SecurityRelatedControlInformation)
			string SecurityRelatedControlInformation::toString() const {
			string s(str());

			return s;
		}
	}
}