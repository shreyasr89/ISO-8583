/*
 * DataElement.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/DataElement.h"

namespace ISO_8583 {
	namespace DTE {
#if 0
		ostream& operator<<(ostream& os, const DataElement& de) {
			return os;
		}
		istream& operator>>(istream& is, DataElement& de) {
			return is;
		}
		void DataElement::serialize(ostream& os) {
			os << *this;
		}
		void DataElement::serialize(istream& is) {
			is >> *this;
		}
#endif

	}
}