/*
 * DefaultFileActionInstructionAcknowledge.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTFILEACTIONINSTRUCTIONACKNOWLEDGE_H_
#define DEFAULTFILEACTIONINSTRUCTIONACKNOWLEDGE_H_

#include "ISO-8583/MSG/FileActionInstructionAcknowledge.h"

namespace ISO_8583 {
	namespace MSG {

		class DefaultFileActionInstructionAcknowledge : public FileActionInstructionAcknowledge {
		public:
			DefaultFileActionInstructionAcknowledge() {
			}
			virtual ~DefaultFileActionInstructionAcknowledge() {
			}
			virtual void confirmation(BinaryInputStream& is, BinaryOutputStream& os);
			virtual bool exception(const Poco::Exception& exception) { return false; };
			virtual bool exception(const std::exception& exception) { return false; };
			virtual bool exception() { return false; };
		};
	}
}

#endif
