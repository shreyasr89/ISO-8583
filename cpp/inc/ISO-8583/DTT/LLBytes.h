/*
 * LLBytes.h
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef LLBYTES_H_
#define LLBYTES_H_

#include <iostream>
using  std::ostream;
using  std::istream;
#include <string>
using  std::string;


#include "ISO-8583/DTT/LL.h"
#include "ISO-8583/DTT/Bytes.h"

namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		class DTT_API_SCOPE LLBytes : public LL, public Bytes < sizeb > {
		private:
			typedef	Bytes < sizeb > DataType;

		public:
			explicit LLBytes() {
			}
			~LLBytes() {
			}

			LLBytes& operator=(const string& value);
			LLBytes& operator=(const char* value);

			template<int size>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLBytes<size>& llb);
			template<int size>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLBytes<size>& llb);

			byte* data() const;
			byte* check(size_t sz) const;
		};
	}
}
#endif
