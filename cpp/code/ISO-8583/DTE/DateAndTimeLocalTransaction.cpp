/*
 * DateAndTimeLocalTransaction.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/DateAndTimeLocalTransaction.h"

namespace ISO_8583 {
	namespace DTE {
		DateAndTimeLocalTransaction::DateAndTimeLocalTransaction() {

		}
		DateAndTimeLocalTransaction::~DateAndTimeLocalTransaction() {

		}
		SERIALIZE(DateAndTimeLocalTransaction)
			string DateAndTimeLocalTransaction::toString() const {
			string s(str());

			return s;
		}
	}
}
