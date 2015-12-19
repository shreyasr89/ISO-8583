/*
 * AuthorizingAgentInstitutionIdentificationCode.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/AuthorizingAgentInstitutionIdentificationCode.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(AuthorizingAgentInstitutionIdentificationCode)
			string AuthorizingAgentInstitutionIdentificationCode::toString() const {
			string s(str());

			return s;
		}
	}
}
