/*
 * LL.h
 *
 *  Created on: 29 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef LL_H_
#define LL_H_
#include <iostream>
using  std::istream;
using  std::ostream;

#include "ISO-8583-DTT.h"

namespace ISO_8583 {
	namespace DTT {
		class InputStream;
		class OutputStream;

		class DTT_API_SCOPE LL {
		private:
			typedef struct {
				char	L1;
				char	L0;
			} LengthType;
			LengthType		mLength;

		protected:
			LL() {
				mLength.L1 = '0';
				mLength.L0 = '0';
			}
			~LL() {
				mLength.L1 = '0';
				mLength.L0 = '0';
			}

		public:
			const byte	length() const;
			void		length(byte length);
			void		clear();

			friend DTT_API_SCOPE InputStream&  operator>>(InputStream& is, LL& ll);
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LL& ll);
		};
	}
}

#endif
