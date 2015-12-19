#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#include "ISO-8583/DTT/BinaryOutputStream.h"
#include "ISO-8583/DTT/AlphaNumeric.h"
#include "AlphaNumericTest.h"


namespace ISO_8583 {
	namespace DTT {
		AlphaNumericTest::AlphaNumericTest(const std::string& name) : CppUnit::TestCase(name) {
		}
		AlphaNumericTest::~AlphaNumericTest() {
		}
		void AlphaNumericTest::testAlphaNumeric() {
			assert(sizeof(AlphaNumeric<8>) == 8);
			AlphaNumeric<8>		a8;

			assert(a8.str() == "00000000");

			a8 = "abcdefgh";
			assert(a8.str() == "abcdefgh");

			a8 = "1BCD2fgh";
			assert(a8.str() == "1BCD2fgh");

			try {
				a8 = "abcdefghi";		// overflow
				assert(false);
			}
			catch (overflow_error e) {
			}
			try {
				a8 = "1bc 2fgh";		// space not alphanumeric
				assert("invalid_argument" == 0);
			}
			catch (invalid_argument e) {
			}
			try {
				a8 = "1bc234%";			// % not alphanumeric
				assert("invalid_argument" == 0);
			}
			catch (invalid_argument e) {
			}
		}
		void AlphaNumericTest::testStream() {
			AlphaNumeric<8>		a8;
			BinaryOutputStream	ss(256);

			ss.clear();
			a8 = "1";
			ss << a8;
			ss.flip();
			assert(ss.str(8) == "1       ");

			ss.clear();
			a8 = "a2c4";
			ss << a8;
			ss.flip();
			assert(ss.str(8) == "a2c4    ");

			ss.clear();
			a8 = "a2c4e6g8";
			ss << a8;
			ss.flip();
			assert(ss.str(8) == "a2c4e6g8");
		}
		void AlphaNumericTest::setUp() {
		}
		void AlphaNumericTest::tearDown() {
		}
		CppUnit::Test* AlphaNumericTest::suite() {
			CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("AlphaNumericTest");
			CppUnit_addTest(pSuite, AlphaNumericTest, testAlphaNumeric);
			return pSuite;
		}
	}
}
