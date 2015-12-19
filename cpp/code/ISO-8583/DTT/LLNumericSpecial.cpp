/*
 * LLNumericSpecial.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTT/LLNumericSpecial.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		template<int precision, int scale>
		LLNumericSpecial<precision, scale>& LLNumericSpecial<precision, scale>::operator= (const string& value) {
			DataType::clear();
			LL::clear();
			if (value.size() > 0) {
				static_cast<DataType&>(*this) = value;
				length(value.size());
			}
			return *this;
		}
		template<int precision, int scale>
		LLNumericSpecial<precision, scale>& LLNumericSpecial<precision, scale>::operator= (const char* value) {
			DataType::clear();
			LL::clear();
			if (value) {
				static_cast<DataType&>(*this) = value;
				length(strlen(value));
			}
			return *this;
		}
		template<int precision, int scale>
		LLNumericSpecial<precision, scale>& LLNumericSpecial<precision, scale>::operator= (nat8 value) {
			DataType::clear();
			LL::clear();
			*(char*)0 = 0;//TODO 
			return *this;
		}
		template<int precision, int scale>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLNumericSpecial<precision, scale>& llns) {
			\
				is >> static_cast<LL&>(llns);
				return is;
		}
		template<int precision, int scale>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLNumericSpecial<precision, scale>& llns) {
			\
				os << static_cast<const LL&>(llns);
				for (int no = sizeof(llns.bytes) - llns.length(); no < sizeof(llns.bytes); no++) {
				\
					os << (char)(llns.bytes[no]);
				}
				return os;
		}
		INOUT(LLNumericSpecial, 8);
		INOUT(LLNumericSpecial, 28);

		template class  LLNumericSpecial < 8 > ;
		template class  LLNumericSpecial < 28 > ;
	}
}
