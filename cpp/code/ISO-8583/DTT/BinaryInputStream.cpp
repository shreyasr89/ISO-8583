/*
 * BinaryInputStream.cpp
 *
 *  Created on: 14 juil. 2015
 *      Author: FrancisANDRE
 */

#include <cstring>
#include "ISO-8583/DTT/BinaryInputStream.h"

namespace ISO_8583 {
	namespace DTT {
		BinaryInputStream::BinaryInputStream(int length, StreamByteOrder byteOrder) :
			Buffer(length) {
#if defined(ARCH_BIG_ENDIAN)
			flipbytes = (byteOrder == StreamByteOrder::LITTLE_ENDIAN_BYTE_ORDER);
#else
			flipbytes = (byteOrder == StreamByteOrder::BIG_ENDIAN_BYTE_ORDER);
#endif
		}
		BinaryInputStream::BinaryInputStream(char* buffer, int length, StreamByteOrder byteOrder) :
			Buffer(buffer, length) {
#if defined(ARCH_BIG_ENDIAN)
			flipbytes = (byteOrder == StreamByteOrder::LITTLE_ENDIAN_BYTE_ORDER);
#else
			flipbytes = (byteOrder == StreamByteOrder::BIG_ENDIAN_BYTE_ORDER);
#endif
		}
		BinaryInputStream::~BinaryInputStream() {
		}
		BinaryInputStream& BinaryInputStream::operator >> (bool& value) {
			if (position() + sizeof(bool) > limit())
				throw out_of_range(exception(sizeof(bool)));
			value = *(bool*)here(); position() += sizeof(bool);
			return *this;
		}
		BinaryInputStream& BinaryInputStream::operator >> (char& value) {
			if (position() + sizeof(char) > limit())
				throw out_of_range(exception(sizeof(char)));
			value = *(char*)here(); position() += sizeof(char);
			return *this;
		}
		BinaryInputStream& BinaryInputStream::operator >> (int1& value) {
			if (position() + sizeof(int1) > limit())
				throw out_of_range(exception(sizeof(int1)));
			value = *(int1*)here(); position() += sizeof(int1);
			return *this;
		}
		BinaryInputStream& BinaryInputStream::operator >> (nat1& value) {
			if (position() + sizeof(nat1) > limit())
				throw out_of_range(exception(sizeof(nat1)));
			value = *(nat1*)here(); position() += sizeof(nat1);
			return *this;
		}
		BinaryInputStream& BinaryInputStream::operator >> (int2& value) {
			if (position() + sizeof(int2) > limit())
				throw out_of_range(exception(sizeof(int2)));
			value = *(int2*)here(); position() += sizeof(int2);
			if (flipbytes)
				value = ntoh(value);
			return *this;
		}
		BinaryInputStream& BinaryInputStream::operator >> (nat2& value) {
			if (position() + sizeof(nat2) > limit())
				throw out_of_range(exception(sizeof(nat2)));
			value = *(nat2*)here(); position() += sizeof(nat2);
			if (flipbytes)
				value = ntoh(value);
			return *this;
		}
		BinaryInputStream& BinaryInputStream::operator >> (int4& value) {
			if (position() + sizeof(int4) > limit())
				throw out_of_range(exception(sizeof(int4)));
			value = *(int4*)here(); position() += sizeof(int4);
			if (flipbytes)
				value = ntoh(value);
			return *this;
		}
		BinaryInputStream& BinaryInputStream::operator >> (nat4& value) {
			if (position() + sizeof(nat4) > limit())
				throw out_of_range(exception(sizeof(nat4)));
			value = *(nat4*)here(); position() += sizeof(nat4);
			if (flipbytes)
				value = ntoh(value);
			return *this;
		}
		BinaryInputStream& BinaryInputStream::operator >> (int8& value) {
			if (position() + sizeof(int8) > limit())
				throw out_of_range(exception(sizeof(int8)));
			value = *(int8*)here(); position() += sizeof(int8);
			if (flipbytes)
				value = ntoh(value);
			return *this;
		}
		BinaryInputStream& BinaryInputStream::operator >> (nat8& value) { 
			if (position() + sizeof(nat8) > limit())
				throw out_of_range(exception(sizeof(nat8)));
			value = *(nat8*)here(); position() += sizeof(nat8);
			if (flipbytes)
				value = ntoh(value);
			return *this;
		}
		BinaryInputStream& BinaryInputStream::operator >> (float& value) {
			if (position() + sizeof(float) > limit())
				throw out_of_range(exception(sizeof(float)));
			value = *(float*)here(); position() += sizeof(float);
			return *this;
		}
		BinaryInputStream& BinaryInputStream::operator >> (double& value) {
			if (position() + sizeof(double) > limit())
				throw out_of_range(exception(sizeof(double)));
			value = *(double*)here(); position() += sizeof(double);
			return *this;
		}


		BinaryInputStream& BinaryInputStream::read(char* buffer, int size) {
			if (position() + size > limit())
				throw out_of_range(exception(size));
			memcpy(buffer, here(), size); position() += size;

			return *this;
		}
		const string BinaryInputStream::exception(int size) const {
			string message = "cannot get object of size ";
			message += to_string(size);
			message += " from buffer " + toString();
			return message;
		}
	}
}
