/*
 * DefaultFileActionNotification.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTFILEACTIONNOTIFICATION_H_
#define DEFAULTFILEACTIONNOTIFICATION_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/FileActionNotification.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_QUESTION(CB2A, FileAction, Notification, Acknowledge)
	}
}

#endif
