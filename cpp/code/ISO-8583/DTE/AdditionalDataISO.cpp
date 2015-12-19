/*
 * AdditionalDataISO.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/AdditionalDataISO.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(AdditionalDataISO)
			string AdditionalDataISO::toString() const {
			string s(str());
			return s;
		}
	}
}
