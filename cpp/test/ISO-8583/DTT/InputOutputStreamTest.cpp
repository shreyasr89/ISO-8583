/*
 * InputOutputStreamTest.cpp
 *
 *  Created on: 14 juil. 2015
 *      Author: FrancisANDRE
 */

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"
#include "Poco/Buffer.h"
using namespace Poco;

#include "ISO-8583/DTT/BinaryInputStream.h"
#include "ISO-8583/DTT/BinaryOutputStream.h"
#include "ISO-8583/DTT/BinaryInputOutputStream.h"
#include "InputOutputStreamTest.h"


namespace ISO_8583 {
	namespace DTT {
		InputOutputStreamTest::InputOutputStreamTest(const std::string& name) : CppUnit::TestCase(name) {
		}
		InputOutputStreamTest::~InputOutputStreamTest() {
		}
		void InputOutputStreamTest::testInputStream() {
			int no = 0;
			int1 c = ++no;
			int2 s = ++no;
			int4 i = ++no;
			int8 l = ++no;
			nat1 uc = ++no;
			nat2 us = ++no;
			nat4 ui = ++no;
			nat8 ul = ++no;

			Poco::Buffer<char> buffer(256);
			char* p = buffer.begin();

			*(int1*)p = c; p += sizeof(int1);
			*(int2*)p = s; p += sizeof(int2);
			*(int4*)p = i; p += sizeof(int4);
			*(int8*)p = l; p += sizeof(int8);
			*(nat1*)p = uc; p += sizeof(nat1);
			*(nat2*)p = us; p += sizeof(nat2);
			*(nat4*)p = ui; p += sizeof(nat4);
			*(nat8*)p = ul; p += sizeof(nat8);

			BinaryInputStream reader(buffer.begin(), buffer.size(), StreamByteOrder::NATIVE_BYTE_ORDER);
			no = 0;
			reader >> c; assert(c == ++no);
			reader >> s;assert(s == ++no);
			reader >> i;assert(i == ++no);
			reader >> l;assert(l == ++no);
			reader >> uc;assert(uc == ++no);
			reader >> us;assert(us == ++no);
			reader >> ui;assert(ui == ++no);
			reader >> ul;assert(ul == ++no);
			assert(reader.position() == p - buffer.begin());
			reader.flip();
			assert(reader.limit() == p - buffer.begin());
			assert(reader.position() == 0);

		}
		void InputOutputStreamTest::testOutputStream() {
			int no = 0;
			int1 c = ++no;
			int2 s = ++no;
			int4 i = ++no;
			int8 l = ++no;
			nat1 uc = ++no;
			nat2 us = ++no;
			nat4 ui = ++no;
			nat8 ul = ++no;

			Poco::Buffer<char> buffer(256);
			BinaryOutputStream writer(buffer.begin(), buffer.size(), StreamByteOrder::NATIVE_BYTE_ORDER);
			writer << c; 
			writer << s;
			writer << i;
			writer << l;
			writer << uc;
			writer << us;
			writer << ui;
			writer << ul;
			char* p = buffer.begin();
			
			no = 0;
			p = buffer.begin();
			assert(++no == *(int1*)p); p += sizeof(int1);
			assert(++no == *(int2*)p); p += sizeof(int2);
			assert(++no == *(int4*)p); p += sizeof(int4);
			assert(++no == *(int8*)p); p += sizeof(int8);
			assert(++no == *(nat1*)p); p += sizeof(nat1);
			assert(++no == *(nat2*)p); p += sizeof(nat2);
			assert(++no == *(nat4*)p); p += sizeof(nat4);
			assert(++no == *(nat8*)p); p += sizeof(nat8);

			assert(writer.position() == p - buffer.begin());
		}
		void InputOutputStreamTest::testInputOutputStream() {
			Poco::Buffer<char> buffer(256);
			memset(buffer.begin(), 0xFF, buffer.size());
			BinaryInputOutputStream rw(buffer.begin(), buffer.size());
			int no = 0;
			int1 c = ++no;
			int2 s = ++no;
			int4 i = ++no;
			int8 l = ++no;
			nat1 uc = ++no;
			nat2 us = ++no;
			nat4 ui = ++no;
			nat8 ul = ++no;

			rw << c; 
			rw << s;
			rw << i;
			rw << l;
			rw << uc;
			rw << us;
			rw << ui;
			rw << ul;

			char* p = buffer.begin();
			no = 0;
			const char* UN		= "\x01";
			const char* DEUX	= "\x00\x02";
			const char* TROIS	= "\x00\x00\x00\x03";
			const char* QUATRE	= "\x00\x00\x00\x00\x00\x00\x00\x04";
			const char* CINQ	= "\x05";
			const char* SIX		= "\x00\x06";
			const char* SEPT	= "\x00\x00\x00\x07";
			const char* HUIT	= "\x00\x00\x00\x00\x00\x00\x00\x08";

			assert(string(p, sizeof(int1)) == string(UN, sizeof(int1))); p += sizeof(int1);
			assert(string(p, sizeof(int2)) == string(DEUX, sizeof(int2))); p += sizeof(int2);
			assert(string(p, sizeof(int4)) == string(TROIS, sizeof(int4))); p += sizeof(int4);
			assert(string(p, sizeof(int8)) == string(QUATRE,  sizeof(int8))); p +=  sizeof(int8);
			
			
			assert(string(p, sizeof(nat1)) == string(CINQ, sizeof(nat1))); p += sizeof(nat1);
			assert(string(p, sizeof(nat2)) == string(SIX, sizeof(nat2))); p += sizeof(nat2);
			assert(string(p, sizeof(nat4)) == string(SEPT, sizeof(nat4))); p += sizeof(nat4);
			assert(string(p, sizeof(nat8)) == string(HUIT,  sizeof(nat8))); p +=  sizeof(nat8);

			rw.flip();

			no = c = s = i = l = uc = us = ui = ul = 0;

			rw >> c; 
			rw >> s;
			rw >> i;
			rw >> l;
			rw >> uc;
			rw >> us;
			rw >> ui;
			rw >> ul;
			assert(c == ++no);
			assert(s == ++no);
			assert(i == ++no);
			assert(l == ++no);
			assert(uc == ++no);
			assert(us == ++no);
			assert(ui == ++no);
			assert(ul == ++no);
		}
		void InputOutputStreamTest::setUp() {
		}
		void InputOutputStreamTest::tearDown() {
		}
		CppUnit::Test* InputOutputStreamTest::suite() {
			CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("InputOutputStreamTest");
			CppUnit_addTest(pSuite, InputOutputStreamTest, testInputStream);
			CppUnit_addTest(pSuite, InputOutputStreamTest, testOutputStream);
			CppUnit_addTest(pSuite, InputOutputStreamTest, testInputOutputStream);
			return pSuite;
		}

}
}
