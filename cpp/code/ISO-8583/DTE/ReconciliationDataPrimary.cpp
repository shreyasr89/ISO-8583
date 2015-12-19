/*
 * ReconciliationDataPrimary.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/ReconciliationDataPrimary.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(ReconciliationDataPrimary)
			string ReconciliationDataPrimary::toString() const {
			string s(str());
			return s;
		}
	}
}
