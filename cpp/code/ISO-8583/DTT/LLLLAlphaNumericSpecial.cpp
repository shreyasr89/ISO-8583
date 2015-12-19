/*
 * LLLLAlphaNumericSpecial.cpp
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#include <iostream>
#include <stdexcept>
using namespace std;
#include "ISO-8583/DTT/LLLLAlphaNumericSpecial.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		LLLLAlphaNumericSpecial<sizeb>& LLLLAlphaNumericSpecial<sizeb>::operator = (const string& value) {
			length(DataType::fill(&isAnAlphaNumericSpecial, &notAnAlphaNumericSpecial, value));
			return *this;
		}
		template<int sizeb>
		LLLLAlphaNumericSpecial<sizeb>& LLLLAlphaNumericSpecial<sizeb>::operator = (const char* value) {
			length(DataType::fill(&isAnAlphaNumericSpecial, &notAnAlphaNumericSpecial, value));
			return *this;
		}
		template<int sizeb>
		LLLLAlphaNumericSpecial<sizeb>& LLLLAlphaNumericSpecial<sizeb>::operator = (nat8 value) {
			length(DataType::fill(&isAnAlphaNumericSpecial, &notAnAlphaNumericSpecial, value));
			return *this;
		}
		template<int size>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLLLAlphaNumericSpecial<size>& llllans) {
			is >> static_cast<LLLL&>(llllans);
			llllans.fill(&isAnAlphaNumericSpecial, &notAnAlphaNumericSpecial, is, llllans.length());
			return is;
		}
		template<int size>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLLLAlphaNumericSpecial<size>& llllans) {
			os << static_cast<const LLLL&>(llllans);
			for (int no = 0; no < llllans.length(); no++) {
				os << llllans.bytes[no];
			}
			return os;
		}

		INOUT(LLLLAlphaNumericSpecial, 9999);

		template class  LLLLAlphaNumericSpecial < 9999 > ;
	}
}


