#ifndef _ALPHABETIC_H_
#define _ALPHABETIC_H_

#include <iostream>
using  std::istream;
using  std::ostream;
#include <string>
using  std::string;

#include "ISO-8583/DTT/ISO-8583-DTT.h"
#include "ISO-8583/DTT/Bytes.h"


namespace ISO_8583 {
	namespace DTT {
		bool isAlphabetic(byte value);
		bool isAlphabetic(char value);
		bool isAlphabetic(const char* value);

		class IsAnAlphabetic : public IsA {
		public:
			bool operator()(byte b);
		};
		class NotAnAlphabetic : public NotA {
		public:
			NotAnAlphabetic() : NotA("not an Alphabetic")  {}
			virtual void operator()(byte b);
			virtual void operator()(char b);
			virtual void operator()(char b, const char* value);
		};

		extern IsAnAlphabetic isAnAlphabetic;
		extern NotAnAlphabetic notAnAlphabetic;

		template<int sizeb>
		class DTT_API_SCOPE Alphabetic : public Bytes < sizeb, ' ' > {
		public:
			typedef Bytes <sizeb, ' ' > DataType;

		public:
			explicit Alphabetic(const char* value = NULL);
			~Alphabetic();

			Alphabetic& operator= (const string& value);
			Alphabetic& operator= (const char* value);

			template<int size>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, Alphabetic<size>& a);
			template<int size>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Alphabetic<size>& a);
		};
	}
}
#endif
