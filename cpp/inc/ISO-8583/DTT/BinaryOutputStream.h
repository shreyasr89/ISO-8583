/*
 * BinaryOutputStream.h
 *
 *  Created on: 14 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef BINARYOUTPUTSTREAM_H_
#define BINARYOUTPUTSTREAM_H_

#include "ISO-8583/DTT/ISO-8583-DTT.h"
#include "ISO-8583/DTT/Buffer.h"
#include "ISO-8583/DTT/Platform.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
namespace DTT {

class DTT_API_SCOPE BinaryOutputStream : public OutputStream, public virtual Buffer {
private:
	bool flipbytes;

public:
	BinaryOutputStream(int length, StreamByteOrder byteOrder = StreamByteOrder::NETWORK_BYTE_ORDER);
	BinaryOutputStream(char* buffer, int length, StreamByteOrder byteOrder = StreamByteOrder::NETWORK_BYTE_ORDER);
	virtual ~BinaryOutputStream();

	BinaryOutputStream& operator << (bool value);
	BinaryOutputStream& operator << (char value);
	BinaryOutputStream& operator << (int1 value);
	BinaryOutputStream& operator << (int2 value);
	BinaryOutputStream& operator << (int4 value);
	BinaryOutputStream& operator << (int8 value);
	BinaryOutputStream& operator << (nat1 value);
	BinaryOutputStream& operator << (nat2 value);
	BinaryOutputStream& operator << (nat4 value);
	BinaryOutputStream& operator << (nat8 value);
	BinaryOutputStream& operator << (float value);
	BinaryOutputStream& operator << (double value);


	BinaryOutputStream& operator << (const Buffer& buffer);
	BinaryOutputStream& operator << (const std::string& value);
	BinaryOutputStream& operator << (const char* value);

	BinaryOutputStream& put(const char* bytes, int length);
	BinaryOutputStream& write(const char* bytes, int length);

	BinaryOutputStream& put(int position, char b);
	BinaryOutputStream& put(int position, unsigned char b);
	BinaryOutputStream& put(int position, int2 s);
	BinaryOutputStream& put(int position, nat2 s);
	BinaryOutputStream& put(int position, int4 i);
	BinaryOutputStream& put(int position, nat4 i);

private:
	const string exception(int size) const;

};

}
}

#endif
