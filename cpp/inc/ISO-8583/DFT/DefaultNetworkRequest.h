/*
 * DefaultNetworkRequest.h
 *
 *  Created on: 3 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTNETWORKREQUEST_H_
#define DEFAULTNETWORKREQUEST_H_


#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/NetworkRequest.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_QUESTION(CB2A, Network, Request, Response)
	}
}

#endif
