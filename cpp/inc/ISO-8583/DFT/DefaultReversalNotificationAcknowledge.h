/*
 * DefaultReversalNotificationAcknowledge.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTREVERSALNOTIFICATIONACKNOWLEDGE_H_
#define DEFAULTREVERSALNOTIFICATIONACKNOWLEDGE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/ReversalNotificationAcknowledge.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_RESPONSE(CB2A, Reversal, Notification, Acknowledge)
	}
}

#endif
