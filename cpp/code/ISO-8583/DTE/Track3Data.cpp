/*
 * Track3Data.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/Track3Data.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(Track3Data)
			string Track3Data::toString() const {
			string s(str());

			return s;
		}
	}
}