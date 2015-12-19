/*
 * DefaultAdministrativeRequestResponse.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTADMINISTRATIVEREQUESTRESPONSE_H_
#define DEFAULTADMINISTRATIVEREQUESTRESPONSE_H_

#include "ISO-8583/MSG/AdministrativeRequestResponse.h"

namespace ISO_8583 {
	namespace MSG {

		class DefaultAdministrativeRequestResponse : public AdministrativeRequestResponse{
		public:
			DefaultAdministrativeRequestResponse() {
			}
			virtual ~DefaultAdministrativeRequestResponse() {
			}
			virtual void confirmation(BinaryInputStream& is, BinaryOutputStream& os);
			virtual bool exception(const Poco::Exception& exception) { return false; };
			virtual bool exception(const std::exception& exception) { return false; };
			virtual bool exception() { return false; };
		};
	}
}

#endif
