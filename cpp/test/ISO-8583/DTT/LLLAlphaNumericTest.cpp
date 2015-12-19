#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#include "ISO-8583/DTT/BinaryOutputStream.h"
#include "ISO-8583/DTT/LLLAlphaNumeric.h"
#include "LLLAlphaNumericTest.h"


namespace ISO_8583 {
	namespace DTT {
		LLLAlphaNumericTest::LLLAlphaNumericTest(const std::string& name) : CppUnit::TestCase(name) {
		}
		LLLAlphaNumericTest::~LLLAlphaNumericTest() {
		}
		void LLLAlphaNumericTest::testLLLAlphaNumeric() {
			LLLAlphaNumeric<8>		lllan8;
			assert(sizeof(lllan8) == sizeof(LLL) + sizeof(AlphaNumeric<8>));

			assert(lllan8.str() == "");
			assert(lllan8.length() == strlen(""));

			lllan8 = "abcdefgh";
			assert(lllan8.str() == "abcdefgh");
			assert(lllan8.length() == strlen("abcdefgh"));

			lllan8 = "a1c2";
			assert(lllan8.str() == "a1c2");
			assert(lllan8.length() == strlen("a1c2"));

			lllan8 = "1BCD2fgh";
			assert(lllan8.str() == "1BCD2fgh");

			try {
				lllan8 = "abcdefghi";		// overflow
				assert(false);
			}
			catch (overflow_error e) {
			}
			catch (...) {
				assert(false);
			}
			try {
				lllan8 = "1bc 2fgh";		// space not alphanumeric
				assert("invalid_argument" == 0);
			}
			catch (invalid_argument e) {
			}
			try {
				lllan8 = "1bc234%";			// % not alphanumeric
				assert("invalid_argument" == 0);
			}
			catch (invalid_argument e) {
			}
			catch (...) {
				assert(false);
			}
		}
		void LLLAlphaNumericTest::testStream() {
			LLLAlphaNumeric<8>		lllan8;
			BinaryOutputStream		ss(256);
			string			s;

			ss.clear();
			lllan8 = "1";
			assert(lllan8.length() == 1);
			ss << lllan8;
			ss.flip();
			assert(ss.limit() == sizeof(LLL) + strlen("1"));
#ifdef STD_CB2A
			assert(ss.at(0) == 0x00);
			assert(ss.at(1) == 0x01);
#else
			assert(ss.at(0) == '0');
			assert(ss.at(1) == '0');
			assert(ss.at(2) == '1');
#endif

			ss.clear();
			lllan8 = "a2c4";
			assert(lllan8.length() == 4);
			ss << lllan8;
			ss.flip();
			assert(ss.limit() == sizeof(LLL) + strlen("a2c4"));
#ifdef STD_CB2A
			assert(ss.at(0) == 0x00);
			assert(ss.at(1) == 0x04);
#else
			assert(ss.at(0) == '0');
			assert(ss.at(1) == '0');
			assert(ss.at(2) == '4');
#endif
			ss.position() = sizeof(LLL);
			assert(ss.str(4) == "a2c4");

			ss.clear();
			lllan8 = "a2c4e6g8";
			assert(lllan8.length() == 8);
			ss << lllan8;
			ss.flip();
			assert(ss.limit() == sizeof(LLL) + strlen("a2c4e6g8"));
#ifdef STD_CB2A
			assert(ss.at(0) == 0x00);
			assert(ss.at(1) == 0x08);
#else
			assert(ss.at(0) == '0');
			assert(ss.at(1) == '0');
			assert(ss.at(2) == '8');
#endif
			ss.position() = sizeof(LLL);
			assert(ss.str(8) == "a2c4e6g8");

			LLLAlphaNumeric<35>		lllan35;
			ss.clear();
			lllan35 = "1234567890123456";
			assert(lllan35.length() == 16);
			ss << lllan35;
			ss.flip();
			assert(ss.limit() == sizeof(LLL) + strlen("1234567890123456"));
#ifdef STD_CB2A
			assert(ss.at(0) == 0x00);
			assert(ss.at(1) == 0x10);
#else
			assert(ss.at(0) == '0');
			assert(ss.at(1) == '1');
			assert(ss.at(2) == '6');
#endif
			ss.position() = sizeof(LLL);
			assert(ss.str(16) == "1234567890123456");

			LLLAlphaNumeric<999>		lllan999;
			ss.clear();
			lllan999 = "1234567890" "1234567890" "1234567890" "1234567890" "1234567890" 
				"1234567890" "1234567890" "1234567890" "1234567890" "1234567890" "1234567890";
			assert(lllan999.length() == 110);
			ss << lllan999;
			ss.flip();
			assert(ss.limit() == sizeof(LLL) + 110);
#ifdef STD_CB2A
			assert(ss.at(0) == 0x00);
			assert(ss.at(1) == 0x6E);
#else
			assert(ss.at(0) == '1');
			assert(ss.at(1) == '1');
			assert(ss.at(2) == '0');
#endif
		}
		void LLLAlphaNumericTest::setUp() {
		}
		void LLLAlphaNumericTest::tearDown() {
		}
		CppUnit::Test* LLLAlphaNumericTest::suite() {
			CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("LLLAlphaNumericTest");
			CppUnit_addTest(pSuite, LLLAlphaNumericTest, testLLLAlphaNumeric);
			CppUnit_addTest(pSuite, LLLAlphaNumericTest, testStream);
			return pSuite;
		}
	}
}
