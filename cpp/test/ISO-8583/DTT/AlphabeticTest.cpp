#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#include "ISO-8583/DTT/BinaryOutputStream.h"
#include "ISO-8583/DTT/BinaryInputOutputStream.h"
#include "ISO-8583/DTT/Alphabetic.h"
#include "AlphabeticTest.h"


namespace ISO_8583 {
	namespace DTT {
		AlphabeticTest::AlphabeticTest(const std::string& name) : CppUnit::TestCase(name) {
		}
		AlphabeticTest::~AlphabeticTest() {
		}
		void AlphabeticTest::testAlphabetic() {
			assert(sizeof(Alphabetic<8>) == 8);
			Alphabetic<8>		a8;

			assert(a8.str() == "        ");

			a8 = "abcdefgh";
			assert(a8.str() == "abcdefgh");

			a8 = "ABCDefgh";
			assert(a8.str() == "ABCDefgh");

			try {
				a8 = "abcdefghi";		// overflow
				assert(false);
			}
			catch (overflow_error e) {
			}
			catch (...) {
				assert(false);
			}
			try {
				a8 = "abc efgh";		// space not alphanumeric
				assert("invalid_argument" == 0);
			}
			catch (invalid_argument e) {
			}
			catch (...) {
				assert(false);
			}
			try {
				a8 = "1bc234%";			// % not alphanumeric
				assert("invalid_argument" == 0);
			}
			catch (invalid_argument e) {
			}
			catch (...) {
				assert(false);
			}
		}
		void AlphabeticTest::testStream() {
			Alphabetic<8>		a8;
			BinaryInputOutputStream	ss(256);

			ss.clear();
			a8 = "a";
			ss << a8;
			ss.flip();
			assert(ss.str(8) == "a       ");

			ss.clear();
			a8 = "abcd";
			ss << a8;
			ss.flip();
			assert(ss.str(8) == "abcd    ");

			ss.clear();
			a8 = "abcdefgh";
			ss << a8;
			ss.flip();
			assert(ss.str(8) == "abcdefgh");
		}
		void AlphabeticTest::setUp() {
		}
		void AlphabeticTest::tearDown() {
		}
		CppUnit::Test* AlphabeticTest::suite() {
			CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("AlphabeticTest");
			CppUnit_addTest(pSuite, AlphabeticTest, testAlphabetic);
			return pSuite;
		}
	}
}
