/*
 * ApprovalCode.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/ApprovalCode.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(ApprovalCode)
			string ApprovalCode::toString() const {
			string s(str());

			return s;
		}
	}
}
