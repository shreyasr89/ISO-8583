/*
 * VerificationData.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/VerificationData.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(VerificationData)
			string VerificationData::toString() const {
			string s(str());

			return s;
		}
	}
}
