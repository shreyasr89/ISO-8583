/*
 * LLNumeric.cpp
 *
 *  Created on: 24 mai 2015
 *      Author: FrancisANDRE
 */

#include <iostream>
#include <stdexcept>
#include <cassert>
using namespace std;
#include "ISO-8583/DTT/LLNumeric.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		template<int precision, int scale>
		LLNumeric<precision, scale>& LLNumeric<precision, scale>::operator = (const string& value) {
			DataType::clear();
			LL::clear();
			if (value.size() > 0) {
				static_cast<DataType&>(*this) = value;
				length(value.size());
			}
			return *this;
		}
		template<int precision, int scale>
		LLNumeric<precision, scale>& LLNumeric<precision, scale>::operator = (const char* value) {
			DataType::clear();
			LL::clear();
			if (value && strlen(value) > 0) {
				static_cast<DataType&>(*this) = value;
				length(strlen(value));
			}
			return *this;
		}
		template<int precision, int scale>
		LLNumeric<precision, scale>& LLNumeric<precision, scale>::operator = (nat8 value) {
			DataType::clear();
			LL::clear();
			static_cast<DataType&>(*this) = value;
			length(DataType::prec());
			return *this;
		}

		template<int precision, int scale>
		bool LLNumeric<precision, scale>::operator==(const char* value) const {
			return static_cast<const DataType&>(*this) == value;
		}

		template<int precision, int scale>
		string	LLNumeric<precision, scale>::str() const {
			string value;
			for (int no = sizeof(DataType::bytes) - length(); no < sizeof(DataType::bytes); no++) {
				value.push_back(DataType::bytes[no]);
			}
			return value;
		}


		template<int precision, int scale>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLNumeric<precision, scale>& lln) {
			is >> static_cast<LL&>(lln);
			lln.fill(&isANumeric, &notANumeric, is, lln.length());
			return is;
		}
		template<int precision, int scale>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLNumeric<precision, scale>& lln) {
			os << static_cast<const LL&>(lln);
			for (int no = sizeof(lln.bytes) - lln.length(); no < sizeof(lln.bytes); no++) {
				os << (char)(lln.bytes[no]);
			}
			return os;
		}

		INOUT(LLNumeric, 8);
		INOUT(LLNumeric, 11);
		INOUT(LLNumeric, 19);
		INOUT(LLNumeric, 28);
		INOUT(LLNumeric, 41);

		template class LLNumeric < 8 > ;
		template class LLNumeric < 11 > ;
		template class LLNumeric < 19 > ;
		template class LLNumeric < 28 > ;
		template class LLNumeric < 41 > ;
	}
}
