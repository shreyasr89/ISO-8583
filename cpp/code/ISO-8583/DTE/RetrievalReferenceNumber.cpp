/*
 * RetrievalReferenceNumber.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/RetrievalReferenceNumber.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(RetrievalReferenceNumber)
			string RetrievalReferenceNumber::toString() const {
			string s(str());

			return s;
		}
	}
}