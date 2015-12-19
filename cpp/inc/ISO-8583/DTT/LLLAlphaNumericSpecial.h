/*
 * LLLAlphaNumericSpecial.h
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef LLLALPHANUMERICSPECIAL_H_
#define LLLALPHANUMERICSPECIAL_H_
#include <iostream>
using  std::ostream;
using  std::istream;
#include <string>
using  std::string;


#include "ISO-8583/DTT/LLL.h"
#include "ISO-8583/DTT/AlphaNumericSpecial.h"

namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		class DTT_API_SCOPE LLLAlphaNumericSpecial : public LLL, public AlphaNumericSpecial < sizeb > {
		private:
			typedef	AlphaNumericSpecial < sizeb > DataType;

		public:
			explicit LLLAlphaNumericSpecial() {
			}
			~LLLAlphaNumericSpecial() {
			}

			LLLAlphaNumericSpecial& operator=(const string& value);
			LLLAlphaNumericSpecial& operator=(const char* value);
			LLLAlphaNumericSpecial& operator=(nat8 value);

			template<int size>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLLAlphaNumericSpecial<size>& lllans);
			template<int size>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLLAlphaNumericSpecial<size>& lllans);


			byte* data(int offset = 0) const {
				byte* b = (byte*)static_cast<const DataType*>(this);
				return b + offset;
			}
		};
	}
}
#endif
