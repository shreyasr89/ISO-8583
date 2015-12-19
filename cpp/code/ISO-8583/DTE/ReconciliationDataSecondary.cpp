/*
 * ReconciliationDataSecondary.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/ReconciliationDataSecondary.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(ReconciliationDataSecondary)
			string ReconciliationDataSecondary::toString() const {
			string s(str());
			return s;
		}
	}
}
