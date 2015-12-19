/*
 * DefaultReversalRequestResponse.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTREVERSALREQUESTRESPONSE_H_
#define DEFAULTREVERSALREQUESTRESPONSE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/ReversalRequestResponse.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_RESPONSE(CB2A, Reversal, Request, Response)
	}
}

#endif
