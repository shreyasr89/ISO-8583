/*
 * DefaultReversalAdvice.cpp
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DFT/DefaultReversalAdvice.h"

namespace ISO_8583 {
	namespace MSG {
		AdviceResponse* DefaultReversalAdvice::indication(BinaryInputStream& is, BinaryOutputStream& os) {
			return NULL;
		}
	}
}
