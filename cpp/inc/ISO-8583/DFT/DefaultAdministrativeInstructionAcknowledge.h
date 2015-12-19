/*
 * DefaultAdministrativeInstructionAcknowledge.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTADMINISTRATIVEINSTRUCTIONACKNOWLEDGE_H_
#define DEFAULTADMINISTRATIVEINSTRUCTIONACKNOWLEDGE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/AdministrativeInstructionAcknowledge.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_RESPONSE(CB2A, Administrative, Instruction, Acknowledge)
	}
}

#endif
