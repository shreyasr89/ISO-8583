/*
 * FileName.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/FileName.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(FileName)
			string FileName::toString() const {
			string s(str());
			return s;
		}
	}
}