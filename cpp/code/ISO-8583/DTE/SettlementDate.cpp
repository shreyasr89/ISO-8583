/*
 * SettlementDate.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/SettlementDate.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(SettlementDate)
			string SettlementDate::toString() const {
			string s(str());

			return s;
		}
	}
}