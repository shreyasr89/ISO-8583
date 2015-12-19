/*
 * LLLAlphaNumeric.cpp
 *
 *  Created on: 24 mai 2015
 *      Author: FrancisANDRE
 */

#include <stdexcept>
using namespace std;
#include "ISO-8583/DTT/LLLAlphaNumeric.h"

namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		LLLAlphaNumeric<sizeb>& LLLAlphaNumeric<sizeb>::operator = (const string& value) {
			length(DataType::fill(&isAnAlphaNumeric, &notAnAlphaNumeric, value));
			return *this;
		}
		template<int sizeb>
		LLLAlphaNumeric<sizeb>& LLLAlphaNumeric<sizeb>::operator = (const char* value) {
			length(DataType::fill(&isAnAlphaNumeric, &notAnAlphaNumeric, value));
			return *this;
		}
		template<int sizeb>
		LLLAlphaNumeric<sizeb>& LLLAlphaNumeric<sizeb>::operator = (nat8 value) {
			length(DataType::fill(&isAnAlphaNumeric, &notAnAlphaNumeric, value));
			return *this;
		}

		template<int sizeb>
		string LLLAlphaNumeric<sizeb>::str() const {
			return string((const char*)DataType::bytes, length());
		}

		template<int size>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLLAlphaNumeric<size>& lllan) {
			is >> static_cast<LLL&>(lllan);
			lllan.fill(&isAnAlphaNumeric, &notAnAlphaNumeric, is, lllan.length());
			return is;
		}
		template<int size>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLLAlphaNumeric<size>& lllan) {
			os << static_cast<const LLL&>(lllan);
			for (int no = 0; no < lllan.length(); no++) {
				os << lllan.bytes[no];
			}
			return os;
		}

		INOUT(LLLAlphaNumeric, 8);
		INOUT(LLLAlphaNumeric, 35);
		INOUT(LLLAlphaNumeric, 120);
		INOUT(LLLAlphaNumeric, 999);

		template class LLLAlphaNumeric < 8 > ;
		template class LLLAlphaNumeric < 35 > ;
		template class LLLAlphaNumeric < 120 > ;
		template class LLLAlphaNumeric < 999 > ;
	}
}
