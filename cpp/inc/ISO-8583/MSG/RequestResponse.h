/*
 * RequestResponse.h
 *
 *  Created on: 29 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef RequestRESPONSE_H_
#define RequestRESPONSE_H_

#include "ISO-8583/MSG/ISO-8583-MSG.h"
#include "ISO-8583/MSG/Exception.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

using ISO_8583::DTT::InputStream;
using ISO_8583::DTT::OutputStream;

namespace ISO_8583 {
	namespace MSG {
		class MSG_API_SCOPE RequestResponse : public virtual Exception  {
		public:
			virtual ~RequestResponse() {}
			virtual void confirmation(InputStream& is, OutputStream& os) = 0;
		};
	}
}

#endif
