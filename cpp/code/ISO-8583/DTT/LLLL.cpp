/*
 * LLLL.cpp
 *
 *  Created on: 29 mai 2015
 *      Author: FrancisANDRE
 */

#include <iostream>
using namespace std;
#include "ISO-8583/DTT/LLLL.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		short	LLLL::length() const {
			return (mLength.L3 - '0') * 1000 + (mLength.L2 - '0') * 100 + (mLength.L1 - '0') * 10 +( mLength.L0 - '0') * 1;
		}
		void LLLL::length(short length) {
			mLength.L3 = (length / 1000) + '0'; 
			mLength.L2 = ((length % 1000) / 100) + '0'; 
			mLength.L1 = ((length % 100) / 10) + '0'; 
			mLength.L0 = ((length % 10) / 1) + '0';
		}
		void LLLL::clear() {
			mLength.L3 = '0'; 
			mLength.L2 = '0'; 
			mLength.L1 = '0'; 
			mLength.L0 = '0';
		}
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLLL& llll) {
			is >> llll.mLength.L3;
			is >> llll.mLength.L2;
			is >> llll.mLength.L1;
			is >> llll.mLength.L0;
			return is;
		}
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLLL& llll) {
			os << llll.mLength.L3;
			os << llll.mLength.L2;
			os << llll.mLength.L1;
			os << llll.mLength.L0;
			return os;
		}
	}
}
