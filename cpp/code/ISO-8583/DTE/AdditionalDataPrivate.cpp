/*
 * AdditionalDataPrivate.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/AdditionalDataPrivate.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(AdditionalDataPrivate)
			string AdditionalDataPrivate::toString() const {
			string s(str());

			return s;
		}
	}
}