/*
 * Bitmaps.cpp
 *
 *  Created on: 8 juin 2015
 *      Author: FrancisANDRE
 */

#include <stdexcept>
#include <climits>
#include <cstdint>
#include <cstdarg>
#include <cassert>
using namespace std;

#include "ISO-8583/DTT/Bitmaps.h"

namespace ISO_8583 {
	namespace DTT {
		Bitmaps::Bitmap::Bitmap() {
			reset();
		}
		Bitmaps::Bitmap::Bitmap(int number, ...) {
			reset();
			va_list vl;
			va_start(vl, number);
			for (int no = 0; no < number; no++) {
				byte val = va_arg(vl, int);
				set(val);
			}
			va_end(vl);
		}
		Bitmaps::Bitmap::~Bitmap() {
		}
		void Bitmaps::Bitmap::set(byte bitno, bool value) {
			if (1 <= bitno && bitno <= 64)
				bitset<64>::set(64 - bitno, value);
			else
				throw out_of_range("bitno out of [1,64]");
		}

		void Bitmaps::Bitmap::set(nat8 value) {
			static_cast<bitset < 64 >&>(*this) = value;
		}

		bool Bitmaps::Bitmap::get(byte bitno) const {
			if (1 <= bitno && bitno <= 64)
				return static_cast<const bitset<64>&>(*this)[64 - bitno];
			else
				throw out_of_range("bitno out of [1,64]");
		}

		DTT_API_SCOPE InputStream& operator>>(InputStream& is, Bitmaps::Bitmap& bitmap) {
#if 0
			union {
				nat8		val64;
				byte		byte8[sizeof(nat8)];
			};
#endif
			nat8 valuen;
			is >> valuen;
			bitmap.set(valuen);
			return is;
		}
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Bitmaps::Bitmap& bitmap) {
#if 0
			union {
				nat8	val64;
				byte	byte8[sizeof(nat8)];
			};
			nat8 value = bitmap.toLong();
			nat8 valuen = hton(value);
			val64 = valuen;
#endif
			os << bitmap.toLong();
			return os;
		}

		// ===============================================================================

		Bitmaps::Bitmaps() {
		}
		Bitmaps::Bitmaps(int number, ...) {
			va_list vl;
			va_start(vl, number);
			for (int no = 0; no < number; no++) {
				byte val = va_arg(vl, int);
				set(val);
			}
			va_end(vl);
		}
		Bitmaps::~Bitmaps() {
		}
		void Bitmaps::set(byte bitno, bool value) {
			if ((64 * 0) + 1 <= bitno && bitno <= 1 * 64)
				bitmap1.set((byte)(bitno - 64 * 0), value);
			else
				// second bitmap
				if ((64 * 1) + 1 <= bitno && bitno <= 2 * 64) {
				if (value == true)
					bitmap1.set((byte)(1 - 64 * 1), true);		// set continuation bit

				bitmap2.set((byte)(bitno - 64 * 1), value);

				if (value == false && bitmap2.none())
					bitmap1.set((byte)(1 - 64 * 1), false);		// unset continuation bit

				}
				else
					// third bitmap
					if ((64 * 2) + 1 <= bitno && bitno <= 3 * 64)  {
				if (value == true)
					bitmap2.set((byte)(1 - 64 * 1), true);		// set continuation bit

				bitmap3.set((byte)(bitno - 64 * 2), value);

				if (value == false && bitmap2.none())
					bitmap2.set((byte)(1 - 64 * 1), false);		// unset continuation bit
					}
					else
						throw out_of_range("bitno out of [1,192]");
		}

		void Bitmaps::set(nat8 bitno1, nat8 bitno2, nat8 bitno3) {
			bitmap1.set(bitno1);
			bitmap2.set(bitno2);
			bitmap3.set(bitno3);
		}

		bool Bitmaps::get(byte bitno) const {
			if ((64 * 0) + 1 <= bitno && bitno <= 1 * 64)
				return bitmap1.get((byte)(bitno - 64 * 0));
			else
				if ((64 * 1) + 1 <= bitno && bitno <= 2 * 64)
					return bitmap2.get((byte)(bitno - 64 * 1));
				else
					if ((64 * 2) + 1 <= bitno && bitno <= 3 * 64)
						return bitmap3.get((byte)(bitno - 64 * 2));
					else
						throw out_of_range("bitno out of [1,192]");
		}
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, Bitmaps& bitmaps) {
			is >> bitmaps.bitmap1;
			if (bitmaps.bitmap1.get(1)) {
				assert(bitmaps.bitmap2.any());
				is >> bitmaps.bitmap2;
				if (bitmaps.bitmap2.get(1)) {
					assert(bitmaps.bitmap3.any());
					is >> bitmaps.bitmap3;
				}
			}
			return is;
		}
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Bitmaps& bitmaps) {
			os << bitmaps.bitmap1;
			if (bitmaps.bitmap1.get(1)) {
				os << bitmaps.bitmap2;
				if (bitmaps.bitmap2.none())
					throw logic_error("invalid bitmap");
				if (bitmaps.bitmap2.get(1)) {
					os << bitmaps.bitmap3;
					if (bitmaps.bitmap3.none())
						throw logic_error("invalid bitmap");
				}
			}
			return os;
		}
	}
}
