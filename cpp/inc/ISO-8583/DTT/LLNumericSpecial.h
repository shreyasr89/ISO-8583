/*
 * LLNumericSpecial.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef LLNUMERICSPECIAL_H_
#define LLNUMERICSPECIAL_H_

#include "ISO-8583/DTT/LL.h"
#include "ISO-8583/DTT/NumericSpecial.h"

namespace ISO_8583 {
	namespace DTT {

		template<int precision, int scale = 0>
		class DTT_API_SCOPE LLNumericSpecial : public LL, public NumericSpecial < precision, scale > {
		private:
			typedef	LL									LengthType;
			typedef	NumericSpecial<precision, scale>	DataType;

		public:
			explicit LLNumericSpecial() {
			}
			~LLNumericSpecial() {
			}

			LLNumericSpecial& operator=(const string& value);
			LLNumericSpecial& operator=(const char* value);
			LLNumericSpecial& operator=(nat8 value);

			template<int precizion, int skale>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLNumericSpecial<precizion, skale>& lln);
			template<int precizion, int skale>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLNumericSpecial<precizion, skale>& lln);

			byte* data() const {
				byte* b = (byte*)static_cast<const DataType*>(this);
				return b;
			}
		};

	}
}

#endif
