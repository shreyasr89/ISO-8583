/*
 * Second.cpp
 *
 *  Created on: 5 juil. 2015
 *      Author: FrancisANDRE
 */

#include <cassert>
using namespace std;

#include "ISO-8583/DTT/Second.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
namespace DTT {
		Second::Second() {
			assert(sizeof(Second) == sizeof(BaseType));
		}
		Second::~Second() {

		}
		Second& Second::operator=(const string& second) {
			static_cast<BaseType&>(*this) = second;
			return *this;
		}
		Second& Second::operator=(const char* second) {
			static_cast<BaseType&>(*this) = second;
			return *this;
		}
		Second& Second::operator=(nat8 second) {
			static_cast<BaseType&>(*this) = second;
			return *this;
		}
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, Second& second) {
			is >> static_cast<Second::BaseType&>(second);
			return is;
		}
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Second& second) {
			os << static_cast<const Second::BaseType&>(second);
			return os;
		}
	}
}
