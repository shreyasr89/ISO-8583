/*
 * CardHolderBillingCurrencyCode.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/CardHolderBillingCurrencyCode.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(CardHolderBillingCurrencyCode)
			string CardHolderBillingCurrencyCode::toString() const {
			string s(str());
			return s;
		}
	}
}
