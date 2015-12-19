/*
 * Exception.h
 *
 *  Created on: 11 août 2015
 *      Author: FrancisANDRE
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <stdexcept>

namespace Poco {
	class Exception;
}

#include "ISO-8583/MSG/ISO-8583-MSG.h"

namespace ISO_8583 {
	namespace MSG {

		class MSG_API_SCOPE Exception {
		public:
			Exception() {
			}
			virtual ~Exception() {
			}
			virtual bool exception(const Poco::Exception& exception) = 0;
			virtual bool exception(const std::exception& exception) = 0;
			virtual bool exception() = 0;
		};
	}
}

#endif
