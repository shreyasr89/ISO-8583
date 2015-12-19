/*
 * MerchantType.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/MerchantType.h"

namespace ISO_8583 {
namespace DTE {
		SERIALIZE(MerchantType)
		string MerchantType::toString() const {
			string s(str());
			return s;
		}
}
}
