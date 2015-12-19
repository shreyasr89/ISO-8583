/*
 * LLL.h
 *
 *  Created on: 29 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef LLL_H_
#define LLL_H_
#include <iostream>
using  std::istream;
using  std::ostream;

#include "ISO-8583-DTT.h"

namespace ISO_8583 {
	namespace DTT {
		class InputStream;
		class OutputStream;

		class DTT_API_SCOPE LLL {
		private:
			typedef struct {
				char	L2;
				char	L1;
				char	L0;
			} LengthType;

			LengthType	mLength;

		protected:
			LLL() {
				mLength.L2 = '0';
				mLength.L1 = '0';
				mLength.L0 = '0';
			}
			~LLL() {
				mLength.L2 = '0';
				mLength.L1 = '0';
				mLength.L0 = '0';
			}

		public:
			short	length() const;
			void	length(short length);
			void	clear();

			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLL& lll);
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLL& lll);
		};
	}
}
#endif
