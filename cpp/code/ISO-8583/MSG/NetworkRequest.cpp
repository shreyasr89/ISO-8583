/*
 * NetworkRequest.cpp
 *
 *  Created on: 28 juin 2015
 *      Author: FrancisANDRE
 */
#include <memory>
#include <stdexcept>
using  namespace std;

#include "ISO-8583/DTE/Bitmap.h"
#include "ISO-8583/MSG/NetworkRequest.h"
#include "ISO-8583/MSG/NetworkRequestResponse.h"
using namespace ISO_8583::DTE;

namespace ISO_8583 {
	namespace MSG {
		MESSAGE_CLASS_BODY(Network, Request)
	}
}
