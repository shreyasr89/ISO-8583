/*
 * ReconciliationFeeAmountsDebit.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ReconciliationFeeAmountsDebit.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(ReconciliationFeeAmountsDebit)
			string ReconciliationFeeAmountsDebit::toString() const {
			string s(asString());
			return s;
		}
	}
}