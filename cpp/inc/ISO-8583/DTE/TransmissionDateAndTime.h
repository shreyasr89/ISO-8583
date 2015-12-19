/*
 * TransmissionDateAndTime.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef TRANSMISSIONDATEANDTIME_H_
#define TRANSMISSIONDATEANDTIME_H_

#include "ISO-8583/DTT/Numeric.h"
#include "ISO-8583/DTE/DataElement.h"
/*
ISO-8583-2003		7 Date and time transmission MMDDhhmmss n 10
*/

namespace ISO_8583 {
	namespace DTE {
		class DTE_API_SCOPE TransmissionDateAndTime :
			public Numeric<10>,
			public DataElement {

		public:
			typedef Numeric<10> DataType;
			static const int  bitmapno = 7;

		public:
			TransmissionDateAndTime();
			virtual ~TransmissionDateAndTime();

			TransmissionDateAndTime& operator=(const char* value) {
				static_cast<DataType&>(*this) = value; return *this;
			}

			virtual int bitno() const { return bitmapno;  }
			virtual void decode(InputStream& is);
			virtual void encode(OutputStream& os);
			virtual string toString() const;
		};
	}
}


#endif
