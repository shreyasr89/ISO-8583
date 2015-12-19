/*
 * Buffer.cpp
 *
 *  Created on: 14 juil. 2015
 *      Author: FrancisANDRE
 */

#include <cassert>
#include <climits>
#include "ISO-8583/DTT/Buffer.h"

using namespace std;

namespace ISO_8583 {
	namespace DTT {
		const int Buffer::OFFSET = 0;// sizeof(Buffer);

		Buffer::Buffer(int length) :
			mark_(-1), position_(0), limit_(length) {
			assert(length <= USHRT_MAX);
			capacity_ = length;
			owned_ = true;
			if (length > 0)
				buffer_ = new char[length];
		}

		Buffer::Buffer(char* buffer, int length) :
			mark_(-1), position_(0), limit_(length) {
			assert(length <= USHRT_MAX);
			capacity_ = length;
			owned_ = false;
			buffer_ = buffer;
		}

		Buffer::~Buffer() {
			if (owned_)
				delete [] buffer_;
		}
		void Buffer::use(char* buffer, int length) {
			if (owned_)
				delete buffer_;
			mark_ = -1, position_ = 0, limit_ = length;
			assert(length <= USHRT_MAX);
			capacity_ = length;
			owned_ = false;
			buffer_ = buffer;
		}
		void Buffer::take(char* buffer, int length) {
			if (owned_)
				delete buffer_;
			mark_ = -1, position_ = 0, limit_ = length;
			assert(length <= USHRT_MAX);
			capacity_ = length;
			owned_ = true;
			buffer_ = buffer;
		}
		void Buffer::dump(Functor& functor) const {
			const int BYTES_PER_LINE = 32;
			string message;
			int length = remaining();
			message.reserve(4 + (BYTES_PER_LINE * 3) + (BYTES_PER_LINE * 2) + 2);
			if (!message.empty()) message.append("\n");
			unsigned char* base = (unsigned char*)buffer_;
			int addr = 0;
			while (addr < length)
			{
//				message.append(NumberFormatter::formatHex(addr, 4));
				message.append("  ");
				int offset = 0;
				while (addr + offset < length && offset < BYTES_PER_LINE)
				{
//					message.append(NumberFormatter::formatHex(base[addr + offset], 2));
					message.append(string_to_hex(string(base[addr + offset], 2)));
					message.append(offset == 7 ? "  " : " ");
					++offset;
				}
				if (offset < 7) message.append(" ");
				while (offset < BYTES_PER_LINE) { message.append("   "); ++offset; }
				message.append(" ");
				offset = 0;
				while (addr + offset < length && offset < BYTES_PER_LINE)
				{
					unsigned char c = base[addr + offset];
					message += (c >= ' ' && c < 127) ? (char)c : '.';
					++offset;
				}
				functor(message);
				message.clear();
				addr += BYTES_PER_LINE;
			}
		}
		const string Buffer::toString() const {
			string message;
			message += "[";
			message += to_string(mark());
			message += ", ";
			message += to_string(position());
			message += ", ";
			message += to_string(limit());
			message += ", ";
			message += to_string(capacity());
			message += "]";
			return message;
		}

	}
}
