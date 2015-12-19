/*
 * LLLLBytes.h
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef LLLLBYTES_H_
#define LLLLBYTES_H_

#include <iostream>
using  std::ostream;
using  std::istream;
#include <string>
using  std::string;


#include "ISO-8583/DTT/LLLL.h"
#include "ISO-8583/DTT/Bytes.h"

namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		class DTT_API_SCOPE LLLLBytes : public LLLL, public Bytes < sizeb > {
		private:
			typedef	Bytes < sizeb > DataType;

		public:
			explicit LLLLBytes() {
			}
			~LLLLBytes() {
			}

			LLLLBytes& operator=(const string& value);
			LLLLBytes& operator=(const char* value);

			template<int size>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLLLBytes<size>& llllb);
			template<int size>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLLLBytes<size>& llllb);

			byte* data(int offset = 0) const {
				byte* b = (byte*)static_cast<const DataType*>(this);
				return b + offset;
			}
		};
	}
}
#endif
