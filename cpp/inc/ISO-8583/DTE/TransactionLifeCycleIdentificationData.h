/*
 * TransactionLifeCycleIdentificationData.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef  TRANSACTIONLIFECYCLEIDENTIFICATIONDATA_H_
#define TRANSACTIONLIFECYCLEIDENTIFICATIONDATA_H_

#if STD_CB2A == 150
#include "ISO-8583/DTE/Numeric.h"
#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/AlphaNumericSpecial.h"
#endif
#include "ISO-8583/DTE/DataElement.h"
/*
CB2A		21 cf norme ISO 8583 n 3
ISO8583		21 X Transaction life cycle identification data ans 22
*/
namespace ISO_8583 {
	namespace DTE {

		class DTE_API_SCOPE TransactionLifeCycleIdentificationData :
#if STD_CB2A == 150
			public Numeric<3>,
#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
			public AlphaNumericSpecial<22>,
#endif
			public DataElement {
		public:
			static const int  bitno = 21;

		public:
			TransactionLifeCycleIdentificationData() {
			}
			virtual ~TransactionLifeCycleIdentificationData() {
			}
			virtual void decode(InputStream& is);
			virtual void encode(OutputStream& os);
			virtual string toString() const;
		};
	}
}

#endif
