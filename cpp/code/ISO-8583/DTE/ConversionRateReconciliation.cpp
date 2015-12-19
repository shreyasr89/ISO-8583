/*
 * ConversionRateReconciliation.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/ConversionRateReconciliation.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(ConversionRateReconciliation)
			string ConversionRateReconciliation::toString() const {
			string s(str());

			return s;
		}
	}
}
