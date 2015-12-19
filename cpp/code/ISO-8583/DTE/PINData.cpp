/*
 * PINData.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/PINData.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(PINData)
			string PINData::toString() const {
			string s(str());

			return s;
		}
	}
}