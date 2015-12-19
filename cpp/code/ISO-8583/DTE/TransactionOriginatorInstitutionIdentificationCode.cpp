/*
 * TransactionOriginatorInstitutionIdentificationCode.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "TISO-8583/DTE/ransactionOriginatorInstitutionIdentificationCode.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(TransactionOriginatorInstitutionIdentificationCode)
			string TransactionOriginatorInstitutionIdentificationCode::toString() const {
			string s(str());
			return s;
		}
	}
}
