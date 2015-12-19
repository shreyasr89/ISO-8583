/*
 * DefaultReconciliationNotification.cpp
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DFT/DefaultReconciliationNotification.h"

namespace ISO_8583 {
	namespace MSG {
		NotificationAcknowledge* DefaultReconciliationNotification::indication(BinaryInputStream& is, BinaryOutputStream& os) {
			return NULL;
		}
	}
}
