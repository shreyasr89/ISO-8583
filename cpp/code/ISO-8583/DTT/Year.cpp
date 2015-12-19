/*
 * Year.cpp
 *
 *  Created on: 5 juil. 2015
 *      Author: FrancisANDRE
 */

#include <cassert>
using namespace std;

#include "ISO-8583/DTT/Year.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
namespace DTT {
		Year::Year() {
			assert(sizeof(Year) == sizeof(BaseType));
		}
		Year::~Year() {

		}
		Year& Year::operator=(const string& year) {
			static_cast<BaseType&>(*this) = year;
			return *this;
		}
		Year& Year::operator=(const char* year) {
			static_cast<BaseType&>(*this) = year;
			return *this;
		}
		Year& Year::operator=(nat8 year) {
			static_cast<BaseType&>(*this) = year;
			return *this;
		}
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, Year& year) {
			is >> static_cast<Year::BaseType&>(year);
			return is;
		}
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Year& year) {
			os << static_cast<const Year::BaseType&>(year);
			return os;
		}
	}
}
