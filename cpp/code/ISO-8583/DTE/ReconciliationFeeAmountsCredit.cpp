/*
 * ReconciliationFeeAmountsCredit.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/ReconciliationFeeAmountsCredit.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(ReconciliationFeeAmountsCredit)
			string ReconciliationFeeAmountsCredit::toString() const {
			string s(str());
			return s;
		}
	}
}
