/*
 * LLNumeric.h
 *
 *  Created on: 24 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef LLNUMERIC_H_
#define LLNUMERIC_H_

#include "ISO-8583/DTT/LL.h"
#include "ISO-8583/DTT/Numeric.h"

namespace ISO_8583 {
	namespace DTT {

		template<int precision, int scale = 0>
		class DTT_API_SCOPE LLNumeric : public LL, public Numeric < precision, scale > {
		private:
			typedef	LL									LengthType;
			typedef	Numeric<precision, scale>			DataType;

		public:
			explicit LLNumeric() { }
			~LLNumeric() { }

			LLNumeric& operator=(const string& value);
			LLNumeric& operator=(const char* value);
			LLNumeric& operator=(nat8 value);
			bool operator==(const char* value) const;
			string str() const;

			template<int precizion, int skale>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLNumeric<precizion, skale>& lln);
			template<int precizion, int skale>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLNumeric<precizion, skale>& lln);

			byte* data(int offset = 0) const {
				byte* b = (byte*)static_cast<const DataType*>(this);
				return b + offset;
			}
		};
	}
}
#endif
