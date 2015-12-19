/*
 * ServiceCode.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/ServiceCode.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(ServiceCode)
			string ServiceCode::toString() const {
			string s(str());

			return s;
		}
	}
}
