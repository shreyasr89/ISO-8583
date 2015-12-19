#include <iostream>
using std::istream;
using std::ostream;
#include <stdexcept>
using std::invalid_argument;

#include "ISO-8583/DTT/AlphaNumericSpecial.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		bool isAlphaNumericSpecial(byte value) {
			return isprint(value) != 0;
		}
		bool isAlphaNumericSpecial(char value) {
			return isprint(value) != 0;
		}
		bool isAlphaNumericSpecial(const char* value) {
			if (value) {
				int no = 0;
				while (value[no])  {
					if (!isAlphaNumericSpecial(value[no++]))
						return false;
				}
			}
			return true;
		}

		IsAnAlphaNumericSpecial isAnAlphaNumericSpecial;
		NotAnAlphaNumericSpecial notAnAlphaNumericSpecial;

		bool IsAnAlphaNumericSpecial::operator()(byte b) {
			return isAlphaNumericSpecial(b);
		}

		void NotAnAlphaNumericSpecial::operator()(byte b) {
			invalidByte = b;
			throw *this;
		}
		void NotAnAlphaNumericSpecial::operator()(char b) {
			invalidByte = b;
			throw *this;
		}
		void NotAnAlphaNumericSpecial::operator()(char b, const char* value) {
			invalidByte = b;
			invalidString = value;
			throw *this;
		}


		template<int sizeb>
		AlphaNumericSpecial<sizeb>::AlphaNumericSpecial(const char* value) {
			DataType::fill(&isAnAlphaNumericSpecial, &notAnAlphaNumericSpecial, value);
		}
		template<int sizeb>
		AlphaNumericSpecial<sizeb>::~AlphaNumericSpecial() {

		}
		template<int sizeb>
		AlphaNumericSpecial<sizeb>& AlphaNumericSpecial<sizeb>::operator= (const string& value) {
			DataType::fill(&isAnAlphaNumericSpecial, &notAnAlphaNumericSpecial, value);
			return *this;
		}
		template<int sizeb>
		AlphaNumericSpecial<sizeb>& AlphaNumericSpecial<sizeb>::operator= (const char* value) {
			DataType::fill(&isAnAlphaNumericSpecial, &notAnAlphaNumericSpecial, value);
			return *this;
		}
		template<int sizeb>
		AlphaNumericSpecial<sizeb>& AlphaNumericSpecial<sizeb>::operator= (nat8 value) {
			DataType::fill(&isAnAlphaNumericSpecial, &notAnAlphaNumericSpecial, value);
			return *this;
		}

		template<int size>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, AlphaNumericSpecial<size>& ans) {
			ans.fill(&isAnAlphaNumericSpecial, &notAnAlphaNumericSpecial, is);
			return is;
		}

		template<int size>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const AlphaNumericSpecial<size>& ans) {
			os << static_cast<const typename AlphaNumericSpecial<size>::DataType&>(ans);
			return os;
		}

		INOUT(AlphaNumericSpecial, 2);
		INOUT(AlphaNumericSpecial, 3);
		INOUT(AlphaNumericSpecial, 4);
		INOUT(AlphaNumericSpecial, 8);

		INOUT(AlphaNumericSpecial, 12);
		INOUT(AlphaNumericSpecial, 15);
		INOUT(AlphaNumericSpecial, 16);
		INOUT(AlphaNumericSpecial, 22);
		INOUT(AlphaNumericSpecial, 25);
		INOUT(AlphaNumericSpecial, 35);
		INOUT(AlphaNumericSpecial, 40);
		INOUT(AlphaNumericSpecial, 76);
		INOUT(AlphaNumericSpecial, 99);
		INOUT(AlphaNumericSpecial, 120);
		INOUT(AlphaNumericSpecial, 126);
		INOUT(AlphaNumericSpecial, 140);
		INOUT(AlphaNumericSpecial, 216);
		INOUT(AlphaNumericSpecial, 255);
		INOUT(AlphaNumericSpecial, 256);
		INOUT(AlphaNumericSpecial, 999);
		INOUT(AlphaNumericSpecial, 9999);


		template class AlphaNumericSpecial < 2 > ;
		template class AlphaNumericSpecial < 3 > ;
		template class AlphaNumericSpecial < 4 > ;
		template class AlphaNumericSpecial < 8 > ;
		template class AlphaNumericSpecial < 12 > ;
		template class AlphaNumericSpecial < 15 > ;
		template class AlphaNumericSpecial < 16 > ;
		template class AlphaNumericSpecial < 22 > ;
		template class AlphaNumericSpecial < 25 > ;
		template class AlphaNumericSpecial < 35 > ;
		template class AlphaNumericSpecial < 40 > ;
		template class AlphaNumericSpecial < 76 > ;
		template class AlphaNumericSpecial < 99 > ;
		template class AlphaNumericSpecial < 120 > ;
		template class AlphaNumericSpecial < 126 > ;
		template class AlphaNumericSpecial < 140 > ;
		template class AlphaNumericSpecial < 216 > ;
		template class AlphaNumericSpecial < 255 > ;
		template class AlphaNumericSpecial < 256 > ;
		template class AlphaNumericSpecial < 999 > ;
		template class AlphaNumericSpecial < 9999 > ;

	}
}
