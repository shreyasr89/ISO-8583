/*
 * DefaultFileActionNotificationAcknowledge.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTFILEACTIONNOTIFICATIONACKNOWLEDGE_H_
#define DEFAULTFILEACTIONNOTIFICATIONACKNOWLEDGE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/FileActionNotificationAcknowledge.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_RESPONSE(CB2A, FileAction, Notification, Acknowledge)
	}
}

#endif
