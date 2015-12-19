/*
 * DefaultAuthorizationRequest.h
 *
 *  Created on: 2 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTAUTHORIZATIONREQUEST_H_
#define DEFAULTAUTHORIZATIONREQUEST_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/AuthorizationRequest.h"

namespace ISO_8583 {
	namespace MSG {
		class ISO_8583_DFT_API concat2(Prefix,  AuthorizationRequest) : public AuthorizationRequest {
		public:
			concat2(Prefix,  AuthorizationRequest)() {
			}
			concat2(Prefix,  AuthorizationRequest)(Origin origin) : AuthorizationRequest(origin) {
			}
			virtual ~concat2(Prefix,  AuthorizationRequest)() {
			}
			virtual RequestResponse* indication(InputStream& is, OutputStream& os);
			virtual bool exception(const Poco::Exception& exception) { return false; };
			virtual bool exception(const std::exception& exception) { return false; };
			virtual bool exception() { return false; };
		};
	}
}

#endif
