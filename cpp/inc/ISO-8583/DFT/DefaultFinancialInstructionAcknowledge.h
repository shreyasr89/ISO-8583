/*
 * DefaultFinancialInstructionAcknowledge.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTFINANCIALINSTRUCTIONACKNOWLEDGE_H_
#define DEFAULTFINANCIALINSTRUCTIONACKNOWLEDGE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/FinancialInstructionAcknowledge.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_RESPONSE(CB2A, Financial, Instruction, Acknowledge)
	}
}

#endif
