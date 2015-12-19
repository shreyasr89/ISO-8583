/*
 * DefaultFileActionInstruction.cpp
 *
 *  Created on: 5 août 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DFT/DefaultFileActionInstruction.h"

namespace ISO_8583 {
namespace MSG {
		InstructionAcknowledge* DefaultFileActionInstruction::indication(BinaryInputStream& is, BinaryOutputStream& os) {
			return NULL;
		}
}
}
