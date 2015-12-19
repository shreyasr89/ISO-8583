/*
 * DefaultAuthorizationRequestResponse.h
 *
 *  Created on: 7 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTAUTHORIZATIONREQUESTRESPONSE_H_
#define DEFAULTAUTHORIZATIONREQUESTRESPONSE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/AuthorizationRequestResponse.h"

namespace ISO_8583 {
	namespace MSG {
		class ISO_8583_DFT_API concat2(Prefix,  AuthorizationRequestResponse) : public AuthorizationRequestResponse {
		public:
			concat2(Prefix,  AuthorizationRequestResponse) () {
			}
			concat2(Prefix,  AuthorizationRequestResponse) (Origin origin) : AuthorizationRequestResponse(origin) {
			}
			virtual ~concat2(Prefix,  AuthorizationRequestResponse) () {
			}
			virtual void confirmation(InputStream& is, OutputStream& os);
			virtual bool exception(const Poco::Exception& exception) { return false; };
			virtual bool exception(const std::exception& exception) { return false; };
			virtual bool exception() { return false; };
		};
	}
}

#endif
