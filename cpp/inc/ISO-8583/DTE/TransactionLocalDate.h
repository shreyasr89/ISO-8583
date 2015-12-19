/*
 * TransactionLocalDate.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef TRANSACTIONLOCALDATE_H_
#define TRANSACTIONLOCALDATE_H_

#include "ISO-8583/DTE/DataElement.h"
#include "ISO-8583/DTT/Month.h"
#include "ISO-8583/DTT/Day.h"

/*
CB2A		150		13 Date locale de la transaction	MMDD n 4
ISO-8583	1987	13 date local transaction			MMDD n 4
*/
namespace ISO_8583 {
	namespace DTE {
		class DTE_API_SCOPE TransactionLocalDate :
			public Numeric<4>,
			public DataElement {
		private:
			typedef Numeric<4> BaseType;
			struct Date {
				Month month;
				Day day;
			};
		public:
			static const int  bitmapno = 13;
			
		public:
			TransactionLocalDate() {}
			virtual ~TransactionLocalDate() {}

			TransactionLocalDate& operator=(const string& value);
			TransactionLocalDate& operator=(const char* value);
			TransactionLocalDate& operator=(nat8 value) ;
			virtual int bitno() const { return bitmapno; }
			virtual void decode(InputStream& is);
			virtual void encode(OutputStream& os);
			virtual string toString() const;

			Month& month()				{ 
				Date* date = (Date*)static_cast<BaseType*>(this); 
				return date->month;
			}
			Day& day()			{ 
				Date* date = (Date*)static_cast<BaseType*>(this); 
				return date->day;
			}
			Month& MM()				{ 
				Date* date = (Date*)static_cast<BaseType*>(this); 
				return date->month;
			}
			Day& DD()			{ 
				Date* date = (Date*)static_cast<BaseType*>(this); 
				return date->day;
			}
			const Month& month() const 	{ 
				Date* date = (Date*)static_cast<const BaseType*>(this); 
				return date->month;
			}
			const Day& day() const 			{ 
				Date* date = (Date*)static_cast<const BaseType*>(this); 
				return date->day;
			}
			const Month& MM() const 	{ 
				Date* date = (Date*)static_cast<const BaseType*>(this); 
				return date->month;
			}
			const Day& DD() const 			{ 
				Date* date = (Date*)static_cast<const BaseType*>(this); 
				return date->day;
			}
		};
	}
}

#endif
