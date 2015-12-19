/*
 * DefaultAuthorizationInstructionAcknowledge.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTAUTHORIZATIONINSTRUCTIONACKNOWLEDGE_H_
#define DEFAULTAUTHORIZATIONINSTRUCTIONACKNOWLEDGE_H_

#include "ISO-8583/MSG/AuthorizationInstructionAcknowledge.h"

namespace ISO_8583 {
	namespace MSG {

		class DefaultAuthorizationInstructionAcknowledge : public AuthorizationInstructionAcknowledge {
		public:
			DefaultAuthorizationInstructionAcknowledge() {
			}
			virtual ~DefaultAuthorizationInstructionAcknowledge() {
			}
			virtual void confirmation(BinaryInputStream& is, BinaryOutputStream& os);
			virtual bool exception(const Poco::Exception& exception) { return false; };
			virtual bool exception(const std::exception& exception) { return false; };
			virtual bool exception() { return false; };
		};
	}
}

#endif
