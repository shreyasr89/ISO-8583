/*
 * ForwardingInstitutionIdentificationCode.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/ForwardingInstitutionIdentificationCode.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(ForwardingInstitutionIdentificationCode)
			string ForwardingInstitutionIdentificationCode::toString() const {
			string s(str());

			return s;
		}
	}
}