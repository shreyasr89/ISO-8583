/*
 * POSDataCode.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/POSDataCode.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(POSDataCode)
			string POSDataCode::toString() const {
			string s(str());

			return s;
		}
	}
}
