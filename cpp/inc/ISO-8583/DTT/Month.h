/*
 * Month.h
 *
 *  Created on: 5 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef MONTH_H_
#define MONTH_H_

#include "ISO-8583/DTT/ISO-8583-DTT.h"
#include "ISO-8583/DTT/Numeric.h"

namespace ISO_8583 {
	namespace DTT {

		class DTT_API_SCOPE Month : public Numeric < 2 > {
		private:
			typedef  Numeric < 2 > BaseType;

		public:
			Month();
			~Month();
			Month& operator=(const string& month);
			Month& operator=(const char* month);
			Month& operator=(nat8 month);
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, Month& month);
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Month& month);
		};
	}
}
#endif
