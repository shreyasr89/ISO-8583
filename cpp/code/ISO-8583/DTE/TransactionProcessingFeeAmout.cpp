/*
 * TransactionProcessingFeeAmout.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/TransactionProcessingFeeAmout.h"

namespace ISO_8583 {
namespace DTE {
		SERIALIZE(TransactionProcessingFeeAmout)
		string TransactionProcessingFeeAmout::toString() const {
			string s(str());
			return s;
		}
}
}
