/*
 * LLL.cpp
 *
 *  Created on: 29 mai 2015
 *      Author: FrancisANDRE
 */

#include <iostream>
using namespace std;
#include "ISO-8583/DTT/LLL.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		short	LLL::length() const {
			return (mLength.L2 - '0') * 100 + (mLength.L1 - '0') * 10 + mLength.L0 - '0';
		}
		void LLL::length(short length) {
			mLength.L2 = (length / 100) + '0'; 
			mLength.L1 = ((length % 100) / 10) + '0'; 
			mLength.L0 = ((length % 10) / 1) + '0';
		}
		void LLL::clear() {
			mLength.L2 = '0'; 
			mLength.L1 = '0'; 
			mLength.L0 = '0';
		}
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLL& lll) {
			is >> lll.mLength.L2;
			is >> lll.mLength.L1;
			is >> lll.mLength.L0;
			return is;
		}
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLL& lll) {
			os << lll.mLength.L2;
			os << lll.mLength.L1;
			os << lll.mLength.L0;
			return os;
		}
	}
}
