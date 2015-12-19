/*
 * DateEffective.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/DateEffective.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(DateEffective)
			string DateEffective::toString() const {
			string s(str());

			return s;
		}
	}
}
