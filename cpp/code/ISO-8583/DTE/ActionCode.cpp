/*
 * ActionCode.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/ActionCode.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(ActionCode)
			string ActionCode::toString() const {
			string s(str());

			return s;
		}
	}
}
