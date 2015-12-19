/*
 * PointOfServiceConditionCode.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/PointOfServiceConditionCode.h"

namespace ISO_8583 {
namespace DTE {
		SERIALIZE(PointOfServiceConditionCode)
		string PointOfServiceConditionCode::toString() const {
			string s(str());
			return s;
		}
}
}
