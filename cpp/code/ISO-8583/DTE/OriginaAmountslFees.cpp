/*
 * AmountsOriginalFees.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/AmountsOriginalFees.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(AmountsOriginalFees)

			string AmountsOriginalFees::toString() const {
			string s(str());
			return s;
		}
	}
}
