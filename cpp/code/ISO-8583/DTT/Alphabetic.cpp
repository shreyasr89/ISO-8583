#include <ctype.h>
#include <iostream>
#include <sstream>
using namespace std;
#include "ISO-8583/DTT/Alphabetic.h"
#include "ISO-8583/DTT/Exception.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		bool isAlphabetic(byte value) {
			return isalpha(value) != 0;
		}
		bool isAlphabetic(char value) {
			return isalpha(value) != 0;
		}
		bool isAlphabetic(const char* value) {
			if (value) {
				int no = 0;
				while (value[no])
					if (!isAlphabetic(value[no++]))
						return false;
			}
			return true;
		}
		bool IsAnAlphabetic::operator()(byte b) { return isAlphabetic(b); }

		void NotAnAlphabetic::operator()(byte b) {
			invalidByte = b;
			throw *this; 
		}
		void NotAnAlphabetic::operator()(char b) {
			invalidByte = b;
			throw *this; 
		}
		void NotAnAlphabetic::operator()(char b, const char* value) {
			invalidByte = b;
			invalidString = value;
			throw *this; 
		}

		IsAnAlphabetic isAnAlphabetic;
		NotAnAlphabetic notAnAlphabetic;

		template<int sizeb>
		Alphabetic<sizeb>::Alphabetic(const char* value) {
		 DataType::fill(&isAnAlphabetic, &notAnAlphabetic, value);
		}
		template<int sizeb>
		Alphabetic<sizeb>::~Alphabetic() {

		}
		template<int sizeb>
		Alphabetic<sizeb>& Alphabetic<sizeb>::operator= (const string& value) {
		 DataType::fill(&isAnAlphabetic, &notAnAlphabetic, value);
			return *this;
		}
		template<int sizeb>
		Alphabetic<sizeb>& Alphabetic<sizeb>::operator= (const char* value) {
		 DataType::fill(&isAnAlphabetic, &notAnAlphabetic, value);
			return *this;
		}

		template<int size>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, Alphabetic<size>& a) {
			a.fill(&isAnAlphabetic, &notAnAlphabetic, is);
			return is;
		}
		template<int size>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Alphabetic<size>& a) {
			os << static_cast<const typename Alphabetic<size>::DataType&>(a);
			return os;
		}


		INOUT(Alphabetic, 2);
		INOUT(Alphabetic, 4);
		INOUT(Alphabetic, 8);
		INOUT(Alphabetic, 12);


		template class Alphabetic<2> ;
		template class Alphabetic<4> ;
		template class Alphabetic<8> ;
		template class Alphabetic<12> ;
	}
}
