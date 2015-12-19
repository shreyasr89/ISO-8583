/*
 * DefaultReversalRequest.h
 *
 *  Created on: 3 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTREVERSALREQUEST_H_
#define DEFAULTREVERSALREQUEST_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/ReversalRequest.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_QUESTION(CB2A, Reversal, Request, Response)
	}
}

#endif
