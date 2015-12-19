/*
 * SettlementInstitutionIdentificationCode.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/SettlementInstitutionIdentificationCode.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(SettlementInstitutionIdentificationCode)
			string SettlementInstitutionIdentificationCode::toString() const {
			string s(str());
			return s;
		}
	}
}