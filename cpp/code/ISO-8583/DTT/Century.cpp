/*
 * Century.cpp
 *
 *  Created on: 5 juil. 2015
 *      Author: FrancisANDRE
 */
#include <cassert>
using namespace std;

#include "ISO-8583/DTT/Century.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		Century::Century() {
			assert(sizeof(Century) == sizeof(BaseType));
		}
		Century::~Century() {

		}
		Century& Century::operator=(const string& year) {
			static_cast<BaseType&>(*this) = year;
			return *this;
		}
		Century& Century::operator=(const char* year) {
			static_cast<BaseType&>(*this) = year;
			return *this;
		}
		Century& Century::operator=(nat8 year) {
			static_cast<BaseType&>(*this) = year;
			return *this;
		}
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, Century& year) {
			is >> static_cast<Century::BaseType&>(year);
			return is;
		}
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Century& year) {
			os << static_cast<const Century::BaseType&>(year);
			return os;
		}
	}
}
