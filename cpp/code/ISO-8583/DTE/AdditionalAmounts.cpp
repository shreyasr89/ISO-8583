/*
 * AdditionalAmounts.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/AdditionalAmounts.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(AdditionalAmounts)
			string AdditionalAmounts::toString() const {
			string s(str());

			return s;
		}
	}
}