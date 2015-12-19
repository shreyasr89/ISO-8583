/*
 * TransactionProcessingFeeAmount.cpp
 *
 *  Created on: 18 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/TransactionProcessingFeeAmount.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(TransactionProcessingFeeAmount)
			string TransactionProcessingFeeAmount::toString() const {
			string s(str());
			return s;
		}
	}
}
