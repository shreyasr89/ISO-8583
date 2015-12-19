/*
 * TransactionLocalDate.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/TransactionLocalDate.h"

namespace ISO_8583 {
namespace DTE {
		TransactionLocalDate& TransactionLocalDate::operator=(const string& value) {
			if (value.size() > 4)
				throw invalid_argument("MMDD value too large");
			month() = value.substr(0, 2);
			day() = value.substr(2, 2);
			return *this;
		}
		TransactionLocalDate& TransactionLocalDate::operator=(const char* value) {
			*this = string(value);
			return *this;
		}
		TransactionLocalDate& TransactionLocalDate::operator=(nat8 value) {
			month() = value / 1000;
			day() = value % 100;
			return *this;
		}
		void TransactionLocalDate::decode(InputStream& is) {
			is >> this->month();
			is >> this->day();
		}
		void TransactionLocalDate::encode(OutputStream& os) {
			os << this->month();
			os << this->day();
		}
		string TransactionLocalDate::toString() const {
			string s = month().str() + day().str();
			return s;
		}
}
}
