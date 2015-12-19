/*
 * BinaryOutputStream.cpp
 *
 *  Created on: 14 juil. 2015
 *      Author: FrancisANDRE
 */

#include <cstring>
#include "ISO-8583/DTT/BinaryOutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		BinaryOutputStream::BinaryOutputStream(int length, StreamByteOrder byteOrder) : Buffer(length) {
#if defined(ARCH_BIG_ENDIAN)
			flipbytes = (byteOrder == StreamByteOrder::LITTLE_ENDIAN_BYTE_ORDER);
#else
			flipbytes = (byteOrder == StreamByteOrder::BIG_ENDIAN_BYTE_ORDER);
#endif
		}
		BinaryOutputStream::BinaryOutputStream(char* buffer, int length, StreamByteOrder byteOrder) : Buffer(buffer, length) {
#if defined(ARCH_BIG_ENDIAN)
			flipbytes = (byteOrder == StreamByteOrder::LITTLE_ENDIAN_BYTE_ORDER);
#else
			flipbytes = (byteOrder == StreamByteOrder::BIG_ENDIAN_BYTE_ORDER);
#endif
		}
		BinaryOutputStream::~BinaryOutputStream() {
		}
		BinaryOutputStream& BinaryOutputStream::operator << (bool value) {
			if (position() + sizeof(value) > limit())
				throw out_of_range(exception(sizeof(value)));
			*(bool*)here() = value; position() += sizeof(value);
			return *this;
		}
		BinaryOutputStream& BinaryOutputStream::operator << (char value) {
			if (position() + sizeof(value) > limit())
				throw out_of_range(exception(sizeof(value)));
			*(char*)here() = value; position() += sizeof(value);
			return *this;
		}
		BinaryOutputStream& BinaryOutputStream::operator << (int1 value) {
			if (position() + sizeof(value) > limit())
				throw out_of_range(exception(sizeof(value)));
			*(int1*)here() = value; position() += sizeof(value);
			return *this;
		}
		BinaryOutputStream& BinaryOutputStream::operator << (int2 value) {
			if (position() + sizeof(value) > limit())
				throw out_of_range(exception(sizeof(value)));
			if (flipbytes)
				value = hton(value);
			*(int2*)here() = value; position() += sizeof(value);
			return *this;
		}
		BinaryOutputStream& BinaryOutputStream::operator << (int4 value) {
			if (position() + sizeof(value) > limit())
				throw out_of_range(exception(sizeof(value)));
			if (flipbytes)
				value = hton(value);
			*(int4*)here() = value; position() += sizeof(value);
			return *this;
		}
		BinaryOutputStream& BinaryOutputStream::operator << (int8 value) {
			if (position() + sizeof(value) > limit())
				throw out_of_range(exception(sizeof(value)));
			if (flipbytes)
				value = hton(value);
			*(int8*)here() = value; position() += sizeof(value);
			return *this;
		}
		BinaryOutputStream& BinaryOutputStream::operator << (nat1 value) {
			if (position() + sizeof(value) > limit())
				throw out_of_range(exception(sizeof(value)));
			*(nat1*)here() = value; position() += sizeof(value);
			return *this;
		}
		BinaryOutputStream& BinaryOutputStream::operator << (nat2 value) {
			if (position() + sizeof(value) > limit())
				throw out_of_range(exception(sizeof(value)));
			if (flipbytes)
				value = hton(value);
			*(nat2*)here() = value; position() += sizeof(value);
			return *this;
		}
		BinaryOutputStream& BinaryOutputStream::operator << (nat4 value) {
			if (position() + sizeof(value) > limit())
				throw out_of_range(exception(sizeof(value)));
			if (flipbytes)
				value = hton(value);
			*(nat4*)here() = value; position() += sizeof(value);
			return *this;
		}
		BinaryOutputStream& BinaryOutputStream::operator << (nat8 value) {
			if (position() + sizeof(value) > limit())
				throw out_of_range(exception(sizeof(value)));
			if (flipbytes)
				value = hton(value);
			*(nat8*)here() = value; position() += sizeof(value);
			return *this;
		}
		BinaryOutputStream& BinaryOutputStream::operator << (float value) {
			if (position() + sizeof(value) > limit())
				throw out_of_range(exception(sizeof(value)));
			*(float*)here() = value; position() += sizeof(value);
			return *this;
		}
		BinaryOutputStream& BinaryOutputStream::operator << (double value) {
			if (position() + sizeof(value) > limit())
				throw out_of_range(exception(sizeof(value)));
			*(double*)here() = value; position() += sizeof(value);
			return *this;
		}

		BinaryOutputStream& BinaryOutputStream::operator << (const std::string& value) {
			if (position() + value.size() > limit())
				throw out_of_range(exception(value.size()));
			memcpy(here(), value.data(), value.size()); position() += value.size();
			return *this;
		}
		BinaryOutputStream& BinaryOutputStream::operator << (const char* value) {
			if (position() + strlen(value) > limit())
				throw out_of_range(exception(sizeof(int)));
			memcpy(here(), value, strlen(value)); position() += strlen(value);
			return *this;
		}
		BinaryOutputStream&   BinaryOutputStream::operator <<(const Buffer& buffer) {
			if (position() + buffer.remaining() > limit())
				throw out_of_range(exception(buffer.remaining()));
			memcpy(here(), buffer.data(), buffer.remaining()); 
			position() += buffer.remaining();
			return *this;
		}
		BinaryOutputStream&	BinaryOutputStream::put(int position, char value) {
			checkByteIndex(position);
			if (flipbytes)
				value = hton(value);
			*(byte*)(here() + position) = value;
			return *this;
		}
		BinaryOutputStream&	BinaryOutputStream::put(int position, unsigned char value) {
			checkByteIndex(position);
			if (flipbytes)
				value = hton(value);
			*(byte*)(here() + position) = value;
			return *this;
		}
		BinaryOutputStream&	BinaryOutputStream::put(int position, int2 value) {
			checkShortIndex(position);
			if (flipbytes)
				value = hton(value);
			*(int2*)buffer(position) = value;
			return *this;
		}
		BinaryOutputStream&	BinaryOutputStream::put(int position, nat2 value) {
			checkShortIndex(position);
			if (flipbytes)
				value = hton(value);
			*(nat2*)buffer(position) = value;
			return *this;
		}
		BinaryOutputStream&	BinaryOutputStream::put(int position, int4 value) {
			checkIntIndex(position);
			if (flipbytes)
				value = hton(value);
			*(int4*)buffer(position) = value;
			return *this;
		}
		BinaryOutputStream&	BinaryOutputStream::put(int position, nat4 value) {
			checkIntIndex(position);
			if (flipbytes)
				value = hton(value);
			*(nat4*)buffer(position) = value;
			return *this;
		}
		BinaryOutputStream&	BinaryOutputStream::put(const char*bytes, int length) {
			if (position() + length > limit())
				throw out_of_range(exception(length));
			memcpy(here(), bytes, length); position() += length;
			return *this;
		}
		BinaryOutputStream&	BinaryOutputStream::write(const char*bytes, int length) {
			if (position() + length > limit())
				throw out_of_range(exception(length));
			memcpy(here(), bytes, length); position() += length;
			return *this;
		}
		const string BinaryOutputStream::exception(int size) const {
			string message = "cannot put object of size ";
			message += to_string(size);
			message += " to buffer " + toString();
			return message;
		}
	}
}
