/*
 * AcquirerReferenceNumber.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/AcquirerReferenceNumber.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(AcquirerReferenceNumber)
			string AcquirerReferenceNumber::toString() const {
			string s(str());

			return s;
		}
	}
}
