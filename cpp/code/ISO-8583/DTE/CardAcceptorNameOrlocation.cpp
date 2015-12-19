/*
 * CardAcceptorNameOrlocation.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/CardAcceptorNameOrlocation.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(CardAcceptorNameOrlocation)
			string CardAcceptorNameOrlocation::toString() const {
			string s(str());

			return s;
		}
	}
}