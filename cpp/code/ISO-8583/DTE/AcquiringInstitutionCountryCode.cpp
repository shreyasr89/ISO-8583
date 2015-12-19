/*
 * AcquiringInstitutionCountryCode.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/AcquiringInstitutionCountryCode.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(AcquiringInstitutionCountryCode)
			string AcquiringInstitutionCountryCode::toString() const {
			string s(str());
			return s;
		}
	}
}
