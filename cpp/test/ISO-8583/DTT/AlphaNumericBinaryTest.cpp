#include <iostream>
#include <stdexcept>
using namespace std;

#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#include "ISO-8583/DTT/AlphaNumericBinary.h"
#include "AlphaNumericBinaryTest.h"


namespace ISO_8583 {
	namespace DTT {
		AlphaNumericBinaryTest::AlphaNumericBinaryTest(const std::string& name) : CppUnit::TestCase(name) {
		}
		AlphaNumericBinaryTest::~AlphaNumericBinaryTest() {
		}
		void AlphaNumericBinaryTest::testAlphaNumericBinary() {
			AlphaNumericBinary<8>		a8;
			assert(sizeof(a8) == 8);

			assert(a8.str() == "        ");

			a8 = "a";
			assert(a8.str() == "a       ");

			a8 = "abcdefgh";
			assert(a8.str() == "abcdefgh");

			try {
				a8 = "abcdefghi";
				assert(false);
			}
			catch (invalid_argument e) {
			}
			try {
				a8 = "abcdefg1";
				assert(false);
			}
			catch (invalid_argument e) {
			}
			try {
				a8 = "abcdefg ";
				assert(false);
			}
			catch (invalid_argument e) {
			}
			try {
				a8 = "abcdefg!";
				assert(false);
			}
			catch (invalid_argument e) {
			}
			try {
				a8 = "abcdefg" "\01";
				assert(false);
			}
			catch (invalid_argument e) {
			}
		}
		void AlphaNumericBinaryTest::setUp() {
		}
		void AlphaNumericBinaryTest::tearDown() {
		}
		CppUnit::Test* AlphaNumericBinaryTest::suite() {
			CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("AlphaNumericBinaryTest");
			CppUnit_addTest(pSuite, AlphaNumericBinaryTest, testAlphaNumericBinary);
			return pSuite;
		}
	}
}

