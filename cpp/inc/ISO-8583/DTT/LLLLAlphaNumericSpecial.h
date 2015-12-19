/*
 * LLLLAlphaNumericSpecial.h
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef LLLLALPHANUMERICSPECIAL_H_
#define LLLLALPHANUMERICSPECIAL_H_

#include "ISO-8583/DTT/LLLL.h"
#include "ISO-8583/DTT/AlphaNumericSpecial.h"

namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		class DTT_API_SCOPE LLLLAlphaNumericSpecial : public LLLL, public AlphaNumericSpecial < sizeb > {
		private:
			typedef	AlphaNumericSpecial < sizeb > DataType;

		public:
			explicit LLLLAlphaNumericSpecial() {
			}
			~LLLLAlphaNumericSpecial() {
			}

			LLLLAlphaNumericSpecial& operator=(const string& value);
			LLLLAlphaNumericSpecial& operator=(const char* value);
			LLLLAlphaNumericSpecial& operator=(nat8 value);

			template<int size>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLLLAlphaNumericSpecial<size>& llllans);
			template<int size>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLLLAlphaNumericSpecial<size>& llllans);


			byte* data(int offset = 0) const {
				byte* b = (byte*)static_cast<const DataType*>(this);
				return b + offset;
			}
		};
	}
}
#endif
