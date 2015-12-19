/*
 * AlphaNumericBinary.cpp
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#include <iostream>
#include <stdexcept>
using namespace std;
#include "ISO-8583/DTT/AlphaNumericBinary.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		bool isAlphaNumericBinary(byte value) {
			return true;
		}
		bool isAlphaNumericBinary(char value) {
			return true;
		}
		bool isAlphaNumericBinary(const char* value) {
			return true;
		}

		IsAnAlphaNumericBinary isAnAlphaNumericBinary;
		NotAnAlphaNumericBinary notAnAlphaNumericBinary;


		bool IsAnAlphaNumericBinary::operator()(byte b) { return isAlphaNumericBinary(b); }

		void NotAnAlphaNumericBinary::operator()(byte b) {
			invalidByte = b;
			throw *this;
		}
		void NotAnAlphaNumericBinary::operator()(char b) {
			invalidByte = b;
			throw *this;
		}
		void NotAnAlphaNumericBinary::operator()(char b, const char* value) {
			invalidByte = b;
			invalidString = value;
			throw *this;
		}

		template<int sizeb>
		AlphaNumericBinary<sizeb>::AlphaNumericBinary(const char* value) {
			DataType::fill(&isAnAlphaNumericBinary, &notAnAlphaNumericBinary, value);
		}
		template<int sizeb>
		AlphaNumericBinary<sizeb>::~AlphaNumericBinary() {

		}
		template<int sizeb>
		AlphaNumericBinary<sizeb>& AlphaNumericBinary<sizeb>::operator= (const string& value) {
			DataType::fill(&isAnAlphaNumericBinary, &notAnAlphaNumericBinary, value);
			return *this;
		}
		template<int sizeb>
		AlphaNumericBinary<sizeb>& AlphaNumericBinary<sizeb>::operator= (const char* value) {
			DataType::fill(&isAnAlphaNumericBinary, &notAnAlphaNumericBinary, value);
			return *this;
		}

		template<int size>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, AlphaNumericBinary<size>& anb) {
			anb.fill(&isAnAlphaNumericBinary, &notAnAlphaNumericBinary, is);
			return is;
		}
		template<int size>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const AlphaNumericBinary<size>& anb) {
			os << static_cast<const typename AlphaNumericBinary<size>::DataType&>(anb);
			return os;
		}

		INOUT(AlphaNumericBinary, 8);
		INOUT(AlphaNumericBinary, 27);

		template class AlphaNumericBinary < 8 > ;
		template class AlphaNumericBinary < 27 > ;
	}
}



