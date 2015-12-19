/*
 * LLBytes.cpp
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#include <iostream>
#include <stdexcept>
using namespace std;
#include "ISO-8583/DTT/LLBytes.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		LLBytes<sizeb>& LLBytes<sizeb>::operator = (const string& value) {
			length(DataType::fill(value));
			return *this;
		}
		template<int sizeb>
		LLBytes<sizeb>& LLBytes<sizeb>::operator = (const char* value) {
			length(DataType::fill(value));
			return *this;
		}

		template<int sizeb>
		byte* LLBytes<sizeb>::data() const {
			byte* b = (byte*)static_cast<const DataType*>(this);
			return b;
		}

		template<int sizeb>
		byte* LLBytes<sizeb>::check(size_t sz) const {
			if (length() + sz > sizeb)
				throw out_of_range("");
			byte* b = (byte*)static_cast<const DataType*>(this);
			return b + length();
		}


		template<int size>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLBytes<size>& llb) {
			is >> static_cast<LL&>(llb);
			for (size_t no = 0; no < llb.length(); no++) {
				is >> llb.bytes[no];
			}
			return is;
		}
		template<int size>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLBytes<size>& llb) {
			os << static_cast<const LL&>(llb);
			for (int no = 0; no < llb.length(); no++) {
				os << llb.bytes[no];
			}
			return os;
		}

		INOUT(LLBytes, 16);
		INOUT(LLBytes, 37);
		INOUT(LLBytes, 40);
		INOUT(LLBytes, 48);
		INOUT(LLBytes, 76);
		INOUT(LLBytes, 255);

		template class LLBytes < 16 > ;
		template class LLBytes < 37 > ;
		template class LLBytes < 40 > ;
		template class LLBytes < 48 > ;
		template class LLBytes < 76 > ;
		template class LLBytes < 255 > ;
	}
}

