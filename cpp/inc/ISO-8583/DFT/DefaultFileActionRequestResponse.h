/*
 * DefaultFileActionRequestResponse.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTFILEACTIONREQUESTRESPONSE_H_
#define DEFAULTFILEACTIONREQUESTRESPONSE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/FileActionRequestResponse.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_RESPONSE(CB2A, FileAction, Request, Response)
	}
}

#endif
