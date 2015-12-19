/*
 * PointOfServiceEntryMode.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/PointOfServiceEntryMode.h"

namespace ISO_8583 {
namespace DTE {
		SERIALIZE(PointOfServiceEntryMode)
		string PointOfServiceEntryMode::toString() const {
			string s(str());
			return s;
		}
}
}
