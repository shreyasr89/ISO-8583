/*
 * Second.h
 *
 *  Created on: 5 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef SECOND_H_
#define SECOND_H_


#include "ISO-8583/DTT/ISO-8583-DTT.h"
#include "ISO-8583/DTT/Numeric.h"

namespace ISO_8583 {
	namespace DTT {

		class DTT_API_SCOPE Second : public Numeric < 2 > {
		private:
			typedef  Numeric < 2 > BaseType;

		public:
			Second();
			~Second();
			Second& operator=(const string& second);
			Second& operator=(const char* second);
			Second& operator=(nat8 second);
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, Second& second);
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Second& second);
		};
	}
}
#endif
