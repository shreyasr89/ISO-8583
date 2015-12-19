/*
 * NotificationAcknowledge.h
 *
 *  Created on: 23 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef NotificationACKNOWLEDGE_H_
#define NotificationACKNOWLEDGE_H_

#include "ISO-8583/MSG/ISO-8583-MSG.h"
#include "ISO-8583/MSG/Exception.h"
#include "ISO-8583/DTT/BinaryInputStream.h"
#include "ISO-8583/DTT/BinaryOutputStream.h"
using ISO_8583::DTT::BinaryInputStream;
using ISO_8583::DTT::BinaryOutputStream;

namespace ISO_8583 {
	namespace MSG {

		class MSG_API_SCOPE NotificationAcknowledge {
		public:
			NotificationAcknowledge() {
			}
			virtual ~NotificationAcknowledge() {
			}
			virtual void confirmation(InputStream& is, OutputStream& os) = 0;
		};
	}
}

#endif

