/*
 * ExpirationDate.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef EXPIRATIONDATE_H_
#define EXPIRATIONDATE_H_

#include "ISO-8583/DTE/DataElement.h"
#include "ISO-8583/DTT/Year.h"
#include "ISO-8583/DTT/Month.h"

/*
CB2A				14 Date d'expiration AAMM n 4
ISO-8583-1987		14 Date expiration YYMM n 4
ISO-8583-2003		14 Date expiration YYMM n 4
*/
namespace ISO_8583 {
	namespace DTE {
		class DTE_API_SCOPE ExpirationDate :
			public Numeric<4>,
			public DataElement {
		private:
			typedef Numeric<4>	BaseType;
			struct Date {
				Year year;
				Month month;
			};
		public:
			static const int  bitmapno = 14;
			
		public:
			ExpirationDate() {}
			virtual ~ExpirationDate() {}

			ExpirationDate& operator=(const string& value);
			ExpirationDate& operator=(const char* value);
			ExpirationDate& operator=(nat8 value) ;
			virtual int bitno() const { return bitmapno; }
			virtual void decode(InputStream& is);
			virtual void encode(OutputStream& os);
			virtual string toString() const;

			Year& year()			{ 
				Date* date = (Date*)static_cast<BaseType*>(this); 
				return date->year;
			}
			Month& month()				{ 
				Date* date = (Date*)static_cast<BaseType*>(this); 
				return date->month;
			}
			Year& YY()			{ 
				Date* date = (Date*)static_cast<BaseType*>(this); 
				return date->year;
			}
			Month& MM()				{ 
				Date* date = (Date*)static_cast<BaseType*>(this); 
				return date->month;
			}
			const Year& year() const 			{ 
				Date* date = (Date*)static_cast<const BaseType*>(this); 
				return date->year;
			}
			const Month& month() const 	{ 
				Date* date = (Date*)static_cast<const BaseType*>(this); 
				return date->month;
			}
			const Year& YY() const 			{ 
				Date* date = (Date*)static_cast<const BaseType*>(this); 
				return date->year;
			}
			const Month& MM() const 	{ 
				Date* date = (Date*)static_cast<const BaseType*>(this); 
				return date->month;
			}
		};
	}
}

#endif
