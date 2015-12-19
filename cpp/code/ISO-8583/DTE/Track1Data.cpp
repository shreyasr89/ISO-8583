/*
 * Track1Data.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/Track1Data.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(Track1Data)
			string Track1Data::toString() const {
			string s(str());

			return s;
		}
	}
}