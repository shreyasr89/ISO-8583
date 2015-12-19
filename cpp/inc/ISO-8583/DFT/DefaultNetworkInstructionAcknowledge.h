/*
 * DefaultNetworkInstructionAcknowledge.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTNETWORKINSTRUCTIONACKNOWLEDGE_H_
#define DEFAULTNETWORKINSTRUCTIONACKNOWLEDGE_H_

#include "ISO-8583/MSG/NetworkInstructionAcknowledge.h"

namespace ISO_8583 {
	namespace MSG {

		class DefaultNetworkInstructionAcknowledge : public NetworkInstructionAcknowledge {
		public:
			DefaultNetworkInstructionAcknowledge() {
			}
			virtual ~DefaultNetworkInstructionAcknowledge() {
			}
			virtual void confirmation(BinaryInputStream& is, BinaryOutputStream& os);
			virtual bool exception(const Poco::Exception& exception) { return false; };
			virtual bool exception(const std::exception& exception) { return false; };
			virtual bool exception() { return false; };
		};
	}
}

#endif
