#ifndef _BYTE_H_
#define _BYTE_H_

#include <iostream>
using  std::istream;
using  std::ostream;

#include "ISO-8583-DTT.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		class DTT_API_SCOPE Byte {
		private:
			byte	mbyte = 0;
		public:
			explicit Byte(byte byte = 0) : mbyte(byte) {}
			Byte(byte leftNibble, byte rightNibble);

			const byte	leftNibble() const			{ return mbyte >> 4; }
			const byte	rightNibble() const			{ return mbyte & 0x0F; }
			void		leftNibble(byte nibble)		{ mbyte |= (nibble << 4); }
			void		rightNibble(byte nibble)	{ mbyte |= (nibble & 0x0F); }

			const byte	byte() const				{ return mbyte; }
			//		void		byte(byte byte) 		{ mbyte = byte; }

			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, Byte& b) {
				is >> b.mbyte;
				return is;
			}
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Byte& b) {
				os << b.mbyte;
				return os;
			}
		};
	}
}
#endif