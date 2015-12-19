/*
 * Notification.h
 *
 *  Created on: 23 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef Notification_H_
#define Notification_H_

#include "ISO-8583/MSG/ISO-8583-MSG.h"
#include "ISO-8583/MSG/Exception.h"
#include "ISO-8583/DTT/BinaryInputStream.h"
#include "ISO-8583/DTT/BinaryOutputStream.h"
using ISO_8583::DTT::BinaryInputStream;
using ISO_8583::DTT::BinaryOutputStream;

namespace ISO_8583 {
	namespace MSG {
		class NotificationAcknowledge;

		class MSG_API_SCOPE Notification : public virtual Exception {
		public:
			Notification() {
			}
			virtual ~Notification() {
			}
			virtual NotificationAcknowledge* indication(InputStream& is, OutputStream& os) = 0;
			virtual void dump(ostream& os) = 0;
		};
	}
}

#endif
