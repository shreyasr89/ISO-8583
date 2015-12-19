/*
 * MACField.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/MACField.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(MACField)
			string MACField::toString() const {
			string s(str());

			return s;
		}
	}
}