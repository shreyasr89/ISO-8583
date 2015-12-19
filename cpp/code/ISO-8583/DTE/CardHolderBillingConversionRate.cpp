/*
 * CardHolderBillingConversionRate.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/CardHolderBillingConversionRate.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(CardHolderBillingConversionRate)
			string CardHolderBillingConversionRate::toString() const {
			string s(str());

			return s;
		}
	}
}