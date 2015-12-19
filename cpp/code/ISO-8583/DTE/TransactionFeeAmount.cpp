/*
 * TransactionFeeAmount.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/TransactionFeeAmount.h"

namespace ISO_8583 {
	namespace DTE {
#if STD_CB2A == 150 || STD_ISO_8583 == 1987 
		SERIALIZE(TransactionFeeAmount)
			string TransactionFeeAmount::toString() const {
			string s(str());
			return s;
		}
#endif
	}
}
