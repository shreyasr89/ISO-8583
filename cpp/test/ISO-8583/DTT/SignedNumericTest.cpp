#include <iostream>
#include <stdexcept>
using namespace std;

#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#include "ISO-8583/DTT/SignedNumeric.h"
#include "SignedNumericTest.h"


namespace ISO_8583 {
	namespace DTT {
		SignedNumericTest::SignedNumericTest(const std::string& name) : CppUnit::TestCase(name) {
		}
		SignedNumericTest::~SignedNumericTest() {
		}
		void SignedNumericTest::testSignedNumeric() {
			assert(sizeof(SignedNumeric<1>) == 1 + 1);
			assert(sizeof(SignedNumeric<2>) == 1 + 2);
			assert(sizeof(SignedNumeric<3>) == 1 + 3);
			assert(sizeof(SignedNumeric<4>) == 1 + 4);
			assert(sizeof(SignedNumeric<5>) == 1 + 5);
			assert(sizeof(SignedNumeric<6>) == 1 + 6);
			assert(sizeof(SignedNumeric<7>) == 1 + 7);
			assert(sizeof(SignedNumeric<8>) == 1 + 8);
			string s;

			SignedNumeric<8>		a8;
			SignedNumeric<19>		a19;
			assert(sizeof(a19) == 1 + 19);

			s = a8.str();
			assert(a8.str() == "+00000000");

#if 0
			a19 = LLONG_MAX; // LLONG_MAX = 9223372036854775807i64
			assert(a19.str() == "9223372036854775807");

			a19 = 9999999999;
			assert(a19.toLong() == 9999999999);
#endif

#if 0
			nat8 ll;
			nat8 ull;				
			// LLONG_MAX = 9223372036854775807i64
			ll			 = 9999999999999999999i64;	// should fail at compile time
			ull			 = 9999999999999999999ui64;	// should fail at compile time
#endif

			a8 = 12345678;
			s = a8.str();
			assert(a8.str() == "+12345678");
			assert(a8.toLong() == 12345678);

			a8 = 4433;
			assert(a8.str() == "+00004433");
			assert(a8.toLong() == 4433);

			a8 = 00000004;
			assert(a8.str() == "+00000004");
			assert(a8.toLong() == 4);

			a8 = 02;
			assert(a8.str() == "+00000002");
			assert(a8.toLong() == 2);

			a8 = 9;
			assert(a8.str() == "+00000009");
			assert(a8.toLong() == 9);

			a8 = -12345678;
			assert(a8.str() == "-12345678");
			assert(a8.toLong() == -12345678);

			a8 = -4433;
			assert(a8.str() == "-00004433");
			assert(a8.toLong() == -4433);

			a8 = -00000004;
			assert(a8.str() == "-00000004");
			assert(a8.toLong() == -4);

			a8 = -02;
			assert(a8.str() == "-00000002");
			assert(a8.toLong() == -2);

			a8 = -9;
			assert(a8.str() == "-00000009");
			assert(a8.toLong() == -9);

			try {
				a8 = "123456790";
				assert("overflow_error" == 0);
			}
			catch (overflow_error e) {
			}
			try {
				a8 = +123456790;
				assert("overflow_error" == 0);
			}
			catch (overflow_error e) {
			}
			try {
				a8 = -123456790;
				assert("overflow_error" == 0);
			}
			catch (overflow_error e) {
			}
			try {
				a8 = "1234567h";
				assert("invalid_argument" == 0);
			}
			catch (invalid_argument e) {
			}
			try {
				a8 = "1234567 ";
				assert("invalid_argument" == 0);
			}
			catch (invalid_argument e) {
			}
			try {
				a8 = "1234567%";
				assert("invalid_argument" == 0);
			}
			catch (invalid_argument e) {
			}
		}
		void SignedNumericTest::setUp() {
		}
		void SignedNumericTest::tearDown() {
		}
		CppUnit::Test* SignedNumericTest::suite() {
			CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("SignedNumericTest");
			CppUnit_addTest(pSuite, SignedNumericTest, testSignedNumeric);
			return pSuite;
		}
	}
}
