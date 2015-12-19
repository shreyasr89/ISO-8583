/*
 * DefaultNetworkNotification.h
 *
 *  Created on: 5 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTNETWORKNOTIFICATION_H_
#define DEFAULTNETWORKNOTIFICATION_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/NetworkNotification.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_QUESTION(CB2A, Network, Notification, Acknowledge)
	}
}

#endif
