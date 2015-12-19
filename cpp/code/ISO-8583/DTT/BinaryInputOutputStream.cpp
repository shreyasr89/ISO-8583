/*
 * InputStreamOutputStream.cpp
 *
 *  Created on: 15 juil. 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTT/BinaryInputOutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		BinaryInputOutputStream::BinaryInputOutputStream(int length, StreamByteOrder byteOrder) :
			BinaryInputStream(length), BinaryOutputStream(length, byteOrder), Buffer(length) {
		}
		BinaryInputOutputStream::BinaryInputOutputStream(char* buffer, int length, StreamByteOrder byteOrder) :
			BinaryInputStream(buffer, length), BinaryOutputStream(buffer, length, byteOrder), Buffer(buffer, length) {
		}
		BinaryInputOutputStream::~BinaryInputOutputStream() {
		}
	}
}
