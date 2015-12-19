/*
 * DefaultFinancialNotification.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTFINANCIALNOTIFICATION_H_
#define DEFAULTFINANCIALNOTIFICATION_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/FinancialNotification.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_QUESTION(CB2A, Financial, Notification, Acknowledge)
	}
}

#endif
