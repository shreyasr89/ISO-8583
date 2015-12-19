/*
 * SignedNumeric.h
 *
 *  Created on: 24 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef SIGNEDNUMERIC_H_
#define SIGNEDNUMERIC_H_

#include "ISO-8583/DTT/Numeric.h"

namespace ISO_8583 {
	namespace DTT {
		template<int precision, int scale = 0>
		class DTT_API_SCOPE SignedNumeric : public Numeric < precision, scale > {
		private:
			static const char PLUS = '+';
			static const char MINUS = '-';
			static const char CREDIT = 'C';
			static const char DEBIT = 'D';
			char	sign;	// '+' for 'C' as CREDIT for positive value 
							// '-' for 'D' as DEBIT  for negative value

		public:
			explicit SignedNumeric() : sign(PLUS) {
			}
			~SignedNumeric() {
			}
			int64_t  toLong() const;
			string	str() const;

			SignedNumeric& operator=(const string& value);
			SignedNumeric& operator=(const char* value);
			SignedNumeric& operator=(int64_t value);

			template<int precizion, int skale>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, SignedNumeric<precizion, skale>& n);
			template<int precizion, int skale>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const SignedNumeric<precizion, skale>& n);
		};
	}
}
#endif
