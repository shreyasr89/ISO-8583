/*
 * DefaultNetworkNotificationAcknowledge.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTNETWORKNOTIFICATIONACKNOWLEDGE_H_
#define DEFAULTNETWORKNOTIFICATIONACKNOWLEDGE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/NetworkNotificationAcknowledge.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_RESPONSE(CB2A, Network, Notification, Acknowledge)
	}
}

#endif
