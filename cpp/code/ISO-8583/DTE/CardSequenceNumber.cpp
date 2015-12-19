/*
 * CardSequenceNumber.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/CardSequenceNumber.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(CardSequenceNumber)
			string CardSequenceNumber::toString() const {
			string s(str());

			return s;
		}
	}
}