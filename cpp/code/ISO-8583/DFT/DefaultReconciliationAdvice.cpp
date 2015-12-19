/*
 * DefaultReconciliationAdvice.cpp
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DFT/DefaultReconciliationAdvice.h"

namespace ISO_8583 {
	namespace MSG {
		AdviceResponse* DefaultReconciliationAdvice::indication(BinaryInputStream& is, BinaryOutputStream& os) {
			return NULL;
		}
	}
}
