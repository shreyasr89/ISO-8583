/*
 * CarTLV.cpp
 *
 *  Created on: 18 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/TLV.h"

namespace ISO_8583 {
	namespace DTE {
		DTE_API_SCOPE istream& operator>>(istream& is, TLV& tlvs) {
			return is;
		}

		DTE_API_SCOPE ostream& operator<<(ostream& os, const TLV& tlvs) {
			return os;
		}

	}
}