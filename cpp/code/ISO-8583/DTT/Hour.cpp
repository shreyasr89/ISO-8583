/*
 * Hour.cpp
 *
 *  Created on: 5 juil. 2015
 *      Author: FrancisANDRE
 */

#include <cassert>
using namespace std;

#include "ISO-8583/DTT/Hour.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
namespace DTT {
		Hour::Hour() {
			assert(sizeof(Hour) == sizeof(BaseType));
		}
		Hour::~Hour() {

		}
		Hour& Hour::operator=(const string& hour) {
			long hourAsLong = strtol(hour.data(), NULL, 10);
			*this = hourAsLong;
			return *this;
		}
		Hour& Hour::operator=(const char* hour) {
			long hourAsLong = strtol(hour, NULL, 10);
			*this = hourAsLong;
			return *this;
		}
		Hour& Hour::operator=(nat8 hour) {
			if (0 <= hour && hour <= 23)
				static_cast<BaseType&>(*this) = hour;
			else
				throw invalid_argument("Not a hour: " + to_string(hour));
			return *this;
		}
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, Hour& hour) {
			is >> static_cast<Hour::BaseType&>(hour);
			return is;
		}
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Hour& hour) {
			os << static_cast<const Hour::BaseType&>(hour);
			return os;
		}
}
}
