/*
 * AlphaNumericSpace.cpp
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#include <iostream>
#include <stdexcept>
using namespace std;

#include "ISO-8583/DTT/AlphaNumericSpace.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		bool isAlphaNumericSpace(char value) {
			return isalnum(value) || isspace(value);
		}
		bool isAlphaNumericSpace(byte value) {
			return isalnum(value) || isspace(value);
		}
		bool isAlphaNumericSpace(const char* value) {
			if (value) {
				int no = 0;
				while (value[no])  {
					if (!isAlphaNumericSpace(value[no++]))
						return false;
				}
			}
			return true;
		}

		bool IsAnAlphaNumericSpace::operator()(byte b) { return isAlphaNumericSpace(b); }

		void NotAnAlphaNumericSpace::operator()(byte b) {
			invalidByte = b;
			throw *this;
		}
		void NotAnAlphaNumericSpace::operator()(char b) {
			invalidByte = b;
			throw *this;
		}
		void NotAnAlphaNumericSpace::operator()(char b, const char* value) {
			invalidByte = b;
			invalidString = value;
			throw *this;
		}

		IsAnAlphaNumericSpace isAnAlphaNumericSpace;
		NotAnAlphaNumericSpace notAnAlphaNumericSpace;

		template<int sizeb>
		AlphaNumericSpace<sizeb>::AlphaNumericSpace(const char* value) {
			DataType::fill(&isAnAlphaNumericSpace, &notAnAlphaNumericSpace, value);
		}
		template<int sizeb>
		AlphaNumericSpace<sizeb>::~AlphaNumericSpace() {

		}
		template<int sizeb>
		AlphaNumericSpace<sizeb>& AlphaNumericSpace<sizeb>::operator= (const string& value) {
			DataType::fill(&isAnAlphaNumericSpace, &notAnAlphaNumericSpace, value);
			return *this;
		}
		template<int sizeb>
		AlphaNumericSpace<sizeb>& AlphaNumericSpace<sizeb>::operator= (const char* value) {
			DataType::fill(&isAnAlphaNumericSpace, &notAnAlphaNumericSpace, value);
			return *this;
		}
		template<int sizeb>
		AlphaNumericSpace<sizeb>& AlphaNumericSpace<sizeb>::operator= (nat8 value) {
			DataType::fill(&isAnAlphaNumericSpace, &notAnAlphaNumericSpace, value);
			return *this;
		}

		template<int size>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, AlphaNumericSpace<size>& ans) {
			ans.fill(&isAnAlphaNumericSpace, &notAnAlphaNumericSpace, is);
			return is;
		}
		template<int size>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const AlphaNumericSpace<size>& ans) {
			os << static_cast<const typename AlphaNumericSpace<size>::DataType&>(ans);
			return os;
		}
		INOUT(AlphaNumericSpace, 1);
		INOUT(AlphaNumericSpace, 2);
		INOUT(AlphaNumericSpace, 4);
		INOUT(AlphaNumericSpace, 8);
		INOUT(AlphaNumericSpace, 12);
		INOUT(AlphaNumericSpace, 16);
		INOUT(AlphaNumericSpace, 22);
		INOUT(AlphaNumericSpace, 25);
		INOUT(AlphaNumericSpace, 28);
		INOUT(AlphaNumericSpace, 35);
		INOUT(AlphaNumericSpace, 40);
		INOUT(AlphaNumericSpace, 99);
		INOUT(AlphaNumericSpace, 216);
		INOUT(AlphaNumericSpace, 255);
		INOUT(AlphaNumericSpace, 256);
		INOUT(AlphaNumericSpace, 999);


		template class AlphaNumericSpace < 1 > ;
		template class AlphaNumericSpace < 2 > ;
		template class AlphaNumericSpace < 4 > ;
		template class AlphaNumericSpace < 8 > ;
		template class AlphaNumericSpace < 12 > ;
		template class AlphaNumericSpace < 16 > ;
		template class AlphaNumericSpace < 22 > ;
		template class AlphaNumericSpace < 25 > ;
		template class AlphaNumericSpace < 28 > ;
		template class AlphaNumericSpace < 35 > ;
		template class AlphaNumericSpace < 40 > ;
		template class AlphaNumericSpace < 99 > ;
		template class AlphaNumericSpace < 126 > ;
		template class AlphaNumericSpace < 216 > ;
		template class AlphaNumericSpace < 255 > ;
		template class AlphaNumericSpace < 256 > ;
		template class AlphaNumericSpace < 999 > ;
		template class AlphaNumericSpace < 9999 > ;
	}
}

