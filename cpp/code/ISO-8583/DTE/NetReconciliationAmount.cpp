/*
 * NetReconciliationAmount.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/NetReconciliationAmount.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(NetReconciliationAmount)
			string NetReconciliationAmount::toString() const {
			string s(str());
			return s;
		}
	}
}
