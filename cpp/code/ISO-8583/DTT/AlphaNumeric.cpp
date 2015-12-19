#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "ISO-8583/DTT/AlphaNumeric.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		bool isAlphaNumeric(byte value) {
			return isalnum(value) != 0;
		}
		bool isAlphaNumeric(char value) {
			return isalnum(value) != 0;
		}
		bool isAlphaNumeric(const char* value) {
			if (value) {
				int no = 0;
				while (value[no])
					if (!isAlphaNumeric(value[no++]))
						return false;
			}
			return true;
		}

		IsAnAlphaNumeric isAnAlphaNumeric;
		NotAnAlphaNumeric notAnAlphaNumeric;

		bool IsAnAlphaNumeric::operator()(byte b) { return isAlphaNumeric(b); }

		void NotAnAlphaNumeric::operator()(byte b) {
			invalidByte = b;
			throw *this; 
		}
		void NotAnAlphaNumeric::operator()(char b) {
			invalidByte = b;
			throw *this; 
		}
		void NotAnAlphaNumeric::operator()(char b, const char* value) {
			invalidByte = b;
			invalidString = value;
			throw *this; 
		}

		template<int sizeb>
		AlphaNumeric<sizeb>::AlphaNumeric(nat8 value) {
			DataType::fill(&isAnAlphaNumeric, &notAnAlphaNumeric, value);
		}
		template<int sizeb>
		AlphaNumeric<sizeb>::AlphaNumeric(const char* value) {
			DataType::fill(&isAnAlphaNumeric, &notAnAlphaNumeric, value);
		}
		template<int sizeb>
		AlphaNumeric<sizeb>::~AlphaNumeric() {

		}
		template<int sizeb>
		AlphaNumeric<sizeb>& AlphaNumeric<sizeb>::operator= (const string& value) {
			DataType::fill(&isAnAlphaNumeric, &notAnAlphaNumeric, value);
			return *this;
		}
		template<int sizeb>
		AlphaNumeric<sizeb>& AlphaNumeric<sizeb>::operator= (nat8 value) {
			stringstream ss; ss.width(sizeb); ss.fill('0');
			ss << value;
			DataType::fill(&isAnAlphaNumeric, &notAnAlphaNumeric, ss.str());
			return *this;
		}
		template<int sizeb>
		AlphaNumeric<sizeb>& AlphaNumeric<sizeb>::operator= (const char* value) {
			DataType::fill(&isAnAlphaNumeric, &notAnAlphaNumeric, value);
			return *this;
		}
		template<int sizeb>
		bool AlphaNumeric<sizeb>::operator==(nat8 value) const {
			stringstream ss; ss.width(sizeb); ss.fill('0');
			ss << value;
			return static_cast<const DataType&>(*this) == ss.str();
		}
		template<int sizeb>
		bool AlphaNumeric<sizeb>::operator==(const string& value) const {
			return static_cast<const DataType&>(*this) == value;
		}
		template<int size>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is,   AlphaNumeric<size>& an) {
			an.fill(&isAnAlphaNumeric, &notAnAlphaNumeric, is);
			return is;
		}
		template<int size>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const AlphaNumeric<size>& an) {
			os << static_cast<const typename AlphaNumeric<size>::DataType&>(an);
			return os;
		}

		INOUT(AlphaNumeric, 1);
		INOUT(AlphaNumeric, 2);
		INOUT(AlphaNumeric, 3);
		INOUT(AlphaNumeric, 4);
		INOUT(AlphaNumeric, 5);
		INOUT(AlphaNumeric, 6);
		INOUT(AlphaNumeric, 8);
		INOUT(AlphaNumeric, 12);
		INOUT(AlphaNumeric, 24);
		INOUT(AlphaNumeric, 35);
		INOUT(AlphaNumeric, 120);
		INOUT(AlphaNumeric, 999);

		template class AlphaNumeric<1>;
		template class AlphaNumeric<2>;
		template class AlphaNumeric<3>;
		template class AlphaNumeric<4>;
		template class AlphaNumeric<5>;
		template class AlphaNumeric<6>;
		template class AlphaNumeric<8>;
		template class AlphaNumeric<12>;
		template class AlphaNumeric<24>;
		template class AlphaNumeric<35>;
		template class AlphaNumeric<120>;
		template class AlphaNumeric<999>;
	}
}

