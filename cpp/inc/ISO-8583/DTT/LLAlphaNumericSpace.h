/*
 * LLAlphaNumericSpace.h
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef LLALPHANUMERICSPACE_H_
#define LLALPHANUMERICSPACE_H_
#include <string>
using  std::string;


#include "ISO-8583/DTT/LL.h"
#include "ISO-8583/DTT/AlphaNumericSpace.h"

namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		class DTT_API_SCOPE LLAlphaNumericSpace : public LL, public AlphaNumericSpace < sizeb > {
		private:
			typedef	AlphaNumericSpace < sizeb > DataType;

		public:
			explicit LLAlphaNumericSpace() {
			}
			~LLAlphaNumericSpace() {
			}

			LLAlphaNumericSpace& operator=(const string& value);
			LLAlphaNumericSpace& operator=(const char* value);
			LLAlphaNumericSpace& operator=(nat8 value);
			string str() const;

			template<int size>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLAlphaNumericSpace<size>& llans);
			template<int size>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLAlphaNumericSpace<size>& llans);

			byte* data(int offset = 0) const {
				byte* b = (byte*)static_cast<const DataType*>(this);
				return b + offset;
			}
		};
	}
}
#endif
