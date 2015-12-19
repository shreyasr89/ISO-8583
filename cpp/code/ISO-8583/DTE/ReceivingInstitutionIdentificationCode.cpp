/*
 * ReceivingInstitutionIdentificationCode.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/ReceivingInstitutionIdentificationCode.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(ReceivingInstitutionIdentificationCode)
			string ReceivingInstitutionIdentificationCode::toString() const {
			string s(str());
			return s;
		}
	}
}