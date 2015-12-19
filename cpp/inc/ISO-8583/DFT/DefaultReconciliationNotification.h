/*
 * DefaultReconciliationNotification.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTRECONCILIATIONNOTIFICATION_H_
#define DEFAULTRECONCILIATIONNOTIFICATION_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/ReconciliationNotification.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_QUESTION(CB2A, Reconciliation, Notification, Acknowledge)
	}
}

#endif
