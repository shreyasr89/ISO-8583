#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#include "ISO-8583/DTT/BinaryOutputStream.h"
#include "ISO-8583/DTT/LLAlphabetic.h"
#include "LLAlphabeticTest.h"


namespace ISO_8583 {
	namespace DTT {
		LLAlphabeticTest::LLAlphabeticTest(const std::string& name) : CppUnit::TestCase(name) {
		}
		LLAlphabeticTest::~LLAlphabeticTest() {
		}
		void LLAlphabeticTest::testLLAlphabeticTest() {
			//
			// LLAlphabetic<1000>		a1000;
			// test checking the maximum size allowed, i.e 999
			// but this does not work on VS2013
			//

			LLAlphabetic<8>		a8;
			assert(sizeof(a8) == sizeof(LL) + sizeof(Alphabetic<8>));

			assert(a8.str() == "");
			assert(a8.length() == 0);

			a8 = "";
			assert(a8.str() == "");
			assert(a8.length() == strlen(""));

			a8 = "abc";
			assert(a8.str() == "abc");
			assert(a8.str() != "abc ");
			assert(a8.length() == strlen("abc"));

			a8 = "abcdefgh";
			assert(a8.str() == "abcdefgh");
			assert(a8.str() != "abcdefgh ");
			assert(a8.length() == strlen("abcdefgh"));

			try {
				a8 = "abcdefghi";		// overflow
				assert(false);
			}
			catch (overflow_error e) {
			}
			try {
				a8 = "abcdefg1";		// 1 not alphabetic
				assert("invalid_argument" == 0);
			}
			catch (const NotAnAlphabetic&) {
			}
			try {
				a8 = "abcdefg ";		// space not alphabetic
				assert("invalid_argument" == 0);
			}
			catch (const NotAnAlphabetic&) {
			}
			try {
				a8 = "abcdefg!";		// ! not alphabetic
				assert("invalid_argument" == 0);
			}
			catch (const NotAnAlphabetic&) {
			}
			try {
				a8 = "abcdefg" "\01";	// 0x01 not alphabetic
				assert("invalid_argument" == 0);
			}
			catch (const NotAnAlphabetic&) {
			}
		}
		void LLAlphabeticTest::testStream() {
			LLAlphabetic<8>		a8;
			BinaryOutputStream		ss(256);

			ss.clear();
			a8 = "a";
			ss << a8;
			ss.flip();
#ifdef	CB2A_1_5_0
			assert(ss.at(0) == 0x01);
			assert(ss.at(1) == 'a');
#elif	ISO_8583_2003
			assert(ss.asstring(3) == "01" "a");
#endif

			ss.clear();
			a8 = "abcd";
			ss << a8;
			ss.flip();
#ifdef	CB2A_1_5_0
			assert((byte)ss.at(0) == 0x04);
			assert((byte)ss.at(1) == 'a');
			assert((byte)ss.at(2) == 'b');
			assert((byte)ss.at(3) == 'c');
			assert((byte)ss.at(4) == 'd');
#elif	ISO_8583_2003
			assert(ss.asstring(6) == "04" "abcd");
#endif

			ss.clear();
			a8 = "abcdefgh";
			ss << a8;
			ss.flip();
#ifdef	CB2A_1_5_0
			assert(ss.at(0) == 0x08);
			assert(s.substr(1) == "abcdefgh");
#elif	ISO_8583_2003
			assert(ss.asstring(10) == "10" "abcdefgh");
#endif
		}
		void LLAlphabeticTest::setUp() {
		}
		void LLAlphabeticTest::tearDown() {
		}
		CppUnit::Test* LLAlphabeticTest::suite() {
			CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("LLAlphabeticTest");
			CppUnit_addTest(pSuite, LLAlphabeticTest, testLLAlphabeticTest);
			CppUnit_addTest(pSuite, LLAlphabeticTest, testStream);
			return pSuite;
		}
	}
}
