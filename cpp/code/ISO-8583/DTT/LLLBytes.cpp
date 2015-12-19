/*
 * LLLBytes.cpp
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#include <iostream>
#include <stdexcept>
using namespace std;
#include "ISO-8583/DTT/LLLBytes.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		LLLBytes<sizeb>& LLLBytes<sizeb>::operator = (const string& value) {
			length(DataType::fill(value));
			return *this;
		}
		template<int sizeb>
		LLLBytes<sizeb>& LLLBytes<sizeb>::operator = (const char* value) {
			length(DataType::fill(value));
			return *this;
		}

		template<int size>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLLBytes<size>& lllb) {
			is >> static_cast<LLL&>(lllb);
			lllb.fill(&isAByte, &notAByte, is, lllb.length());
			return is;
		}
		template<int size>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLLBytes<size>& lllb) {
			os << static_cast<const LLL&>(lllb);
			for (int no = 0; no < lllb.length(); no++) {
				os << lllb.bytes[no];
			}
			return os;
		}
		INOUT(LLLBytes, 11);
		INOUT(LLLBytes, 104);
		INOUT(LLLBytes, 140);
		INOUT(LLLBytes, 255);

		template class LLLBytes < 11 > ;
		template class LLLBytes < 104 > ;
		template class LLLBytes < 140 > ;
		template class LLLBytes < 255 > ;

	}
}
