/*
 * LLLBytes.h
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef LLLBYTES_H_
#define LLLBYTES_H_
#include <iostream>
using  std::ostream;
using  std::istream;
#include <string>
using  std::string;


#include "ISO-8583/DTT/LLL.h"
#include "ISO-8583/DTT/Bytes.h"

namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		class DTT_API_SCOPE LLLBytes : public LLL, public Bytes < sizeb > {
		private:
			typedef	Bytes < sizeb > DataType;

		public:
			explicit LLLBytes() {
			}
			~LLLBytes() {
			}

			LLLBytes& operator=(const string& value);
			LLLBytes& operator=(const char* value);

			template<int size>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLLBytes<size>& lllb);
			template<int size>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLLBytes<size>& lllb);

			byte* data(int offset = 0) const {
				byte* b = (byte*)static_cast<const DataType*>(this);
				return b + offset;
			}
		};
	}
}
#endif
