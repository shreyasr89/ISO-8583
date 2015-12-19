/*
 * Month.cpp
 *
 *  Created on: 5 juil. 2015
 *      Author: FrancisANDRE
 */

#include <cassert>
using namespace std;

#include "ISO-8583/DTT/Month.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
namespace DTT {
		Month::Month() {
			assert(sizeof(Month) == sizeof(BaseType));
		}
		Month::~Month() {

		}
		Month& Month::operator=(const string& month) {
			long monthAsLong = strtol(month.data(), NULL, 10);
			*this = monthAsLong;
			return *this;
		}
		Month& Month::operator=(const char* month) {
			long monthAsLong = strtol(month, NULL, 10);
			*this = monthAsLong;
			return *this;
		}
		Month& Month::operator=(nat8 month) {
			if (1 <= month && month <= 12)
				static_cast<BaseType&>(*this) = month;
			else
				throw invalid_argument("Not a month: " + to_string(month));
			return *this;
		}
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, Month& month) {
			is >> static_cast<Month::BaseType&>(month);
			return is;
		}
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Month& month) {
			os << static_cast<const Month::BaseType&>(month);
			return os;
		}
	}
}
