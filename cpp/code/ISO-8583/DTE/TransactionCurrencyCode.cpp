/*
 * TransactionCurrencyCode.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/TransactionCurrencyCode.h"

namespace ISO_8583 {
namespace DTE {
		SERIALIZE(TransactionCurrencyCode)
		string TransactionCurrencyCode::toString() const {
			string s(str());
			return s;
		}
}
}
