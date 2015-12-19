#include <iostream>
#include <stdexcept>
using namespace std;

#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#include "ISO-8583/DTT/LLAlphaNumericSpecial.h"
#include "LLAlphaNumericSpecialTest.h"


namespace ISO_8583 {
	namespace DTT {
		LLAlphaNumericSpecialTest::LLAlphaNumericSpecialTest(const std::string& name) : CppUnit::TestCase(name) {
		}
		LLAlphaNumericSpecialTest::~LLAlphaNumericSpecialTest() {
		}
		void LLAlphaNumericSpecialTest::testLLAlphaNumericSpecial() {
			LLAlphaNumericSpecial<8>		a8;
			assert(sizeof(a8) == sizeof(LL) + sizeof(AlphaNumericSpecial<8>));

			assert(a8.str() == "");
			assert(a8.length() == 0);

			a8 = "abcdefgh";
			assert(a8.str() == "abcdefgh");
			assert(a8.length() == strlen("abcdefgh"));

			a8 = "1BCD2";
			assert(a8.str() == "1BCD2");
			assert(a8.length() == strlen("1BCD2"));

			a8 = "1bc ";
			assert(a8.str() == "1bc ");
			assert(a8.length() == strlen("1bc "));

			a8 = "&'(-+$!<";
			assert(a8.str() == "&'(-+$!<");
			assert(a8.length() == strlen("&'(-+$!<"));

			try {
				a8 = "abcdefghi";		// overflow
				assert("overflow_error" == 0);
			}
			catch (overflow_error e) {
			}
			try {
				a8 = "123" "\13" "5678";
				assert("invalid_argument" == 0);
			}
			catch (invalid_argument e) {
			}
		}
		void LLAlphaNumericSpecialTest::setUp() {
		}
		void LLAlphaNumericSpecialTest::tearDown() {
		}
		CppUnit::Test* LLAlphaNumericSpecialTest::suite() {
			CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("LLAlphaNumericSpecialTest");
			CppUnit_addTest(pSuite, LLAlphaNumericSpecialTest, testLLAlphaNumericSpecial);
			return pSuite;
		}
	}
}
