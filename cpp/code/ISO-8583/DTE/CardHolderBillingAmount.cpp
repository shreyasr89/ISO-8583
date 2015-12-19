/*
 * CardHolderBillingAmount.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/CardHolderBillingAmount.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(CardHolderBillingAmount)
			string CardHolderBillingAmount::toString() const {
			string s(str());
			return s;
		}
	}
}