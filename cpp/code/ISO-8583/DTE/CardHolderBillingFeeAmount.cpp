/*
 * CardHolderBillingFeeAmount.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/CardHolderBillingFeeAmount.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(CardHolderBillingFeeAmount)
			string CardHolderBillingFeeAmount::toString() const {
			string s(str());

			return s;
		}
	}
}