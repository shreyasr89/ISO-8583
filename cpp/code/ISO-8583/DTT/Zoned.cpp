#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cassert>
using namespace std;
#include <limits>

#include "ISO-8583/DTT/Zoned.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		template<int precision, int scale>
		Zoned<precision, scale>::Zoned(nat8 value) {
			assert(sizeof(*this) == precision);
			assign(value);
		}
		template<int precision, int scale>
		Zoned<precision, scale>::Zoned(const char* value) {
			assign(value);
		}
		template<int precision, int scale>
		Zoned<precision, scale>::~Zoned() {
		}
		template<int precision, int scale>
		void Zoned<precision, scale>::assign(nat8 value) {
			char	buffer[sizeof(DataType::bytes)];
			memset(buffer, '0', sizeof(buffer));

			if (value < 0)
				throw invalid_argument(message("value is negative"));

			int length = 0;
			while (value != 0) {
				if (length >= sizeof(buffer))
					throw overflow_error(message("value too big: ") + to_string(value));
				buffer[length++] = value % 10 + '0';
				value = value / 10;
			}

			for (int no = 0; no < sizeof(DataType::bytes); no++) {
				DataType::bytes[no] = buffer[sizeof(DataType::bytes) - no - 1];
			}
		}
		template<int precision, int scale>
		void Zoned<precision, scale>::assign(const string& value) {
			if (value.size() > 0) {
				int length = strlen(value.c_str());
				for (int no = 0; no < length; no++) 	{
					char a = value[no];
					if (!isdigit(a))
						throw std::invalid_argument(message("not a Zoned") + value);
				}
				DataType::fill(value);
			}
		}

		template<int precision, int scale>
		void Zoned<precision, scale>::assign(const char* value) {
			if (value) {
				int length = strlen(value);
				for (int no = 0; no < length; no++) 	{
					char a = value[no];
					if (!isdigit(a))
						throw std::invalid_argument(message("not a Zoned") + value);
				}
				DataType::fill(value);
			}
		}

		template<int precision, int scale>
		nat8 Zoned<precision, scale>::toLong() const {
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
		Zoned<precision, scale>& Zoned<precision, scale>::operator=(nat8 value) {
			assign(value);
			return *this;
		}

		template<int precision, int scale>
		Zoned<precision, scale>& Zoned<precision, scale>::operator=(const string& value) {
			assign(value);
			return *this;
		}

		template<int precision, int scale>
		Zoned<precision, scale>& Zoned<precision, scale>::operator=(const char* value) {
			assign(value);
			return *this;
		}

		template<int precision, int scale>
		bool Zoned<precision, scale>::operator==(nat8 value) const {
			return toLong() == value;
		}

		template<int precision, int scale>
		bool Zoned<precision, scale>::operator==(const char* value) const {
			Zoned<precision, scale> right;
			right.assign(value);
			return *this == right;
		}

		template<int precision, int scale>
		bool Zoned<precision, scale>::operator==(const Zoned& value) const {
			return static_cast<const DataType&>(*this) == static_cast<const DataType&>(value);
		}

		template<int precision, int scale>
		const string Zoned<precision, scale>::message(const string& arg) {
			string mess = string("Zoned<") + to_string(precision) + ", " + to_string(scale) + ">";
			mess += ": ";
			mess += arg;
			return mess;
		}

		template<int precision, int scale>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, Zoned<precision, scale>& zd) {
			zd.clear();
			for (int no = 0; no < sizeof(zd.bytes); no++) {
				is >> zd.bytes[no];
			}
			return is;
		}
		template<int precision, int scale>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Zoned<precision, scale>& zd) {
			for (int no = 0; no < sizeof(zd.bytes); no++) {
				os << zd.bytes[no];
			}
			return os;
		}
		INOUT(Zoned, 1);
		INOUT(Zoned, 2);
		INOUT(Zoned, 3);
		INOUT(Zoned, 4);
		INOUT(Zoned, 5);
		INOUT(Zoned, 6);
		INOUT(Zoned, 7);
		INOUT(Zoned, 8);
		INOUT(Zoned, 9);
		INOUT(Zoned, 10);
		INOUT(Zoned, 11);
		INOUT(Zoned, 12);
		INOUT(Zoned, 13);
		INOUT(Zoned, 14);
		INOUT(Zoned, 15);
		INOUT(Zoned, 16);
		INOUT(Zoned, 17);
		INOUT(Zoned, 18);
		INOUT(Zoned, 19);

		INOUT(Zoned, 23);
		INOUT(Zoned, 28);

		INOUT(Zoned, 32);

		INOUT(Zoned, 41);

		template class Zoned < 1 > ;
		template class Zoned < 2 > ;
		template class Zoned < 3 > ;
		template class Zoned < 4 > ;
		template class Zoned < 5 > ;
		template class Zoned < 6 > ;
		template class Zoned < 7 > ;
		template class Zoned < 8 > ;
		template class Zoned < 9 > ;
		template class Zoned < 10 > ;
		template class Zoned < 11 > ;
		template class Zoned < 12 > ;
		template class Zoned < 13 > ;
		template class Zoned < 14 > ;
		template class Zoned < 15 > ;
		template class Zoned < 16 > ;
		template class Zoned < 17 > ;
		template class Zoned < 18 > ;
		template class Zoned < 19 > ;

		template class Zoned < 23 > ;
		template class Zoned < 28 > ;

		template class Zoned < 32 > ;

		template class Zoned < 41 > ;
	}
}



