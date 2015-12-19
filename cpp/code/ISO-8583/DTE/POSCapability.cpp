/*
 * POSCapability.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/POSCapability.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(POSCapability)
			string POSCapability::toString() const {
			string s(str());

			return s;
		}
	}
}
