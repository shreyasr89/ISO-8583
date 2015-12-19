/*
 * LLAlphaNumericSpecial.cpp
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */
#include <stdexcept>
using namespace std;

#include "ISO-8583/DTT/LLAlphaNumericSpecial.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		LLAlphaNumericSpecial<sizeb>& LLAlphaNumericSpecial<sizeb>::operator = (const string& value) {
			length(DataType::fill(&isAnAlphaNumericSpecial, &notAnAlphaNumericSpecial, value));
			return *this;
		}
		template<int sizeb>
		LLAlphaNumericSpecial<sizeb>& LLAlphaNumericSpecial<sizeb>::operator = (const char* value) {
			length(DataType::fill(&isAnAlphaNumericSpecial, &notAnAlphaNumericSpecial, value));
			return *this;
		}
		template<int sizeb>
		LLAlphaNumericSpecial<sizeb>& LLAlphaNumericSpecial<sizeb>::operator = (nat8 value) {
			length(DataType::fill(&isAnAlphaNumericSpecial, &notAnAlphaNumericSpecial, value));
			return *this;
		}
		template<int sizeb>
		string LLAlphaNumericSpecial<sizeb>::str() const {
			return string((const char*)DataType::bytes, length());
		}
		template<int size>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLAlphaNumericSpecial<size>& llas) {
			is >> static_cast<LL&>(llas);
			llas.fill(&isAnAlphaNumericSpecial, &notAnAlphaNumericSpecial, is, llas.length());
			return is;
		}
		template<int size>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLAlphaNumericSpecial<size>& llas) {
			os << static_cast<const LL&>(llas);
			for (int no = 0; no < llas.length(); no++) {
				os << (char)llas.bytes[no];
			}
			return os;
		}

		INOUT(LLAlphaNumericSpecial, 4);
		INOUT(LLAlphaNumericSpecial, 8);
		INOUT(LLAlphaNumericSpecial, 25);
		INOUT(LLAlphaNumericSpecial, 35);
		INOUT(LLAlphaNumericSpecial, 40);
		INOUT(LLAlphaNumericSpecial, 99);
		INOUT(LLAlphaNumericSpecial, 255);

		template class LLAlphaNumericSpecial < 4 > ;
		template class LLAlphaNumericSpecial < 8 > ;
		template class LLAlphaNumericSpecial < 25 > ;
		template class LLAlphaNumericSpecial < 35 > ;
		template class LLAlphaNumericSpecial < 40 > ;
		template class LLAlphaNumericSpecial < 99 > ;
		template class LLAlphaNumericSpecial < 255 > ;
	}
}


