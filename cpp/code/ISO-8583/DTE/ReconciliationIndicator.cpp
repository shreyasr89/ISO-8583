/*
 * ReconciliationIndicator.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ReconciliationIndicator.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(ReconciliationIndicator)
			string ReconciliationIndicator::toString() const {
			string s(asString());

			return s;
		}
	}
}