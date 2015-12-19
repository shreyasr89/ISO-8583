/*
 * SystemsTraceAuditNumber.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/SystemsTraceAuditNumber.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(SystemsTraceAuditNumber)
			string SystemsTraceAuditNumber::toString() const {
			string s(str());

			return s;
		}
	}
}