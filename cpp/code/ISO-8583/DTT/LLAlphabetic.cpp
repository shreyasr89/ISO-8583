/*
 * LLAlphabetic.cpp
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#include <iostream>
#include <stdexcept>
using namespace std;
#include "ISO-8583/DTT/LLAlphabetic.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		LLAlphabetic<sizeb>& LLAlphabetic<sizeb>::operator = (const string& value) {
			length(DataType::fill(&isAnAlphabetic, &notAnAlphabetic, value));
			return *this;
		}
		template<int sizeb>
		LLAlphabetic<sizeb>& LLAlphabetic<sizeb>::operator = (const char* value) {
			length(DataType::fill(&isAnAlphabetic, &notAnAlphabetic, value));
			return *this;
		}

		template<int sizeb>
		string LLAlphabetic<sizeb>::str() const {
			return string((const char*)DataType::bytes, length());
		}
		template<int sizeb>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLAlphabetic<sizeb>& lla) {
 			is >> static_cast<LL&>(lla);
			lla.fill(&isAnAlphabetic, &notAnAlphabetic, is, lla.length());
			return is;
		}
		template<int sizeb>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLAlphabetic<sizeb>& lla) {
	 		os << static_cast<const LL&>(lla); \
			for (int no = 0; no < lla.length(); no++) {
				os << lla.bytes[no];
			}
			return os;
		}

		INOUT(LLAlphabetic, 4);
		INOUT(LLAlphabetic, 8);

		template class LLAlphabetic<4> ;
		template class LLAlphabetic<8> ;
	}
}

