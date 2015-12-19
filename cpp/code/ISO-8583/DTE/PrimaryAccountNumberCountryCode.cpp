/*
 * PrimaryAccountNumberCountryCode.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/PrimaryAccountNumberCountryCode.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(PrimaryAccountNumberCountryCode)
			string PrimaryAccountNumberCountryCode::toString() const {
			string s(str());

			return s;
		}
	}
}