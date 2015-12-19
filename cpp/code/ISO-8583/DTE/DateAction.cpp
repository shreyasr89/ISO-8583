/*
 * DateAction.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/DateAction.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(DateAction)
			string DateAction::toString() const {
			string s(str());
			return s;
		}

	}
}
