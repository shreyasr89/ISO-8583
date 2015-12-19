/*
 * TransactionLocalTime.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/TransactionLocalTime.h"

namespace ISO_8583 {
namespace DTE {
		TransactionLocalTime& TransactionLocalTime::operator=(const string& value) {
			if (value.size() > 6)
				throw invalid_argument("hhmmss value too large");
			hour() = value.substr(0, 2);
			minute() = value.substr(2, 2);
			second() = value.substr(4, 2);
			return *this;
		}
		TransactionLocalTime& TransactionLocalTime::operator=(const char* value) {
			*this = string(value);
			return *this;
		}
		TransactionLocalTime& TransactionLocalTime::operator=(nat8 value) {
			hour() = value / 10000;
			value = value % 10000;
			minute() = value / 100;
			second() = value % 100;
			return *this;
		}
		void TransactionLocalTime::decode(InputStream& is) {
			is >> this->hour();
			is >> this->minute();
			is >> this->second();
		}
		void TransactionLocalTime::encode(OutputStream& os) {
			os << this->hour();
			os << this->minute();
			os << this->second();
		}
		string TransactionLocalTime::toString() const {
			string s = hour().str() + minute().str() + second().str();
			return s;
		}
}
}
