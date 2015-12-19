/*
 * Advice.h
 *
 *  Created on: 5 août 2015
 *      Author: FrancisANDRE
 */

#ifndef Advice_H_
#define Advice_H_

#include "ISO-8583/MSG/ISO-8583-MSG.h" 
#include "ISO-8583/MSG/Exception.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"
using ISO_8583::DTT::InputStream;
using ISO_8583::DTT::OutputStream;

namespace ISO_8583 {
	namespace MSG {
		class AdviceResponse;

		class MSG_API_SCOPE Advice : public virtual Exception {
		public:
			Advice() {
			}
			virtual ~Advice() {
			}
			virtual AdviceResponse* indication(InputStream& is, OutputStream& os) = 0;
			virtual void dump(ostream& os) = 0;
		};
	}
}

#endif
