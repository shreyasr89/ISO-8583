/*
 * AdditionalResponseData.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/AdditionalResponseData.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(AdditionalResponseData)
			string AdditionalResponseData::toString() const {
			string s(str());

			return s;
		}
	}
}