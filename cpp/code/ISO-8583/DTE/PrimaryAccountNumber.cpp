/*
 * PrimaryAccountNumber.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/PrimaryAccountNumber.h"

namespace ISO_8583 {
	namespace DTE {

		SERIALIZE(PrimaryAccountNumber)

		string PrimaryAccountNumber::toString() const {
			return static_cast<const BaseType&>(*this).str();
		}
	}
}