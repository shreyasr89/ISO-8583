/*
 * ReconciliationAdviceResponse.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef ReconciliationAdviceRESPONSE_H_
#define ReconciliationAdviceRESPONSE_H_

#include <iostream>
using  std::istream;
using  std::ostream;

#include "ISO-8583/MSG/ISO-8583-MSG.h"

#include "ISO-8583/DTT/Bitmaps.h"
#include "ISO-8583/MSG/Message.h"
#include "ISO-8583/MSG/AdviceResponse.h"

using ISO_8583::MSG::Message;
using ISO_8583::MSG::Origin;
using ISO_8583::MSG::Version;
using ISO_8583::MSG::Class;
using ISO_8583::MSG::Function;

namespace ISO_8583 {
	namespace MSG {
		MESSAGE_CLASS_DEFINITION(Reconciliation, AdviceResponse)
	}
}

#endif
