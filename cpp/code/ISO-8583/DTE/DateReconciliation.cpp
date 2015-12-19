/*
 * DateReconciliation.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/DateReconciliation.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(DateReconciliation)
			string DateReconciliation::toString() const {
			string s(str());

			return s;
		}
	}
}
