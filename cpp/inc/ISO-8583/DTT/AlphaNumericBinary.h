/*
 * AlphaNumericBinary.h
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef ALPHANUMERICBINARY_H_
#define ALPHANUMERICBINARY_H_

#include <iostream>
using  std::ostream;
using  std::istream;
#include <string>
using  std::string;


#include "ISO-8583-DTT.h"
#include "ISO-8583/DTT/Bytes.h"

namespace ISO_8583 {
	namespace DTT {
		bool isAlphaNumericBinary(byte value);
		bool isAlphaNumericBinary(char value);
		bool isAlphaNumericBinary(const char* value);

		class IsAnAlphaNumericBinary : public IsA {
		public:
			bool operator()(byte b);
		};
		class NotAnAlphaNumericBinary : public NotA {
		public:
			NotAnAlphaNumericBinary() : NotA("not an AlphaNumericBinary")  {}
			void operator()(byte b);
			void operator()(char b);
			void operator()(char b, const char* value);
		};

		extern IsAnAlphaNumericBinary isAnAlphaNumericBinary;
		extern NotAnAlphaNumericBinary notAnAlphaNumericBinary;

		template<int sizeb>
		class DTT_API_SCOPE AlphaNumericBinary : public Bytes < sizeb, ' ' > {
		private:
			typedef Bytes <sizeb, ' ' > DataType;

		public:
			explicit AlphaNumericBinary(const char* value = NULL);
			~AlphaNumericBinary();

			AlphaNumericBinary& operator= (const string& value);
			AlphaNumericBinary& operator= (const char* value);

			template<int size>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, AlphaNumericBinary<size>& anb);
			template<int size>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const AlphaNumericBinary<size>& anb);
		};
	}
}
#endif
