/*
 * ICCSystemRelatedData.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/ICCSystemRelatedData.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(ICCSystemRelatedData)
			string ICCSystemRelatedData::toString() const {
			string s(str());

			return s;
		}
	}
}
