/*
 * AcquiringInstitutionIdentificationCode.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/AcquiringInstitutionIdentificationCode.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(AcquiringInstitutionIdentificationCode)
			string AcquiringInstitutionIdentificationCode::toString() const {
			string s(str());
			return s;
		}
	}
}