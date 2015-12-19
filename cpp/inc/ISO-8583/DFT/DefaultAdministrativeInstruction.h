/*
 * DefaultAdministrativeInstruction.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTADMINISTRATIVEINSTRUCTION_H_
#define DEFAULTADMINISTRATIVEINSTRUCTION_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/AdministrativeInstruction.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_QUESTION(CB2A, Administrative, Instruction, Acknowledge)
	}
}


#endif
