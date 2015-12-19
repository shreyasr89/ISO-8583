/*
 * AuthorizationIdentificationResponse.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/AuthorizationIdentificationResponse.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(AuthorizationIdentificationResponse)
		string AuthorizationIdentificationResponse::toString() const {
			string s(str());
			return s;
		}
	}
}
