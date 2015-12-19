/*
 * AmountReconciliation.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef ISO_8583_DTE_AMOUNTRECONCILIATION_H_
#define  ISO_8583_DTE_AMOUNTRECONCILIATION_H_

#if VRM_CB2A == 150
#include "ISO-8583/DTT/Packed.h"
#elif VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
#endif
#include "ISO-8583/DTE/DataElement.h"

/*
CB2A		5 cf norme ISO 8583 n 12
ISO8583		5 X Amount reconciliation n 16
*/

namespace ISO_8583 {
	namespace DTE {

		class DTE_API_SCOPE AmountReconciliation :
#if VRM_CB2A == 150
			public Packed<12>,
#elif VRM_ISO_8583 == 2003
			public Numeric<16>,
#endif
			public DataElement {
		public:
			static const int  bitno = 5;

		public:
			AmountReconciliation() {
			}
			virtual ~AmountReconciliation() {
			}
			virtual void serialize(ostream& os);
			virtual void serialize(istream& is);
			virtual string toString() const;
		};
	}
}

#endif
