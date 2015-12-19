/*
 * TransactionDestinationInstitutionIdentificationCode.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/TransactionDestinationInstitutionIdentificationCode.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(TransactionDestinationInstitutionIdentificationCode)
			string TransactionDestinationInstitutionIdentificationCode::toString() const {
			string s(str());
			return s;
		}
	}
}
