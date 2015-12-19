/*
 * TransactionSpecificData.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/TransactionSpecificData.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(TransactionSpecificData)
			string TransactionSpecificData::toString() const {
			string s(str());
			return s;
		}
	}
}
