/*
 * AuthorizationIdentificationResponseLength.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/AuthorizationIdentificationResponseLength.h"

namespace ISO_8583 {
namespace DTE {
		SERIALIZE(AuthorizationIdentificationResponseLength)
		string AuthorizationIdentificationResponseLength::toString() const {
			string s(str());
			return s;
		}
}
}
