#ifndef _ALPHANUMERICSPECIAL_H_
#define _ALPHANUMERICSPECIAL_H_

#include <iostream>
using  std::ostream;
using  std::istream;
#include <string>
using  std::string;


#include "ISO-8583-DTT.h"
#include "ISO-8583/DTT/Bytes.h"

namespace ISO_8583 {
	namespace DTT {
		bool isAlphaNumericSpecial(byte value);
		bool isAlphaNumericSpecial(char value);
		bool isAlphaNumericSpecial(const char* value);

		class IsAnAlphaNumericSpecial : public IsA {
		public:
			bool operator()(byte b);
		};
		class NotAnAlphaNumericSpecial : public NotA {
		public:
			NotAnAlphaNumericSpecial() : NotA("not an AlphaNumericSpecial")  {}
			void operator()(byte b);
			void operator()(char b);
			void operator()(char b, const char* value);
		};

		extern IsAnAlphaNumericSpecial isAnAlphaNumericSpecial;
		extern NotAnAlphaNumericSpecial notAnAlphaNumericSpecial;

		template<int sizeb>
		class DTT_API_SCOPE AlphaNumericSpecial : public Bytes < sizeb, ' ' > {
		private:
			typedef Bytes <sizeb, ' ' > DataType;

		public:
			explicit AlphaNumericSpecial(const char* value = NULL);
			~AlphaNumericSpecial();

			AlphaNumericSpecial& operator= (const string& value);
			AlphaNumericSpecial& operator= (const char* value);
			AlphaNumericSpecial& operator= (nat8 value);

			template<int size>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, AlphaNumericSpecial<size>& ans);
			template<int size>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const AlphaNumericSpecial<size>& ans);
		};
	}
}
#endif // !_ALPHABETIC_H_
