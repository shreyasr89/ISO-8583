/*
 * Millisecond.cpp
 *
 *  Created on: 5 juil. 2015
 *      Author: FrancisANDRE
 */

#include <cassert>
using namespace std;

#include "ISO-8583/DTT/Millisecond.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		Millisecond::Millisecond() {
			assert(sizeof(Millisecond) == sizeof(BaseType));
		}
		Millisecond::~Millisecond() {

		}
		Millisecond& Millisecond::operator=(const string& millisecond) {
			long millisecondAsLong = strtol(millisecond.data(), NULL, 10);
			*this = millisecondAsLong;
			return *this;
		}
		Millisecond& Millisecond::operator=(const char* millisecond) {
			long millisecondAsLong = strtol(millisecond, NULL, 10);
			*this = millisecondAsLong;
			return *this;
		}
		Millisecond& Millisecond::operator=(nat8 millisecond) {
			if (0 <= millisecond && millisecond <= 999)
				static_cast<BaseType&>(*this) = millisecond;
			else
				throw invalid_argument("Not a millisecond: " + to_string(millisecond));
			return *this;
		}
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, Millisecond& millisecond) {
			is >> static_cast<Millisecond::BaseType&>(millisecond);
			return is;
		}
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Millisecond& millisecond) {
			os << static_cast<const Millisecond::BaseType&>(millisecond);
			return os;
		}
	}
}
