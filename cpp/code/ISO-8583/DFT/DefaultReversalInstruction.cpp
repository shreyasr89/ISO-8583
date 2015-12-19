/*
 * DefaultReversalInstruction.cpp
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DFT/DefaultReversalInstruction.h"

namespace ISO_8583 {
	namespace MSG {
		InstructionAcknowledge* DefaultReversalInstruction::indication(BinaryInputStream& is, BinaryOutputStream& os) {
			return NULL;
		}
	}
}
