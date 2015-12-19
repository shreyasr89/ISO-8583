/*
 * LLAlphaNumericSpecial.h
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef LLALPHANUMERICSPECIAL_H_
#define LLALPHANUMERICSPECIAL_H_
#include <iostream>
using  std::ostream;
using  std::istream;
#include <string>
using  std::string;


#include "ISO-8583/DTT/LL.h"
#include "ISO-8583/DTT/AlphaNumericSpecial.h"

namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		class DTT_API_SCOPE LLAlphaNumericSpecial : public LL, public AlphaNumericSpecial < sizeb > {
		private:
			typedef	AlphaNumericSpecial < sizeb > DataType;

		public:
			explicit LLAlphaNumericSpecial() {
			}
			~LLAlphaNumericSpecial() {
			}

			LLAlphaNumericSpecial& operator=(const string& value);
			LLAlphaNumericSpecial& operator=(const char* value);
			LLAlphaNumericSpecial& operator=(nat8 value);
			string str() const;

			template<int size>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLAlphaNumericSpecial<size>& llans);
			template<int size>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLAlphaNumericSpecial<size>& llans);

			byte* data(int offset = 0) const {
				byte* b = (byte*)static_cast<const DataType*>(this);
				return b + offset;
			}
		};
	}
}
#endif
