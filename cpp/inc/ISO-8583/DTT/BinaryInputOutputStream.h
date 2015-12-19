/*
 * BinaryInputOutputStream.h
 *
 *  Created on: 15 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef BinaryInputOutputStream_H_
#define BinaryInputOutputStream_H_
#include "ISO-8583/DTT/BinaryInputStream.h"
#include "ISO-8583/DTT/BinaryOutputStream.h"

namespace ISO_8583 {
	namespace DTT {

		class DTT_API_SCOPE BinaryInputOutputStream : public BinaryInputStream, public BinaryOutputStream {
		public:
			BinaryInputOutputStream(int length, StreamByteOrder byteOrder = StreamByteOrder::NETWORK_BYTE_ORDER);
			BinaryInputOutputStream(char* buffer, int length, StreamByteOrder byteOrder = StreamByteOrder::NETWORK_BYTE_ORDER);
			virtual ~BinaryInputOutputStream();
		};

	}
}

#endif
