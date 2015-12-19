/*
 * DefaultNetworkInstruction.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTNETWORKINSTRUCTION_H_
#define DEFAULTNETWORKINSTRUCTION_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/NetworkInstruction.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_QUESTION(CB2A, Network, Instruction, Acknowledge)
	}
}

#endif
