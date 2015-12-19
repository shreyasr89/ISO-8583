/*
 * Century.h
 *
 *  Created on: 5 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef CENTURY_H_
#define CENTURY_H_

#include "ISO-8583/DTT/ISO-8583-DTT.h"
#include "ISO-8583/DTT/Numeric.h"

namespace ISO_8583 {
	namespace DTT {

		class DTT_API_SCOPE Century : public Numeric < 2 > {
		private:
			typedef  Numeric < 2 > BaseType;

		public:
			Century();
			~Century();
			Century& operator=(const string& century);
			Century& operator=(const char* century);
			Century& operator=(nat8 century);
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, Century& century);
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Century& century);
		};
	}
}

#endif
