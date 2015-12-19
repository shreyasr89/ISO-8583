/*
 * Millisecond.h
 *
 *  Created on: 5 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef MILLISECONDE_H_
#define MILLISECONDE_H_

#include "ISO-8583/DTT/ISO-8583-DTT.h"
#include "ISO-8583/DTT/Numeric.h"

namespace ISO_8583 {
	namespace DTT {

		class DTT_API_SCOPE Millisecond : public Numeric < 2 > {
		private:
			typedef  Numeric < 2 > BaseType;

		public:
			Millisecond();
			~Millisecond();
			Millisecond& operator=(const string& millisecond);
			Millisecond& operator=(const char* millisecond);
			Millisecond& operator=(nat8 millisecond);
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, Millisecond& millisecond);
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Millisecond& millisecond);
		};
	}
}

#endif
