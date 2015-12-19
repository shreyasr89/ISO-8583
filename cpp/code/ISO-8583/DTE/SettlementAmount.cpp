/*
 * SettlementAmount.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/SettlementAmount.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(SettlementAmount)
		string SettlementAmount::toString() const {
			string s(str());
			return s;
		}
	}
}
