/*
 * DefaultReconciliationNotificationAcknowledge.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTRECONCILIATIONNOTIFICATIONACKNOWLEDGE_H_
#define DEFAULTRECONCILIATIONNOTIFICATIONACKNOWLEDGE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/ReconciliationNotificationAcknowledge.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_RESPONSE(CB2A, Reconciliation, Notification, Acknowledge)
	}
}

#endif
