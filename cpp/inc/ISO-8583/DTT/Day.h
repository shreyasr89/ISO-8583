/*
 * Day.h
 *
 *  Created on: 5 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef DAY_H_
#define DAY_H_

#include "ISO-8583/DTT/ISO-8583-DTT.h"
#include "ISO-8583/DTT/Numeric.h"

namespace ISO_8583 {
namespace DTT {

		class DTT_API_SCOPE Day : public Numeric < 2 > {
		private:
			typedef  Numeric < 2 > BaseType;

		public:
			Day();
			~Day();
			Day& operator=(const string& day);
			Day& operator=(const char* day);
			Day& operator=(nat8 day);
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, Day& day);
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Day& day);
		};

}
}

#endif
