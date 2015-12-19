/*
 * LLLAlphaNumericSpecial.cpp
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#include <iostream>
#include <stdexcept>
using namespace std;
#include "ISO-8583/DTT/LLLAlphaNumericSpecial.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"


namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		LLLAlphaNumericSpecial<sizeb>& LLLAlphaNumericSpecial<sizeb>::operator = (const string& value) {
			length(DataType::fill(&isAnAlphaNumericSpecial, &notAnAlphaNumericSpecial, value));
			return *this;
		}
		template<int sizeb>
		LLLAlphaNumericSpecial<sizeb>& LLLAlphaNumericSpecial<sizeb>::operator = (const char* value) {
			length(DataType::fill(&isAnAlphaNumericSpecial, &notAnAlphaNumericSpecial, value));
			return *this;
		}
		template<int sizeb>
		LLLAlphaNumericSpecial<sizeb>& LLLAlphaNumericSpecial<sizeb>::operator = (nat8 value) {
			length(DataType::fill(&isAnAlphaNumericSpecial, &notAnAlphaNumericSpecial, value));
			return *this;
		}
		template<int size>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLLAlphaNumericSpecial<size>& lllans) {
			is >> static_cast<LLL&>(lllans);
			lllans.fill(&isAnAlphaNumericSpecial, &notAnAlphaNumericSpecial, is, lllans.length());
			return is;
		}
		template<int size>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLLAlphaNumericSpecial<size>& lllans) {
			os << static_cast<const LLL&>(lllans);
			for (int no = 0; no < lllans.length(); no++) {
				os << lllans.bytes[no];
			}
			return os;
		}

		INOUT(LLLAlphaNumericSpecial, 120);
		INOUT(LLLAlphaNumericSpecial, 126);
		INOUT(LLLAlphaNumericSpecial, 140);
		INOUT(LLLAlphaNumericSpecial, 255);
		INOUT(LLLAlphaNumericSpecial, 216);
		INOUT(LLLAlphaNumericSpecial, 999);

		template class LLLAlphaNumericSpecial < 120 > ;
		template class LLLAlphaNumericSpecial < 126 > ;
		template class LLLAlphaNumericSpecial < 140 > ;
		template class LLLAlphaNumericSpecial < 216 > ;
		template class LLLAlphaNumericSpecial < 255 > ;
		template class LLLAlphaNumericSpecial < 999 > ;
	}
}
