/*
 * DefaultFileActionRequest.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTFILEACTIONREQUEST_H_
#define DEFAULTFILEACTIONREQUEST_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/FileActionRequest.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_QUESTION(CB2A, FileAction, Request, Response)
	}
}

#endif
