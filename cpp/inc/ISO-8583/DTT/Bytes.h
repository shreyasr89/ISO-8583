#ifndef _BYTES_H_
#define _BYTES_H_

#include <cstring>
#include <string>
using  std::string;
#include <algorithm> 
using std::min;

#include "ISO-8583-DTT.h"
#include "ISO-8583/DTT/Exception.h"

namespace ISO_8583 {
	namespace DTT {
		class InputStream;
		class OutputStream;

		enum Justification {
			left,
			right
		};
		enum Encoding {
			ASCII,
			EBCDIC
		};

		class IsAByte : public IsA {
		public:
			bool operator()(byte b);
		};
		class NotAByte : public NotA {
		public:
			NotAByte() : NotA("not a byte") {}
			virtual void operator()(byte b);
			virtual void operator()(char b);
			virtual void operator()(char b, const char* value);
		};

		extern IsAByte isAByte;
		extern NotAByte notAByte;


		template<int sizeb, byte init = ' ', Justification justified = Justification::left, Encoding encoding = ASCII>
		class DTT_API_SCOPE Bytes {
		protected:
			byte	bytes[sizeb];

			void	clear()	{ memset(bytes, init, sizeof(bytes)); }
			int		fill(nat8 value);
			int		fill(const string& value);
			int		fill(const char* value);
			int		fill(IsA* isa, NotA* nota, nat8 value);
			int		fill(IsA* isa, NotA* nota, const string& value);
			int		fill(IsA* isa, NotA* nota, const char* value);
		public:
			InputStream& fill(IsA* isa, NotA* nota, InputStream& is, size_t length = sizeb);

		public:
			explicit Bytes()						{ clear(); }
			~Bytes()								{ }

			Bytes& operator=(const string& value)	{ fill(value.c_str()); return *this; }
			Bytes& operator=(const char* value)		{ fill(value); return *this; }
			bool operator==(const Bytes& value) const;
			bool operator==(const string& value) const;
			bool operator==(const char* value) const;

			const byte&	operator[](int no) const;

			string	str() const;

			template<int size>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, Bytes<size, ' ', Justification::left, Encoding::ASCII>& bs);
			template<int size>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Bytes<size, ' ', Justification::left, Encoding::ASCII>& bs);
			template<int size>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, Bytes<size, '0', Justification::right, Encoding::ASCII>& bs);
			template<int size>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Bytes<size, '0', Justification::right, Encoding::ASCII>& bs);
		};
	}
}
#endif // !_BYTES_H_
