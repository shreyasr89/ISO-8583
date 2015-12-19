/*
 * ConversionDate.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/ConversionDate.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(ConversionDate)
			string ConversionDate::toString() const {
			string s(str());

			return s;
		}
	}
}