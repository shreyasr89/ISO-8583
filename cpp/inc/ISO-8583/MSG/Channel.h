/*
 * Channel.h
 *
 *  Created on: 23 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef CHANNEL_H_
#define CHANNEL_H_

#include "ISO-8583/MSG/ISO-8583-MSG.h"
#include "ISO-8583/DTT/Buffer.h"
using ISO_8583::DTT::Buffer;

namespace ISO_8583 {
	namespace MSG {

		class Channel {
		public:
			Channel() {}
			virtual ~Channel() {}
			virtual int send(Buffer& buffer) = 0;
			virtual int recv(Buffer& buffer) = 0;
		};
	}
}

#endif
