/*
 * Request.h
 *
 *  Created on: 29 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef Request_H_
#define Request_H_
#include <iostream>
using std::ostream;

#include "ISO-8583/MSG/ISO-8583-MSG.h"
#include "ISO-8583/MSG/Exception.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"
using ISO_8583::DTT::InputStream;
using ISO_8583::DTT::OutputStream;

namespace ISO_8583 {
	namespace MSG {
		class RequestResponse;

		class MSG_API_SCOPE Request : public virtual Exception {
		public:
			virtual ~Request() {}
			virtual RequestResponse* indication(InputStream& is, OutputStream& os) = 0;
			virtual void dump(ostream& os) = 0;
		};
	}
}

#endif
