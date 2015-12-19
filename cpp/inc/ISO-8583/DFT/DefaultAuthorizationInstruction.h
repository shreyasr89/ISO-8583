/*
 * DefaultAuthorizationInstruction.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTAUTHORIZATIONINSTRUCTION_H_
#define DEFAULTAUTHORIZATIONINSTRUCTION_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/AuthorizationInstruction.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_QUESTION(CB2A, Authorization, Instruction, Acknowledge)
	}
}

#endif
