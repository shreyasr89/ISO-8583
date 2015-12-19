/*
 * BinaryTLVs.cpp
 *
 *  Created on: 1 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/BinaryTLVs.h"

namespace ISO_8583 {
	namespace DTE {
		DTE_API_SCOPE istream& operator>>(istream& is, BinaryTLVs& btlvs) {
			return is;
		}

		DTE_API_SCOPE ostream& operator<<(ostream& os, const BinaryTLVs& btlvs) {
			return os;
		}
	}
}