/*
 * FinancialNotificationAcknowledge.h
 *
 *  Created on: 11 ao�t 2015
 *      Author: FrancisANDRE
 */

#ifndef FINANCIALNOTIFICATIONACKNOWLEDGE_H_
#define FINANCIALNOTIFICATIONACKNOWLEDGE_H_

#include <iostream>
using  std::istream;
using  std::ostream;

#include "ISO-8583/MSG/ISO-8583-MSG.h"

#include "ISO-8583/DTT/Bitmaps.h"
#include "ISO-8583/MSG/Message.h"
#include "ISO-8583/MSG/NotificationAcknowledge.h"

using ISO_8583::MSG::Message;
using ISO_8583::MSG::Origin;
using ISO_8583::MSG::Version;
using ISO_8583::MSG::Class;
using ISO_8583::MSG::Function;

namespace ISO_8583 {
	namespace MSG {
		MESSAGE_CLASS_DEFINITION(Financial, NotificationAcknowledge)
	}
}

#endif
