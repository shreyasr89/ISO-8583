/*
 * DefaultNetworkAdvice.cpp
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DFT/DefaultNetworkAdvice.h"

namespace ISO_8583 {
	namespace MSG {
		AdviceResponse* DefaultNetworkAdvice::indication(BinaryInputStream& is, BinaryOutputStream& os) {
			return NULL;
		}
	}
}
