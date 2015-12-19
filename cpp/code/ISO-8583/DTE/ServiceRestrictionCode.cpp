/*
 * ServiceRestrictionCode.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/ServiceRestrictionCode.h"

namespace ISO_8583 {
namespace DTE {
		SERIALIZE(ServiceRestrictionCode)
		string ServiceRestrictionCode::toString() const {
			string s(str());
			return s;
		}
}
}
