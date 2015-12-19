#ifndef ZONED_H_
#define ZONED_H_

#include <iostream>
using  std::istream;
using  std::ostream;

#include "ISO-8583-DTT.h"
#include "ISO-8583/DTT/Exception.h"
#include "ISO-8583/DTT/Bytes.h"

namespace ISO_8583 {
	namespace DTT {
		class IsAZoned : public IsA {
		public:
			bool operator()(byte b);
		};
		class NotAZoned : public NotA {
		public:
			NotAZoned() : NotA("not an Zoned")  {}
			virtual void operator()(byte b);
			virtual void operator()(char b);
			virtual void operator()(char b, const char* value);
		};

		extern IsAZoned isAZoned;
		extern NotAZoned notAZoned;

		template<int precision, int scale = 0>
		class DTT_API_SCOPE Zoned : public Bytes < precision, '0', Justification::right > {
		private:
			typedef	Bytes < precision, '0', Justification::right > DataType;
			void assign(nat8 value);
			void assign(const string& value);
			void assign(const char* value);

		public:
			Zoned(nat8 value);
			explicit Zoned(const char* value = NULL);
			~Zoned();

			nat8  toLong() const;

			Zoned& operator=(const string& value);
			Zoned& operator=(const char* value);
			Zoned& operator=(nat8 value);

			bool operator==(nat8 value) const;
			bool operator==(const char* value) const;
			bool operator==(const Zoned& value) const;

			template<int precizion, int skale>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, Zoned<precizion, skale>& n);
			template<int precizion, int skale>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Zoned<precizion, skale>& n);

		protected:
			static const string		message(const string& arg);
		};
	}
}
#endif // !NUMERIC_H_
