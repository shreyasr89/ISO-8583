#include <iostream>
#include <stdexcept>
using namespace std;

#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#include "ISO-8583/DTT/Numeric.h"
#include "NumericTest.h"
#include <limits.h>

namespace ISO_8583 {
	namespace DTT {
		NumericTest::NumericTest(const std::string& name) : CppUnit::TestCase(name) {
		}
		NumericTest::~NumericTest() {
		}
		void NumericTest::testNumeric() {
			assert(sizeof(Numeric<1>) == 1);
			assert(sizeof(Numeric<2>) == 2);
			assert(sizeof(Numeric<3>) == 3);
			assert(sizeof(Numeric<4>) == 4);
			assert(sizeof(Numeric<5>) == 5);
			assert(sizeof(Numeric<6>) == 6);
			assert(sizeof(Numeric<7>) == 7);
			assert(sizeof(Numeric<8>) == 8);

			Numeric<8>		a8;
			Numeric<19>		a19;
			assert(sizeof(a8) == 8);

			assert(a8.str() == "00000000");
			assert(a8 == "0");

			a19 = LLONG_MAX; // LLONG_MAX = 9223372036854775807i64
			assert(a19.str() == "9223372036854775807");

			a19 = 9999999999;
			assert(a19 == 9999999999);

#if 0
			nat8 ll;
			nat8 ull;				
			// LLONG_MAX = 9223372036854775807i64
			ll			 = 9999999999999999999i64;	// should fail at compile time
			ull			 = 9999999999999999999ui64;	// should fail at compile time
#endif

			a8 = "12345678";
			assert(a8.str() == "12345678");
			assert(a8 == 12345678);

			a8 = "4433";
			assert(a8.str() == "00004433");
			assert(a8 == 4433);

			a8 = "00000004";
			assert(a8.str() == "00000004");
			assert(a8 == 4);

			a8 = "02";
			assert(a8.str() == "00000002");
			assert(a8 == 2);

			a8 = "9";
			assert(a8.str() == "00000009");
			assert(a8 == 9);

			a8 = 12345678;
			assert(a8.str() == "12345678");
			assert(a8 == 12345678);

			a8 = 4433;
			assert(a8.str() == "00004433");
			assert(a8 == 4433);

			a8 = 00000004;
			assert(a8.str() == "00000004");
			assert(a8 == 4);

			a8 = 02;
			assert(a8.str() == "00000002");
			assert(a8 == 2);

			a8 = 9;
			assert(a8.str() == "00000009");
			assert(a8 == 9);

			try {
				a8 = "123456790";
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
		void NumericTest::setUp() {
		}
		void NumericTest::tearDown() {
		}
		CppUnit::Test* NumericTest::suite() {
			CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("NumericTest");
			CppUnit_addTest(pSuite, NumericTest, testNumeric);
			return pSuite;
		}
	}
}
