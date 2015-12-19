/*
 * Minute.cpp
 *
 *  Created on: 5 juil. 2015
 *      Author: FrancisANDRE
 */

#include <cassert>
using namespace std;

#include "ISO-8583/DTT/Minute.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
namespace DTT {
		Minute::Minute() {
			assert(sizeof(Minute) == sizeof(BaseType));
		}
		Minute::~Minute() {

		}
		Minute& Minute::operator=(const string& minute) {
			long minuteAsLong = strtol(minute.data(), NULL, 10);
			*this = minuteAsLong;
			return *this;
		}
		Minute& Minute::operator=(const char* minute) {
			long minuteAsLong = strtol(minute, NULL, 10);
			*this = minuteAsLong;
			return *this;
		}
		Minute& Minute::operator=(nat8 minute) {
			if (0 <= minute && minute <= 59)
				static_cast<BaseType&>(*this) = minute;
			else
				throw invalid_argument("Not a minute: " + to_string(minute));
			return *this;
		}
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, Minute& minute) {
			is >> static_cast<Minute::BaseType&>(minute);
			return is;
		}
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Minute& minute) {
			os << static_cast<const Minute::BaseType&>(minute);
			return os;
		}
	}
}
