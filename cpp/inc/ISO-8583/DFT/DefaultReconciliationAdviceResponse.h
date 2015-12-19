/*
 * DefaultReconciliationAdviceResponse.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTRECONCILIATIONADVICERESPONSE_H_
#define DEFAULTRECONCILIATIONADVICERESPONSE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/ReconciliationAdviceResponse.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_RESPONSE(CB2A, Reconciliation, Advice, Response)
	}
}

#endif
