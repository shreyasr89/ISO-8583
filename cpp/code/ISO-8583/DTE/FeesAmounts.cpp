/*
 * AmountsFees.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/AmountsFees.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(AmountsFees)
			string AmountsFees::toString() const {
			string s(str());

			return s;
		}
	}
}
