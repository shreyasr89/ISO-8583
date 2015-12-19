/*
 * DateAndTimeLocalTransaction.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef DATEANDTIMELOCALTRANSACTION_H_
#define DATEANDTIMELOCALTRANSACTION_H_

#include "ISO-8583/DTT/Numeric.h"
#include "ISO-8583/DTE/DataElement.h"

/*
CB2A		150		12 Heure locale de la transaction			 hhmmss n 6
ISO-8583	1993	12 X Date and time local transaction   YYMMDDhhmmss n 12
ISO-8583	2003	12 X Date and time local transaction CCYYMMDDhhmmss n 14
*/
namespace ISO_8583 {
	namespace DTE {

		class DTE_API_SCOPE DateAndTimeLocalTransaction :
#if STD_CB2A == 150
			public Numeric<6>,
#elif STD_ISO_8583 == 1993
			public Numeric<12>,
#elif STD_ISO_8583 == 2003
			public Numeric<14>,
#endif
			public DataElement {
		public:
#if	STD_CB2A == 150 
			typedef  Numeric<6>		BaseType;
#elif STD_ISO_8583 == 1993
			typedef  Numeric<12>	BaseType;
#elif STD_ISO_8583 == 2003
			typedef  Numeric<14>	BaseType;
#endif
			static const int  bitno = 12;

		public:
			DateAndTimeLocalTransaction();
			virtual ~DateAndTimeLocalTransaction();

			DateAndTimeLocalTransaction& operator=(const char* value) {
				static_cast<BaseType&>(*this) = value; return *this;
			}
			virtual void decode(InputStream& is);
			virtual void encode(OutputStream& os);
			virtual string toString() const;
		};
	}
}


#endif
