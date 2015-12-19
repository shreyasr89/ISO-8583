/*
 * Minute.h
 *
 *  Created on: 5 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef MINUTE_H_
#define MINUTE_H_


#include "ISO-8583/DTT/ISO-8583-DTT.h"
#include "ISO-8583/DTT/Numeric.h"

namespace ISO_8583 {
	namespace DTT {

		class DTT_API_SCOPE Minute : public Numeric < 2 > {
		private:
			typedef  Numeric < 2 > BaseType;

		public:
			Minute();
			~Minute();
			Minute& operator=(const string& minute);
			Minute& operator=(const char* minute);
			Minute& operator=(nat8 minute);
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, Minute& minute);
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Minute& minute);
		};
	}
}

#endif
