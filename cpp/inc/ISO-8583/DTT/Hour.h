/*
 * Hour.h
 *
 *  Created on: 5 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef HOUR_H_
#define HOUR_H_

#include "ISO-8583/DTT/ISO-8583-DTT.h"
#include "ISO-8583/DTT/Numeric.h"

namespace ISO_8583 {
	namespace DTT {

		class DTT_API_SCOPE Hour : public Numeric < 2 > {
		private:
			typedef  Numeric < 2 > BaseType;

		public:
			Hour();
			~Hour();
			Hour& operator=(const string& hour);
			Hour& operator=(const char* hour);
			Hour& operator=(nat8 hour);
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, Hour& hour);
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Hour& hour);
		};

	}
}

#endif
