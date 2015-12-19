/*
 * Year.h
 *
 *  Created on: 5 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef YEAR_H_
#define YEAR_H_

#include "ISO-8583/DTT/ISO-8583-DTT.h"
#include "ISO-8583/DTT/Numeric.h"

namespace ISO_8583 {
	namespace DTT {
		class InputStream;
		class OutputStream;

		class DTT_API_SCOPE Year : public Numeric < 2 > {
		private:
			typedef  Numeric < 2 > BaseType;

		public:
			Year();
			~Year();
			Year& operator=(const string& year);
			Year& operator=(const char* year);
			Year& operator=(nat8 year);
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, Year& year);
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Year& year);
		};

	}
}

#endif
