/*
 * CardAcceptorTerminalIdentification.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/CardAcceptorTerminalIdentification.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(CardAcceptorTerminalIdentification)
			string CardAcceptorTerminalIdentification::toString() const {
			string s(str());

			return s;
		}
	}
}