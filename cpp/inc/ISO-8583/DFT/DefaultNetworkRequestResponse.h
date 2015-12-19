/*
 * DefaultNetworkRequestResponse.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTNETWORKREQUESTRESPONSE_H_
#define DEFAULTNETWORKREQUESTRESPONSE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/NetworkRequestResponse.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_RESPONSE(CB2A, Network, Request, Response)
	}
}

#endif
