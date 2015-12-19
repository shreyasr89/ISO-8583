/*
 * Track2Data.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/Track2Data.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(Track2Data)
			string Track2Data::toString() const {
			string s(str());

			return s;
		}
	}
}