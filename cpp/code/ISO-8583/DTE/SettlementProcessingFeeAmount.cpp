/*
 * SettlementProcessingFeeAmount.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/SettlementProcessingFeeAmount.h"

namespace ISO_8583 {
namespace DTE {
		SERIALIZE(SettlementProcessingFeeAmount)
		string SettlementProcessingFeeAmount::toString() const {
			string s(str());
			return s;
		}
}
}
