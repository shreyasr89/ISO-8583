/*
 * SettlementConversionRate.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/SettlementConversionRate.h"

namespace ISO_8583 {
namespace DTE {
		SERIALIZE(SettlementConversionRate)
		string SettlementConversionRate::toString() const {
			string s(str());
			return s;
		}
}
}
