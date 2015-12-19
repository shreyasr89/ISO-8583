#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#include "ISO-8583/DTT/BinaryOutputStream.h"
#include "ISO-8583/DTT/AlphaNumericSpecial.h"
#include "AlphaNumericSpecialTest.h"


namespace ISO_8583 {
	namespace DTT {
		AlphaNumericSpecialTest::AlphaNumericSpecialTest(const std::string& name) : CppUnit::TestCase(name) {
		}
		AlphaNumericSpecialTest::~AlphaNumericSpecialTest() {
		}
		void AlphaNumericSpecialTest::testAlphaNumericSpecial() {
			AlphaNumericSpecial<8>		a8;
			assert(sizeof(a8) == 8);

			assert(a8.str() == "        ");

			a8 = "abcdefgh";
			assert(a8.str() == "abcdefgh");

			a8 = "1BCD2fgh";
			assert(a8.str() == "1BCD2fgh");

			a8 = "1bc 2fgh";
			assert(a8.str() == "1bc 2fgh");

			a8 = "&'(-+$!<";
			assert(a8.str() == "&'(-+$!<");

			try {
				a8 = "abcdefghi";		// overflow
				assert("invalid_argument" == 0);
			}
			catch (overflow_error e) {
			}
			try {
				a8 = "123" "\13" "5678"; // 0x13 not alphanumericspecial
				assert("invalid_argument" == 0);
			}
			catch (invalid_argument e) {
			}
		}
		void AlphaNumericSpecialTest::testStream() {
			BinaryOutputStream	ss(256);
			AlphaNumericSpecial<8>		a8;
			a8 = "";
			ss << a8;
			ss.flip();
			assert(ss.str(8) == "        ");

			a8 = "A";
			ss << a8;
			ss.flip();
			assert(ss.str(8) == "A       ");

			a8 = "1";
			ss << a8;
			ss.flip();
			assert(ss.str(8) == "1       ");

			a8 = "%";
			ss << a8;
			ss.flip();
			assert(ss.str(8) == "%       ");

			a8 = "abc1";
			ss << a8;
			ss.flip();
			assert(ss.str(8) == "abc1    ");

			a8 = "abc  fg1";
			ss << a8;
			ss.flip();
			assert(ss.str(8) == "abc  fg1");

			a8 = "abc%!fg1";
			ss << a8;
			ss.flip();
			assert(ss.str(8) == "abc%!fg1");
		}
		void AlphaNumericSpecialTest::setUp() {
		}
		void AlphaNumericSpecialTest::tearDown() {
		}
		CppUnit::Test* AlphaNumericSpecialTest::suite() {
			CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("AlphaNumericSpecialTest");
			CppUnit_addTest(pSuite, AlphaNumericSpecialTest, testAlphaNumericSpecial);
			CppUnit_addTest(pSuite, AlphaNumericSpecialTest, testStream);
			return pSuite;
		}
	}
}
