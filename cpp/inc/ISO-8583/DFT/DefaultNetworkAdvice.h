/*
 * DefaultNetworkAdvice.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTNETWORKADVICE_H_
#define DEFAULTNETWORKADVICE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/NetworkAdvice.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_QUESTION(CB2A, Network, Advice, Response)
	}
}

#endif
