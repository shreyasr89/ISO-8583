#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#include "ISO-8583/DTT/BinaryOutputStream.h"
#include "ISO-8583/DTT/AlphaNumericSpace.h"
#include "AlphaNumericSpaceTest.h"


namespace ISO_8583 {
	namespace DTT {
		AlphaNumericSpaceTest::AlphaNumericSpaceTest(const std::string& name) : CppUnit::TestCase(name) {
		}
		AlphaNumericSpaceTest::~AlphaNumericSpaceTest() {
		}
		void AlphaNumericSpaceTest::testAlphaNumericSpace() {
			AlphaNumericSpace<8>		a8;
			assert(sizeof(a8) == 8);

			assert(a8.str() == "        ");

			a8 = "a";
			assert(a8.str() == "a       ");

			a8 = "abcdefgh";
			assert(a8.str() == "abcdefgh");

			a8 = "abcd5678";
			assert(a8.str() == "abcd5678");

			a8 = "abcd56";
			assert(a8.str() == "abcd56  ");

			a8 = "1234";
			assert(a8.str() == "1234    ");

			try {
				a8 = "abcdefghi";		// overflow
				assert("invalid_argument" == 0);
			}
			catch (overflow_error e) {
			}
			try {
				a8 = "abcd567!";		// ! not an alphanumericspace
				assert("invalid_argument" == 0);
			}
			catch (invalid_argument e) {
			}
			try {
				a8 = "abcd567" "\01";	// 0x01 not an alphanumericspace
				assert("invalid_argument" == 0);
			}
			catch (invalid_argument e) {
			}
		}
		void AlphaNumericSpaceTest::testStream() {
			BinaryOutputStream	ss(256);
			AlphaNumericSpace<8>		a8;
			a8 = " ";
			ss << a8;
			ss.flip();
			assert(ss.str(8) == "        ");

			ss.clear();
			a8 = "1";
			ss << a8;
			ss.flip();
			assert(ss.str(8) == "1       ");

			a8 = "A";
			ss.clear();
			ss << a8;
			ss.flip();
			assert(ss.str(8) == "A       ");

			a8 = "abcd12";
			ss.clear();
			ss << a8;
			ss.flip();
			assert(ss.str(8) == "abcd12  ");

			a8 = "abc  fg1";
			ss.clear();
			ss << a8;
			ss.flip();
			assert(ss.str(8) == "abc  fg1");
		}
		void AlphaNumericSpaceTest::setUp() {
		}
		void AlphaNumericSpaceTest::tearDown() {
		}
		CppUnit::Test* AlphaNumericSpaceTest::suite() {
			CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("AlphaNumericSpaceTest");
			CppUnit_addTest(pSuite, AlphaNumericSpaceTest, testAlphaNumericSpace);
			CppUnit_addTest(pSuite, AlphaNumericSpaceTest, testStream);
			return pSuite;
		}
	}
}
