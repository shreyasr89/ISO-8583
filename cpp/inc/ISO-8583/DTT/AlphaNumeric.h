#ifndef _ALPHANUMERIC_H_
#define _ALPHANUMERIC_H_

#include <iostream>
using  std::ostream;
using  std::istream;
#include <string>
using  std::string;

#include "ISO-8583-DTT.h"
#include "ISO-8583/DTT/Bytes.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {

		bool isAlphaNumeric(byte value);
		bool isAlphaNumeric(char value);
		bool isAlphaNumeric(const char* value);

		class IsAnAlphaNumeric : public IsA {
		public:
			bool operator()(byte b);
		};
		class NotAnAlphaNumeric : public NotA {
		public:
			NotAnAlphaNumeric() : NotA("not an AlphaNumeric")  {}
			void operator()(byte b);
			void operator()(char b);
			void operator()(char b, const char* value);
		};

		extern IsAnAlphaNumeric isAnAlphaNumeric;
		extern NotAnAlphaNumeric notAnAlphaNumeric;

		template<int sizeb>
		class DTT_API_SCOPE AlphaNumeric : public Bytes < sizeb, ' ' > {
		public:
			typedef Bytes <sizeb, ' ' > DataType;

		public:
			AlphaNumeric(nat8 value = 0);
			AlphaNumeric(const char* value);
			~AlphaNumeric();

			AlphaNumeric& operator= (const string& value);
			AlphaNumeric& operator= (const char* value);
			AlphaNumeric& operator= (nat8 value);

			bool operator==(nat8 value) const;
			bool operator==(const string& value) const;

			template<int size>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, AlphaNumeric<size>& an);
			template<int size>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const AlphaNumeric<size>& an);
		};
	}
}
#endif // !_ALPHABETIC_H_
