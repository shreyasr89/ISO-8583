/*
 * TLVBinary.h
 *
 *  Created on: 1 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef BINARYTLV_H_
#define BINARYTLV_H_
#include <cassert>
#include <iostream>
using  std::istream;
using  std::ostream;

#include "ISO-8583/DTE/ISO-8583-DTE.h"

namespace ISO_8583 {
	namespace DTE {

#pragma pack(push, 1) // exact fit - no padding
		/*
		padding = align - (offset & (align - 1)) = (-offset) & (align - 1)
		new offset = (offset + align - 1) & ~(align - 1)
		*/
		class DTE_API_SCOPE BinaryTLV {
		private:
			typedef	unsigned short	TagType;
			typedef	byte			Lengthtype;

			TagType					T;
			Lengthtype				L;

		public:
			explicit BinaryTLV(TagType tag, Lengthtype length) : T(tag), L(length) {
				assert(sizeof(BinaryTLV) == sizeof(TagType) + sizeof(Lengthtype));
			}
			~BinaryTLV() {
			}

			const TagType&		tag() const		{ return T; }
			const Lengthtype&	length() const	{ return L; }

			void		hostToNetwork()	{ T = hton(T); }
			void		networkToHost()	{ T = ntoh(T); }

			friend DTE_API_SCOPE ostream& operator<<(ostream& os, const BinaryTLV& a);
			friend DTE_API_SCOPE istream& operator>>(istream& is, BinaryTLV& a);
		};
#pragma pack(pop) //back to whatever the previous packing mode was 
	}
}
#endif
