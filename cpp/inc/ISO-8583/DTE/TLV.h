/*
 * TLV.h
 *
 *  Created on: 18 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef TLV_H_
#define TLV_H_
#include <cassert>
#include <iostream>
using  std::istream;
using  std::ostream;

#include "ISO-8583-DTE.h"

#include "ISO-8583/DTT/AlphaNumeric.h"
#include "ISO-8583/DTT/Numeric.h"
#include "ISO-8583/DTT/Zoned.h"

namespace ISO_8583 {
	namespace DTE {
		/*
		padding = align - (offset & (align - 1)) = (-offset) & (align - 1)
		new offset = (offset + align - 1) & ~(align - 1)
		*/
#pragma pack(push, 1) // exact fit - no padding

		class DTE_API_SCOPE TLV {
		public:
			typedef	AlphaNumeric<2>				TagType;
			typedef	Zoned<2>					LengthType;

		private:
			TagType				T;
			LengthType			L;

		public:
			TLV(const TagType& tag, const LengthType& length) : T(tag), L(length) {
				assert(sizeof(TLV) == 4);
			}
			~TLV() {
			}

			const TagType&		tag() const		{ return T; }
			const LengthType&	length() const	{ return L; }

			friend DTE_API_SCOPE ostream& operator<<(ostream& os, const TLV& a);
			friend DTE_API_SCOPE istream& operator>>(istream& is, TLV& a);
		};
#pragma pack(pop) //back to whatever the previous packing mode was 
	}
}
#endif
