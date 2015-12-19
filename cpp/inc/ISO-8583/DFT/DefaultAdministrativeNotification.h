/*
 * DefaultAdministrativeNotification.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTADMINISTRATIVENOTIFICATION_H_
#define DEFAULTADMINISTRATIVENOTIFICATION_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/AdministrativeNotification.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_QUESTION(CB2A, Administrative, Notification, Acknowledge)
	}
}

#endif
