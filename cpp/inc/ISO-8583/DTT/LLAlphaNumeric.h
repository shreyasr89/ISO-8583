/*
 * LLAlphaNumeric.h
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef LLALPHANUMERIC_H_
#define LLALPHANUMERIC_H_

#include <iostream>
using  std::ostream;
using  std::istream;
#include <string>
using  std::string;

#include "ISO-8583/DTT/LL.h"
#include "ISO-8583/DTT/AlphaNumeric.h"

namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		class DTT_API_SCOPE LLAlphaNumeric : public LL, public AlphaNumeric < sizeb > {
		private:
			typedef	AlphaNumeric < sizeb > DataType;

		public:
			explicit LLAlphaNumeric() {
			}
			~LLAlphaNumeric() {
			}

			LLAlphaNumeric& operator=(const string& value);
			LLAlphaNumeric& operator=(const char* value);
			string str() const;

			template<int size>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLAlphaNumeric<size>& llan);
			template<int size>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLAlphaNumeric<size>& llan);

			byte* data(int offset = 0) const {
				byte* b = (byte*)static_cast<const DataType*>(this);
				return b + offset;
			}
		};
	}
}
#endif
