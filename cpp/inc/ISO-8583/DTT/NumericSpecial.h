/*
 * PackedSpecial.h
 *
 *  Created on: 24 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef PACKEDSPECIAL_H_
#define PACKEDSPECIAL_H_

#include "ISO-8583/DTT/Numeric.h"

namespace ISO_8583 {
	namespace DTT {

		template<int precision, int scale = 0>
		class DTT_API_SCOPE NumericSpecial : public Numeric < precision, scale > {
		private:
			typedef	Numeric < precision,  scale> DataType;
		public:
			explicit NumericSpecial() {	}
			~NumericSpecial() {	}

			nat8	toLong() const;
			string		str() const;

			NumericSpecial& operator=(const string& value);
			NumericSpecial& operator=(const char* value);

			template<int precizion, int skale>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, NumericSpecial<precizion, skale>& ns);
			template<int precizion, int skale>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const NumericSpecial<precizion, skale>& ns);
		};
	}
}
#endif
