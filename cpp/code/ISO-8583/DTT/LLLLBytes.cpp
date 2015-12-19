/*
 * LLLLBytes.cpp
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#include <iostream>
#include <stdexcept>
using namespace std;
#include "ISO-8583/DTT/LLLLBytes.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		LLLLBytes<sizeb>& LLLLBytes<sizeb>::operator = (const string& value) {
			length(DataType::fill(value));
			return *this;
		}
		template<int sizeb>
		LLLLBytes<sizeb>& LLLLBytes<sizeb>::operator = (const char* value) {
			length(DataType::fill(value));
			return *this;
		}

		template<int size>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLLLBytes<size>& llllb) {
			is >> static_cast<LLLL&>(llllb);
			llllb.fill(&isAByte, &notAByte, is, llllb.length());
			return is;
		}

		template<int size>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLLLBytes<size>& llllb) {
			os << static_cast<const LLLL&>(llllb);
			for (int no = 0; no < llllb.length(); no++) {
				os << llllb.bytes[no];
			}
			return os;
		}
		INOUT(LLLLBytes, 9999);

		template class LLLLBytes < 9999 > ;
	}
}
