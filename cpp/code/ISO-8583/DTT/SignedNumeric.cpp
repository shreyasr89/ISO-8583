/*
 * SignedNumeric.cpp
 *
 *  Created on: 24 mai 2015
 *      Author: FrancisANDRE
 */

#include <stdexcept>
using namespace std;
#include "ISO-8583/DTT/SignedNumeric.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {

		template<int precision, int scale>
		int64_t	SignedNumeric<precision, scale>::toLong() const {
			int64_t value = static_cast<const Numeric<precision, scale>&>(*this).toLong();
			if (sign == '-')
				value = -value;
			return value;
		}

		template<int precision, int scale>
		SignedNumeric<precision, scale>& SignedNumeric<precision, scale>::operator=(int64_t value) {
			nat8	positive;
			if (value < 0) {
				positive = -value; sign = '-';
			}
			else {
				positive = value; sign = '+';
			}
			static_cast<Numeric<precision, scale>&>(*this) = positive;
			return *this;
		}

		template<int precision, int scale>
		SignedNumeric<precision, scale>& SignedNumeric<precision, scale>::operator=(const string& value) {
			*this = value.c_str();
			return *this;
		}
		template<int precision, int scale>
		SignedNumeric<precision, scale>& SignedNumeric<precision, scale>::operator=(const char* value) {
			static_cast<Numeric<precision, scale>&>(*this) = value;
			sign = '+';
			return *this;
		}

		template<int precision, int scale>
		string	SignedNumeric<precision, scale>::str() const {
			string value;
			value += sign;
			value += static_cast<const Numeric<precision, scale>&>(*this).str();
			return value;
		}

		template<int precision, int scale>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, SignedNumeric<precision, scale>& sn) {
			/*
			'+' as 'C' for CREDIT for positive value
			'-' as 'D' for DEBIT  for negative value
			*/
			is >> sn.sign;
			if (sn.sign == 'C')
				sn.sign = '+';
			else if (sn.sign == 'D')
				sn.sign = '-';
			else
				throw invalid_argument(string("invalid sign ") + sn.sign);
			is >> static_cast<Numeric<precision, scale>&>(sn);
			return is;
		}

		template<int precision, int scale>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const SignedNumeric<precision, scale>& sn) {
			/*
			'+' as 'C' for CREDIT for positive value
			'-' as 'D' for DEBIT  for negative value
			*/
			if (sn.sign == '+')
				os << 'C';
			else if (sn.sign == '-')
				os << 'D';
			else
				throw invalid_argument(string("invalid sign ") + sn.sign);
			for (int no = 0; no < sizeof(sn.bytes); no++) {
					os << (char)(sn.bytes[no]);
			}
			return os;
		}

		INOUT(SignedNumeric, 8);
		INOUT(SignedNumeric, 19);

		template class SignedNumeric < 8 > ;
		template class  SignedNumeric < 19 > ;
	}
}
