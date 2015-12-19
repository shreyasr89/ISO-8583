/*
 * TransactionLifeCycleIdentificationData.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/TransactionLifeCycleIdentificationData.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(TransactionLifeCycleIdentificationData)
			string TransactionLifeCycleIdentificationData::toString() const {
			string s(str());
			return s;
		}
	}
}
