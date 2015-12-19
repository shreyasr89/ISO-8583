/*
 * NumericSpecial.cpp
 *
 *  Created on: 24 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTT/NumericSpecial.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		template<int precision, int scale>
		NumericSpecial<precision, scale>& NumericSpecial<precision, scale>::operator=(const string& value) {
			static_cast<Numeric<precision, scale>&>(*this) = value;
			return *this;
		}
		template<int precision, int scale>
		NumericSpecial<precision, scale>& NumericSpecial<precision, scale>::operator=(const char* value) {
			static_cast<Numeric<precision, scale>&>(*this) = value;
			return *this;
		}

		template<int precision, int scale>
		string	NumericSpecial<precision, scale>::str() const {
			return static_cast<const Numeric<precision, scale>&>(*this).str();
		}
		template<int precision, int scale>
		nat8	NumericSpecial<precision, scale>::toLong() const {
			return static_cast<const Numeric<precision, scale>&>(*this).toLong();
		}

		template<int precision, int scale>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, NumericSpecial<precision, scale>& ps) {
			is >> static_cast<Numeric<precision, scale>&>(ps);
			return is;
		}
		template<int precision, int scale>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const NumericSpecial<precision, scale>& ps) {
			os << static_cast<const Numeric<precision, scale>&>(ps);
			return os;
		}

		INOUT(NumericSpecial, 8);
		INOUT(NumericSpecial, 28);

		template class NumericSpecial < 8 > ;
		template class  NumericSpecial < 28 > ;
	}
}

