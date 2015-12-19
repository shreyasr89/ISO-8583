/*
 * LL.cpp
 *
 *  Created on: 29 mai 2015
 *      Author: FrancisANDRE
 */

#include <iostream>
using namespace std;
#include "ISO-8583/DTT/LL.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		const byte	LL::length() const {
			return (mLength.L1 - '0') * 10 + mLength.L0 - '0';
		}
		void LL::length(byte length) {
			mLength.L1 = (length / 10) + '0'; 
			mLength.L0 = (length % 10) + '0';
		}
		void LL::clear() {
			mLength.L1 = '0'; 
			mLength.L0 = '0';
		}
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, LL& ll) {
			ll.clear();
			is >> ll.mLength.L1;
			is >> ll.mLength.L0;
			return is;
		}
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LL& ll) {
			os << ll.mLength.L1;
			os << ll.mLength.L0;
			return os;
		}
	}
}
