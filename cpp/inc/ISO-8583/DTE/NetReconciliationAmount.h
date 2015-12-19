/*
 * NetReconciliationAmount.h
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef AMOUNTNETRECONCILIATION_H_
#define AMOUNTNETRECONCILIATION_H_

#if STD_CB2A == 150
#include "ISO-8583/DTT/AlphaNumeric.h"
#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/AlphaNumericSpace.h"
#endif
#include "ISO-8583/DTE/DataElement.h"

namespace ISO_8583 {
	namespace DTE {

		class DTE_API_SCOPE NetReconciliationAmount :
#if STD_CB2A == 150
			public AlphaNumeric<12>,
#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
			public AlphaNumericSpace<12>,
#endif
			public DataElement {
		public:
			static const int  bitno = 22;
		public:
			NetReconciliationAmount() {
			}
			~NetReconciliationAmount() {
			}
			NetReconciliationAmount& operator=(const char* value) {
				return *this;
			}
			virtual void decode(InputStream& is);
			virtual void encode(OutputStream& os);
			virtual string toString() const;
		};
	}
}

#endif
