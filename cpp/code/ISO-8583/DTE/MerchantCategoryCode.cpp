/*
 * MerchantCategoryCode.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/MerchantCategoryCode.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(MerchantCategoryCode)
			string MerchantCategoryCode::toString() const {
			string s(str());

			return s;
		}
	}
}
