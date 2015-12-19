/*
 * DefaultReconciliationInstructionAcknowledge.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTRECONCILIATIONINSTRUCTIONACKNOWLEDGE_H_
#define DEFAULTRECONCILIATIONINSTRUCTIONACKNOWLEDGE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/ReconciliationInstructionAcknowledge.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_RESPONSE(CB2A, Reconciliation, Instruction, Acknowledge)
	}
}

#endif
