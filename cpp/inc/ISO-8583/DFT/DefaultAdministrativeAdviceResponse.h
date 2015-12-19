/*
 * DefaultAdministrativeAdviceResponse.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTADMINISTRATIVEADVICERESPONSE_H_
#define DEFAULTADMINISTRATIVEADVICERESPONSE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/AdministrativeAdviceResponse.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_RESPONSE(CB2A, Administrative, Advice, Response)
	}
}

#endif
