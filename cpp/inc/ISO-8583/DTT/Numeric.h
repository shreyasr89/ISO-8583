#ifndef NUMERIC_H_
#define NUMERIC_H_

#include <iostream>
using  std::istream;
using  std::ostream;

#include "ISO-8583-DTT.h"
#include "ISO-8583/DTT/Exception.h"
#include "ISO-8583/DTT/Bytes.h"

namespace ISO_8583 {
	namespace DTT {
		class IsANumeric : public IsA {
		public:
			bool operator()(byte b);
		};
		class NotANumeric : public NotA {
		public:
			NotANumeric() : NotA("not an Numeric")  {}
			virtual void operator()(byte b);
			virtual void operator()(char b);
			virtual void operator()(char b, const char* value);
		};

		extern IsANumeric isANumeric;
		extern NotANumeric notANumeric;

		template<int precision, int scale = 0>
		class DTT_API_SCOPE Numeric : public Bytes < precision, '0', Justification::right > {
		public:
			typedef	Bytes < precision, '0', Justification::right > DataType;

		private:
			void assign(nat8 value);
			void assign(const string& value);
			void assign(const char* value);

		public:
			Numeric(nat8 value);
			explicit Numeric(const char* value = NULL);
			~Numeric();

			nat8  toLong() const;
			nat1  prec() const;

			Numeric& operator=(const string& value);
			Numeric& operator=(const char* value);
			Numeric& operator=(nat8 value);

			bool operator==(nat8 value) const;
			bool operator==(const char* value) const;
			bool operator==(const Numeric& value) const;

			template<int precizion, int skale>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, Numeric<precizion, skale>& n);
			template<int precizion, int skale>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Numeric<precizion, skale>& n);
		};
	}
}
#endif // !NUMERIC_H_
