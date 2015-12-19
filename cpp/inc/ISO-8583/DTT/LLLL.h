/*
 * LLLL.h
 *
 *  Created on: 29 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef LLLL_H_
#define LLLL_H_

#include "ISO-8583-DTT.h"

namespace ISO_8583 {
	namespace DTT {
		class InputStream;
		class OutputStream;

		class DTT_API_SCOPE LLLL {
		private:
			typedef struct {
				char	L3;
				char	L2;
				char	L1;
				char	L0;
			} LengthType;

			LengthType	mLength;

		protected:
			LLLL() {
				mLength.L3 = '0';
				mLength.L2 = '0';
				mLength.L1 = '0';
				mLength.L0 = '0';
			}
			~LLLL() {
				mLength.L3 = '0';
				mLength.L2 = '0';
				mLength.L1 = '0';
				mLength.L0 = '0';
			}

		public:
			short	length() const;
			void	length(short length);
			void	clear();

			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, LLLL& llll);
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const LLLL& llll);
		};
	}
}

#endif
