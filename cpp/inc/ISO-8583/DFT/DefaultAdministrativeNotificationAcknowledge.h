/*
 * DefaultAdministrativeNotificationAcknowledge.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTADMINISTRATIVENOTIFICATIONACKNOWLEDGE_H_
#define DEFAULTADMINISTRATIVENOTIFICATIONACKNOWLEDGE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/AdministrativeNotificationAcknowledge.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_RESPONSE(CB2A, Administrative, Notification, Acknowledge)
	}
}

#endif
