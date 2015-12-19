/*
 * LLAlphaNumeric.cpp
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#include <iostream>
#include <stdexcept>
using namespace std;
#include "ISO-8583/DTT/LLAlphaNumeric.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		string LLAlphaNumeric<sizeb>::str() const {
			return string((const char*)DataType::bytes, length());
		}

		template<int sizeb>
		LLAlphaNumeric<sizeb>& LLAlphaNumeric<sizeb>::operator = (const string& value) {
			length(DataType::fill(&isAnAlphaNumeric, &notAnAlphaNumeric, value));
			return *this;
		}
		template<int sizeb>
		LLAlphaNumeric<sizeb>& LLAlphaNumeric<sizeb>::operator = (const char* value) {
			length(DataType::fill(&isAnAlphaNumeric, &notAnAlphaNumeric, value));
			return *this;
		}
		template<int size>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLAlphaNumeric<size>& llan) {
			is >> static_cast<LL&>(llan);
			llan.fill(&isAnAlphaNumeric, &notAnAlphaNumeric, is, llan.length());
			return is;
		}
		template<int size>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLAlphaNumeric<size>& llan) {
			os << static_cast<const LL&>(llan);
			for (int no = 0; no < llan.length(); no++) {
				os << llan.bytes[no];
			}
			return os;
		}


		INOUT(LLAlphaNumeric, 8);
		INOUT(LLAlphaNumeric, 35);

		template class LLAlphaNumeric < 8 > ;
		template class LLAlphaNumeric < 35 > ;
	}
}

