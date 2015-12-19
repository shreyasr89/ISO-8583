/*
 * LLAlphabetic.h
 *
 *  Created on: 20 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef LLALPHABETIC_H_
#define LLALPHABETIC_H_

#include <iostream>
using  std::ostream;
using  std::istream;
#include <string>
using  std::string;

#include "ISO-8583/DTT/LL.h"
#include "ISO-8583/DTT/Alphabetic.h"

namespace ISO_8583 {
	namespace DTT {
		template<int sizeb>
		class DTT_API_SCOPE LLAlphabetic : public LL, public Alphabetic < sizeb > {
		private:
			typedef	Alphabetic < sizeb > DataType;

		public:
			explicit LLAlphabetic() {
			}
			~LLAlphabetic() {
			}

			LLAlphabetic& operator=(const string& value);
			LLAlphabetic& operator=(const char* value);
			string str() const;


			template<int size>
			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLAlphabetic<size>& lla);
			template<int size>
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLAlphabetic<size>& lla);

			byte* data(size_t size, int offset = 0) const {
				byte* b = (byte*)static_cast<const DataType*>(this);
				return b + offset;
			}
			//		typedef char size_gt_999[size > 999 ? 1 : -1];
		};
	}
}
#endif
