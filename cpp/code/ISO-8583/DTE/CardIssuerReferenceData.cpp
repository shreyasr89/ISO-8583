/*
 * CardIssuerReferenceData.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/CardIssuerReferenceData.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(CardIssuerReferenceData)
			string CardIssuerReferenceData::toString() const {
			string s(str());
			return s;
		}
	}
}