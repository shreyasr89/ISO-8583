/*
 * Day.cpp
 *
 *  Created on: 5 juil. 2015
 *      Author: FrancisANDRE
 */

#include <cassert>
using namespace std;

#include "ISO-8583/DTT/Day.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
namespace DTT {
		Day::Day() {
			assert(sizeof(Day) == sizeof(BaseType));
		}
		Day::~Day() {

		}
		Day& Day::operator=(const string& day) {
			long dayAsLong = strtol(day.data(), NULL, 10);
			*this = dayAsLong;
			return *this;
		}
		Day& Day::operator=(const char* day) {
			long dayAsLong = strtol(day, NULL, 10);
			*this = dayAsLong;
			return *this;
		}
		Day& Day::operator=(nat8 day) {
			if (0 <= day && day <= 31)
				static_cast<BaseType&>(*this) = day;
			else
				throw invalid_argument("Not a day: " + to_string(day));
			return *this;
		}
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, Day& day) {
			is >> static_cast<Day::BaseType&>(day);
			return is;
		}
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Day& day) {
			os << static_cast<const Day::BaseType&>(day);
			return os;
		}
}
}
