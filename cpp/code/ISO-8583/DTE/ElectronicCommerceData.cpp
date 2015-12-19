/*
 * ElectronicCommerceData.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/ElectronicCommerceData.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(ElectronicCommerceData)
			string ElectronicCommerceData::toString() const {
			string s(str());

			return s;
		}
	}
}
