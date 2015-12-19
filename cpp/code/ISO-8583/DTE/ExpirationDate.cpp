/*
 * ExpirationDate.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include <stdexcept>
using namespace std;

#include "ISO-8583/DTE/ExpirationDate.h"

namespace ISO_8583 {
	namespace DTE {
		ExpirationDate& ExpirationDate::operator=(const string& value) {
			year() = value.substr(0, 2);
			month() = value.substr(2, 2);
			return *this;
		}
		ExpirationDate& ExpirationDate::operator=(const char* value) {
			if (strlen(value) > 4)
				throw invalid_argument("YYMM value too large");
			year() = string(value, 2);
			month() = string(value + 2, 2);
			return *this;
		}
		ExpirationDate& ExpirationDate::operator=(nat8 value) {
			year() = value / 100;
			month() = value % 100;
			return *this;
		}

		void ExpirationDate::decode(InputStream& is) {
			is >> this->year();
			is >> this->month();
		}
		void ExpirationDate::encode(OutputStream& os) {
			os << this->year();
			os << this->month();
		}
		string ExpirationDate::toString() const {
			string s = year().str() + month().str();
			return s;
		}
	}
}