/*
 * AmountReconciliation.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/AmountReconciliation.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(AmountReconciliation)
			string AmountReconciliation::toString() const {
			string s(asString());

			return s;
		}
	}
}
