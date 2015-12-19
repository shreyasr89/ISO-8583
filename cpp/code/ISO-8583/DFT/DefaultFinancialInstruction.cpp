/*
 * DefaultFinancialInstruction.cpp
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DFT/DefaultFinancialInstruction.h"

namespace ISO_8583 {
	namespace MSG {
		InstructionAcknowledge* DefaultFinancialInstruction::indication(BinaryInputStream& is, BinaryOutputStream& os) {
			return NULL;
		}
	}
}
