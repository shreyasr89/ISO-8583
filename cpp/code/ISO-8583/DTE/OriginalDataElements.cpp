/*
 * OriginalDataElements.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/OriginalDataElements.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(OriginalDataElements)
			string OriginalDataElements::toString() const {
			string s(str());

			return s;
		}
	}
}