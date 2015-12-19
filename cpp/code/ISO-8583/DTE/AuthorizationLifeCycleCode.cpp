/*
 * AuthorizationLifeCycleCode.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/AuthorizationLifeCycleCode.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(AuthorizationLifeCycleCode)
			string AuthorizationLifeCycleCode::toString() const {
			string s(str());

			return s;
		}
	}
}
