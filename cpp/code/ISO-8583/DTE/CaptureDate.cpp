/*
 * CaptureDate.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/CaptureDate.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(CaptureDate)
			string CaptureDate::toString() const {
			string s(str());

			return s;
		}
	}
}