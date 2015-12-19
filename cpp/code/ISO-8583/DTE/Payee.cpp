/*
 * Payee.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/Payee.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(Payee)
			string Payee::toString() const {
			string s(str());
			return s;
		}
	}
}