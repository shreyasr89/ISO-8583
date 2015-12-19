/*
 * NetworkInternationalIdentifier.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/NetworkInternationalIdentifier.h"

namespace ISO_8583 {
namespace DTE {
		SERIALIZE(NetworkInternationalIdentifier)
		string NetworkInternationalIdentifier::toString() const {
			string s(str());
			return s;
		}
}
}
