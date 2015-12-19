/*
 * DefaultAuthorizationAdviceResponse.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTAUTHORIZATIONADVICERESPONSE_H_
#define DEFAULTAUTHORIZATIONADVICERESPONSE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/AuthorizationAdviceResponse.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_RESPONSE(CB2A, Authorization, Advice, Response)
	}
}

#endif
