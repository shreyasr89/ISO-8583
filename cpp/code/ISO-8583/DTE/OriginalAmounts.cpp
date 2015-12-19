/*
 * AmountsOriginal.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/AmountsOriginal.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(AmountsOriginal)
			string AmountsOriginal::toString() const {
			string s(str());

			return s;
		}
	}
}
