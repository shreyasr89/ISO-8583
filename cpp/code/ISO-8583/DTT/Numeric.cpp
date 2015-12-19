#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cassert>
using namespace std;
#include <limits>

#include "ISO-8583/DTT/Numeric.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		bool isNumeric(byte value) {
			return isdigit(value) != 0;
		}
		bool isNumeric(char value) {
			return isdigit(value) != 0;
		}
		bool isNumeric(const char* value) {
			if (value) {
				int no = 0;
				while (value[no])
					if (!isNumeric(value[no++]))
						return false;
			}
			return true;
		}
		bool IsANumeric::operator()(byte b) { return isNumeric(b); }

		void NotANumeric::operator()(byte b) {
			invalidByte = b;
			throw *this;
		}
		void NotANumeric::operator()(char b) {
			invalidByte = b;
			throw *this;
		}
		void NotANumeric::operator()(char b, const char* value) {
			invalidByte = b;
			invalidString = value;
			throw *this;
		}

		IsANumeric isANumeric;
		NotANumeric notANumeric;

		template<int precision, int scale>
		Numeric<precision, scale>::Numeric(nat8 value) {
			assert(sizeof(*this) == precision);
			assign(value);
		}
		template<int precision, int scale>
		Numeric<precision, scale>::Numeric(const char* value) {
			assert(sizeof(*this) == precision);
			assign(value);
		}
		template<int precision, int scale>
		Numeric<precision, scale>::~Numeric() {
		}
		template<int precision, int scale>
		void Numeric<precision, scale>::assign(nat8 value) {
			char	buffer[sizeof(DataType::bytes)];
			memset(buffer, '0', sizeof(buffer));

			if (value < 0)
				throw invalid_argument("value is negative");

			int length = 0;
			while (value != 0) {
				if (length >= sizeof(buffer))
					throw overflow_error("value too big");
				buffer[length++] = value % 10 + '0';
				value = value / 10;
			}

			for (int no = 0; no < sizeof(DataType::bytes); no++) {
				DataType::bytes[no] = buffer[sizeof(DataType::bytes) - no - 1];
			}
		}
		template<int precision, int scale>
		void Numeric<precision, scale>::assign(const string& value) {
			if (value.size() > 0) {
				int length = strlen(value.c_str());
				for (int no = 0; no < length; no++) 	{
					char a = value[no];
					if (!isdigit(a))
						throw std::invalid_argument("not a Numeric");
				}
				DataType::fill(value);
			}
		}

		template<int precision, int scale>
		void Numeric<precision, scale>::assign(const char* value) {
			if (value) {
				int length = strlen(value);
				for (int no = 0; no < length; no++) 	{
					char a = value[no];
					if (!isdigit(a))
						throw std::invalid_argument("not a Numeric");
				}
				DataType::fill(value);
			}
		}

		template<int precision, int scale>
		nat1 Numeric<precision, scale>::prec() const {
			int no = 0;
			for (; no < sizeof(DataType::bytes); no++) {
				if (DataType::bytes[no - 1] != '0')
					break;
			}
			return precision - no;
		}
		template<int precision, int scale>
		nat8 Numeric<precision, scale>::toLong() const {
			nat8 value = 0;
			nat8 powerof10 = 1;
			for (int no = sizeof(DataType::bytes); no >= 1; no--) {
				int digit = DataType::bytes[no - 1] - '0';
				value += digit * powerof10;
				powerof10 *= 10;
			}
			return value;
		}

		template<int precision, int scale>
		Numeric<precision, scale>& Numeric<precision, scale>::operator=(nat8 value) {
			assign(value);
			return *this;
		}

		template<int precision, int scale>
		Numeric<precision, scale>& Numeric<precision, scale>::operator=(const string& value) {
			assign(value);
			return *this;
		}

		template<int precision, int scale>
		Numeric<precision, scale>& Numeric<precision, scale>::operator=(const char* value) {
			assign(value);
			return *this;
		}

		template<int precision, int scale>
		bool Numeric<precision, scale>::operator==(nat8 value) const {
			return toLong() == value;
		}

		template<int precision, int scale>
		bool Numeric<precision, scale>::operator==(const char* value) const {
			Numeric<precision, scale> right;
			right.assign(value);
			return *this == right;
		}

		template<int precision, int scale>
		bool Numeric<precision, scale>::operator==(const Numeric& value) const {
			return static_cast<const DataType&>(*this) == static_cast<const DataType&>(value);
		}


		template<int precision, int scale>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, Numeric<precision, scale>& zd) {
			is >> static_cast<typename Numeric<precision, scale>::DataType&>(zd);
			return is;
		}
		template<int precision, int scale>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Numeric<precision, scale>& zd) {
			os << static_cast<const typename Numeric<precision, scale>::DataType&>(zd);
			return os;
		}
#undef READER
#undef WRITER
#undef INOUT
#define READER(type, stream, precision, scale)	template DTT_API_SCOPE stream& operator>> <precision, scale>(stream& is, type<precision, scale>& a);
#define WRITER(type, stream, precision, scale)	template DTT_API_SCOPE stream& operator<< <precision, scale>(stream& os, const type<precision, scale>& a);
#define INOUT(type, precision, scale)  READER(type, InputStream, precision, scale); WRITER(type, OutputStream, precision, scale)

		INOUT(Numeric, 1, 0);
		INOUT(Numeric, 2, 0);
		INOUT(Numeric, 3, 0);
		INOUT(Numeric, 4, 0);
		INOUT(Numeric, 5, 0);
		INOUT(Numeric, 6, 0);
		INOUT(Numeric, 7, 0);
		INOUT(Numeric, 8, 0);
		INOUT(Numeric, 9, 0);
		INOUT(Numeric, 10, 0);
		INOUT(Numeric, 11, 0);
		INOUT(Numeric, 12, 0);
		INOUT(Numeric, 13, 0);
		INOUT(Numeric, 14, 0);
		INOUT(Numeric, 15, 0);
		INOUT(Numeric, 16, 0);
		INOUT(Numeric, 17, 0);
		INOUT(Numeric, 18, 0);
		INOUT(Numeric, 19, 0);

		INOUT(Numeric, 23, 0);
		INOUT(Numeric, 28, 0);

		INOUT(Numeric, 32, 0);

		INOUT(Numeric, 41, 0);

		template class Numeric < 1, 0 > ;
		template class Numeric < 2, 0 > ;
		template class Numeric < 3, 0 > ;
		template class Numeric < 4, 0 > ;
		template class Numeric < 5, 0 > ;
		template class Numeric < 6, 0 > ;
		template class Numeric < 7, 0 > ;
		template class Numeric < 8, 0 > ;
		template class Numeric < 9, 0 > ;
		template class Numeric < 10, 0 > ;
		template class Numeric < 11, 0 > ;
		template class Numeric < 12, 0 > ;
		template class Numeric < 13, 0 > ;
		template class Numeric < 14, 0 > ;
		template class Numeric < 15, 0 > ;
		template class Numeric < 16, 0 > ;
		template class Numeric < 17, 0 > ;
		template class Numeric < 18, 0 > ;
		template class Numeric < 19, 0 > ;

		template class Numeric < 23, 0 > ;
		template class Numeric < 28, 0 > ;

		template class Numeric < 32, 0 > ;

		template class Numeric < 41, 0 > ;
	}
}

