/*
 * FunctionCode.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/FunctionCode.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(FunctionCode)
			string FunctionCode::toString() const {
			string s(str());

			return s;
		}
	}
}
