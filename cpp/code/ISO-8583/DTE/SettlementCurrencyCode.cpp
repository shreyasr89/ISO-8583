/*
 * SettlementCurrencyCode.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/SettlementCurrencyCode.h"

namespace ISO_8583 {
namespace DTE {
		SERIALIZE(SettlementCurrencyCode)
		string SettlementCurrencyCode::toString() const {
			string s(str());
			return s;
		}
}
}
