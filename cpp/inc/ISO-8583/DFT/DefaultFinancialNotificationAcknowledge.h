/*
 * DefaultFinancialNotificationAcknowledge.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTFINANCIALNOTIFICATIONACKNOWLEDGE_H_
#define DEFAULTFINANCIALNOTIFICATIONACKNOWLEDGE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/FinancialNotificationAcknowledge.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_RESPONSE(CB2A, Financial, Notification, Acknowledge)
	}
}

#endif
