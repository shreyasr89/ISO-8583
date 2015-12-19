/*
 * DefaultAdministrativeAdvice.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTADMINISTRATIVEADVICE_H_
#define DEFAULTADMINISTRATIVEADVICE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/AdministrativeAdvice.h"

namespace ISO_8583 {
	namespace MSG {
#if	  defined(VRM_CB2A)
		CLASS_DEFINITION_QUESTION(CB2A, Administrative, Advice, Response)
#elif defined(VRM_ISO_8583)
		CLASS_DEFINITION_QUESTION(Default, Administrative, Advice, Response)
#endif

	}
}

#endif
