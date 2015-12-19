/*
 * AlphaNumericSpace.h
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef ALPHANUMERICSPACE_H_
#define ALPHANUMERICSPACE_H_

#include <iostream>
using  std::ostream;
using  std::istream;
#include <string>
using  std::string;


#include "ISO-8583-DTT.h"
#include "ISO-8583/DTT/Bytes.h"

namespace ISO_8583 {
	namespace DTT {
		bool isAlphaNumericSpace(byte value);
		bool isAlphaNumericSpace(char value);
		bool isAlphaNumericSpace(const char* value);

		class IsAnAlphaNumericSpace : public IsA {
		public:
			bool operator()(byte b);
		};
		class NotAnAlphaNumericSpace : public NotA {
		public:
			NotAnAlphaNumericSpace() : NotA("not an AlphaNumericSpace")  {}
			void operator()(byte b);
			void operator()(char b);
			void operator()(char b, const char* value);
		};

		extern IsAnAlphaNumericSpace isAnAlphaNumericSpace;
		extern NotAnAlphaNumericSpace notAnAlphaNumericSpace;

		template<int sizeb>
		class DTT_API_SCOPE AlphaNumericSpace : public Bytes < sizeb, ' ' > {
		private:
			typedef Bytes <sizeb, ' ' > DataType;


		public:
			explicit AlphaNumericSpace(const char* value = NULL);
			~AlphaNumericSpace();

			AlphaNumericSpace& operator= (const string& value);
			AlphaNumericSpace& operator= (const char* value);
			AlphaNumericSpace& operator= (nat8 value);

			template<int size>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, AlphaNumericSpace<size>& ans);
			template<int size>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const AlphaNumericSpace<size>& ans);
		};
	}
}
#endif
