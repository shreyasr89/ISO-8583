/*
 * DataRecord.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/DataRecord.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(DataRecord)
			string DataRecord::toString() const {
			string s(str());
			return s;
		}
	}
}
