/*
 * AdministrativeRequestResponse.h
 *
 *  Created on: 17 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef AdministrativeRequestRESPONSE_H_
#define AdministrativeRequestRESPONSE_H_

#include <iostream>
using  std::istream;
using  std::ostream;

#include "ISO-8583/MSG/ISO-8583-MSG.h" 

#include "ISO-8583/DTT/Bitmaps.h"
#include "ISO-8583/MSG/Message.h"
#include "ISO-8583/MSG/RequestResponse.h"

using ISO_8583::MSG::Message;
using ISO_8583::MSG::Origin;
using ISO_8583::MSG::Version;
using ISO_8583::MSG::Class;
using ISO_8583::MSG::Function;

namespace ISO_8583 {
	namespace MSG {
		MESSAGE_CLASS_DEFINITION(Administrative, RequestResponse)
	}
}

#endif
