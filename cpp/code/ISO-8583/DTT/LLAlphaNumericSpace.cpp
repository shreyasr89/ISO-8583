/*
 * LLAlphaNumericSpace.cpp
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */
#include <stdexcept>
using namespace std;

#include "ISO-8583/DTT/LLAlphaNumericSpace.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		LLAlphaNumericSpace<sizeb>& LLAlphaNumericSpace<sizeb>::operator = (const string& value) {
			length(DataType::fill(&isAnAlphaNumericSpace, &notAnAlphaNumericSpace, value));
			return *this;
		}
		template<int sizeb>
		LLAlphaNumericSpace<sizeb>& LLAlphaNumericSpace<sizeb>::operator = (const char* value) {
			length(DataType::fill(&isAnAlphaNumericSpace, &notAnAlphaNumericSpace, value));
			return *this;
		}
		template<int sizeb>
		LLAlphaNumericSpace<sizeb>& LLAlphaNumericSpace<sizeb>::operator = (nat8 value) {
			length(DataType::fill(&isAnAlphaNumericSpace, &notAnAlphaNumericSpace, value));
			return *this;
		}
		template<int sizeb>
		string LLAlphaNumericSpace<sizeb>::str() const {
			return string((const char*)DataType::bytes, length());
		}
		template<int size>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLAlphaNumericSpace<size>& llas) {
			is >> static_cast<LL&>(llas);
			llas.fill(&isAnAlphaNumericSpace, &notAnAlphaNumericSpace, is, llas.length());
			return is;
		}
		template<int size>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLAlphaNumericSpace<size>& llas) {
			os << static_cast<const LL&>(llas);
			for (int no = 0; no < llas.length(); no++) {
				os << (char)llas.bytes[no];
			}
			return os;
		}
		INOUT(LLAlphaNumericSpace, 4);
		INOUT(LLAlphaNumericSpace, 8);
		INOUT(LLAlphaNumericSpace, 28);

		template class LLAlphaNumericSpace < 4 > ;
		template class LLAlphaNumericSpace < 8 > ;
		template class LLAlphaNumericSpace < 28 > ;
	}
}

