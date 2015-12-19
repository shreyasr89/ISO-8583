/*
 * DefaultFileActionInstruction.h
 *
 *  Created on: 5 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTFILEACTIONINSTRUCTION_H_
#define DEFAULTFILEACTIONINSTRUCTION_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/FileActionInstruction.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_QUESTION(CB2A, FileAction, Instruction, Acknowledge)
	}
}

#endif
