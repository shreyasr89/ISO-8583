/*
 * LLLAlphaNumeric.h
 *
 *  Created on: 24 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef LLLALPHANUMERIC_H_
#define LLLALPHANUMERIC_H_

#include "ISO-8583/DTT/LLL.h"
#include "ISO-8583/DTT/AlphaNumeric.h"

namespace ISO_8583 {
	namespace DTT {

		template<int sizeb>
		class DTT_API_SCOPE LLLAlphaNumeric : public LLL, public AlphaNumeric < sizeb > {
		private:
			typedef	AlphaNumeric < sizeb > DataType;

		public:
			explicit LLLAlphaNumeric()  {
			}
			~LLLAlphaNumeric() {
			}

			LLLAlphaNumeric& operator=(const string& value);
			LLLAlphaNumeric& operator=(const char* value);
			LLLAlphaNumeric& operator=(nat8 value);
			string str() const;

			template<int size>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLLAlphaNumeric<size>& lllan);
			template<int size>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLLAlphaNumeric<size>& lllan);

			byte* data(int offset = 0) const {
				byte* b = (byte*)static_cast<const DataType*>(this);
				return b + offset;
			}
		};
	}
}
#endif
