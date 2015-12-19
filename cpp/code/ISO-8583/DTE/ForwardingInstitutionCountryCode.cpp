/*
 * ForwardingInstitutionCountryCode.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/ForwardingInstitutionCountryCode.h"

namespace ISO_8583 {
namespace DTE {
		SERIALIZE(ForwardingInstitutionCountryCode)
		string ForwardingInstitutionCountryCode::toString() const {
			string s(str());
			return s;
		}
}
}
