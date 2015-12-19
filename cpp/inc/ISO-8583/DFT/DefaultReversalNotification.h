/*
 * DefaultReversalNotification.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTREVERSALNOTIFICATION_H_
#define DEFAULTREVERSALNOTIFICATION_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/ReversalNotification.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_QUESTION(CB2A, Reversal, Notification, Acknowledge)
	}
}

#endif
