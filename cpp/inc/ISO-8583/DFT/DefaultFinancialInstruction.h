/*
 * DefaultFinancialInstruction.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTFINANCIALINSTRUCTION_H_
#define DEFAULTFINANCIALINSTRUCTION_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/FinancialInstruction.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_QUESTION(CB2A, Financial, Instruction, Acknowledge)
	}
}

#endif
