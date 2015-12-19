/*
 * DefaultReconciliationRequestResponse.h
 *
 *  Created on: 10 ao�t 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTRECONCILIATIONREQUESTRESPONSE_H_
#define DEFAULTRECONCILIATIONREQUESTRESPONSE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/ReconciliationRequestResponse.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_RESPONSE(CB2A, Reconciliation, Request, Response)
	}
}

#endif
