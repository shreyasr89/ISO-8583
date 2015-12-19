/*
 * TransactionLocalTime.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef TRANSACTIONLOCALTIME_H_
#define TRANSACTIONLOCALTIME_H_

#include "ISO-8583/DTE/DataElement.h"
#include "ISO-8583/DTT/Hour.h"
#include "ISO-8583/DTT/Minute.h"
#include "ISO-8583/DTT/Second.h"

/*
CB2A				12 Temps local de la transaction hhmmss n 6
ISO-8583-1987		12 time local transaction hhmmss n 6
*/
namespace ISO_8583 {
	namespace DTE {
		class DTE_API_SCOPE TransactionLocalTime :
			public Numeric<6>,
			public DataElement {
			struct Time {
				Hour hour;
				Minute minute;
				Second second;
			};
			typedef Numeric<6> BaseType;
		public:
			static const int  bitmapno = 12;
			
		public:
			TransactionLocalTime() {}
			virtual ~TransactionLocalTime() {}

			TransactionLocalTime& operator=(const string& value);
			TransactionLocalTime& operator=(const char* value);
			TransactionLocalTime& operator=(nat8 value) ;
			virtual int bitno() const { return bitmapno; }
			virtual void decode(InputStream& is);
			virtual void encode(OutputStream& os);
			virtual string toString() const;

		public:
			Hour& hour()				{ 
				Time* time = (Time*)static_cast<BaseType*>(this); 
				return time->hour;
			}
			Minute& minute()			{ 
				Time* time = (Time*)static_cast<BaseType*>(this); 
				return time->minute;
			}
			Second& second()			{ 
				Time* time = (Time*)static_cast<BaseType*>(this); 
				return time->second;
			}
			Hour& HH()				{ 
				Time* time = (Time*)static_cast<BaseType*>(this); 
				return time->hour;
			}
			Minute& MM()			{ 
				Time* time = (Time*)static_cast<BaseType*>(this); 
				return time->minute;
			}
			Second& SS()			{ 
				Time* time = (Time*)static_cast<BaseType*>(this); 
				return time->second;
			}

			const Hour& hour()	const 			{ 
				Time* time = (Time*)static_cast<const BaseType*>(this); 
				return time->hour;
			}
			const Minute& minute()	const 		{ 
				Time* time = (Time*)static_cast<const BaseType*>(this); 
				return time->minute;
			}
			const Second& second()	const 		{ 
				Time* time = (Time*)static_cast<const BaseType*>(this); 
				return time->second;
			}
			const Hour& HH()	const 			{ 
				Time* time = (Time*)static_cast<const BaseType*>(this); 
				return time->hour;
			}
			const Minute& MM()	const 		{ 
				Time* time = (Time*)static_cast<const BaseType*>(this); 
				return time->minute;
			}
			const Second& SS()	const 		{ 
				Time* time = (Time*)static_cast<const BaseType*>(this); 
				return time->second;
			}
		};
	}
}


#endif
