#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#include "ISO-8583/DTT/BinaryOutputStream.h"
#include "ISO-8583/DTT/BinaryInputOutputStream.h"
#include "ISO-8583/DTT/LLNumeric.h"
#include "LLNumericTest.h"


namespace ISO_8583 {
	namespace DTT {
		LLNumericTest::LLNumericTest(const std::string& name) : CppUnit::TestCase(name) {
		}
		LLNumericTest::~LLNumericTest() {
		}
		void LLNumericTest::testLLNumeric() {
			assert(sizeof(LLNumeric<1>) == sizeof(LL) + sizeof(Numeric<1>));
			assert(sizeof(LLNumeric<2>) == sizeof(LL) + sizeof(Numeric<2>));
			assert(sizeof(LLNumeric<3>) == sizeof(LL) + sizeof(Numeric<3>));
			assert(sizeof(LLNumeric<4>) == sizeof(LL) + sizeof(Numeric<4>));
			assert(sizeof(LLNumeric<5>) == sizeof(LL) + sizeof(Numeric<5>));
			assert(sizeof(LLNumeric<6>) == sizeof(LL) + sizeof(Numeric<6>));
			assert(sizeof(LLNumeric<7>) == sizeof(LL) + sizeof(Numeric<7>));
			assert(sizeof(LLNumeric<8>) == sizeof(LL) + sizeof(Numeric<8>));

			LLNumeric<8>		llp8;
			string s;

			assert(llp8.length() == 0);
			llp8 = "1";
			assert(llp8.length() == strlen("1"));
			assert(llp8.str() == "1");

			llp8 = "4433";
			assert(llp8.length() == strlen("4433"));
			assert(llp8.str() == "4433");

			try {
				llp8 = "123456789";
				assert("overflow_error" == 0);
			}
			catch (overflow_error e) {
			}

			try {
				llp8 = "1bcdefgh";
				assert("invalid_argument" == 0);
			}
			catch (invalid_argument e) {
			}


#define V1 	"9876543210123456"
#define V2 	"9876543210123456789"
#define V3 	"1"
#define V4 	"22"
#define V5 	"333"

			LLNumeric<19>	llp19;
			llp19 = V1;
			assert(llp19.length() == strlen(V1));
			assert(llp19.str() == V1);

			llp19 = V2;
			assert(llp19.length() == strlen(V2));
			assert(llp19.str() == V2);

			llp19 = V3;
			assert(llp19.length() == strlen(V3));
			assert(llp19.str() == V3);

			llp19 = V4;
			assert(llp19.length() == strlen(V4));
			assert(llp19.str() == V4);

			llp19 = V5;
			assert(llp19.length() == strlen(V5));
			assert(llp19.str() == V5);

		}
		void LLNumericTest::testLLNumericStringStream() {
			BinaryInputOutputStream		ios(256);
			LLNumeric<19>	llp19;
			string s;
			int no;

			ios.clear();
			llp19 = V1;
			assert(llp19.length() == strlen(V1));
			ios << llp19;
			ios.flip();
			int sz = sizeof(LL); int sz1 = ios.remaining(); int sz2 = llp19.length();
			no = 0;
#ifdef STD_CB2A
			assert(ios.remaining() == sizeof(LL) + (llp19.length() + 1) / 2);
			assert((byte)ios.at(no++) == 0x10);
			assert((byte)ios.at(no++) == 0x98);
			assert((byte)ios.at(no++) == 0x76);
			assert((byte)ios.at(no++) == 0x54);
			assert((byte)ios.at(no++) == 0x32);
			assert((byte)ios.at(no++) == 0x10);
			assert((byte)ios.at(no++) == 0x12);
			assert((byte)ios.at(no++) == 0x34);
			assert((byte)ios.at(no++) == 0x56);
#elif defined(STD_ISO_8583)
			assert(ios.remaining() == sizeof(LL) + llp19.length());
			assert((byte)ios.at(no++) == '1');
			assert((byte)ios.at(no++) == '6');
			assert((byte)ios.at(no++) == '9');
			assert((byte)ios.at(no++) == '8');
			assert((byte)ios.at(no++) == '7');
			assert((byte)ios.at(no++) == '6');
			assert((byte)ios.at(no++) == '5');
			assert((byte)ios.at(no++) == '4');
			assert((byte)ios.at(no++) == '3');
			assert((byte)ios.at(no++) == '2');
			assert((byte)ios.at(no++) == '1');
			assert((byte)ios.at(no++) == '0');
			assert((byte)ios.at(no++) == '1');
			assert((byte)ios.at(no++) == '2');
			assert((byte)ios.at(no++) == '3');
			assert((byte)ios.at(no++) == '4');
			assert((byte)ios.at(no++) == '5');
			assert((byte)ios.at(no++) == '6');
#endif
			llp19 = (nat8)0LL;
			ios >> llp19;
			assert(llp19.length() == strlen(V1));
			string a = llp19.str();
			assert(llp19.str() == V1);


			ios.clear();
			llp19 = V2;
			ios << llp19;
			ios.flip();
			no = 0;
#ifdef STD_CB2A
			assert(ios.remaining() == sizeof(LL) + (llp19.length() + 1) / 2);
			assert((byte)ios.at(no++) == 0x13);
			assert((byte)ios.at(no++) == 0x09);
			assert((byte)ios.at(no++) == 0x87);
			assert((byte)ios.at(no++) == 0x65);
			assert((byte)ios.at(no++) == 0x43);
			assert((byte)ios.at(no++) == 0x21);
			assert((byte)ios.at(no++) == 0x01);
			assert((byte)ios.at(no++) == 0x23);
			assert((byte)ios.at(no++) == 0x45);
			assert((byte)ios.at(no++) == 0x67);
			assert((byte)ios.at(no++) == 0x89);
#elif defined(STD_ISO_8583)
			assert(ios.remaining() == sizeof(LL) + llp19.length());
			assert((byte)ios.at(no++) == '1');
			assert((byte)ios.at(no++) == '9');
			assert((byte)ios.at(no++) == '9');
			assert((byte)ios.at(no++) == '8');
			assert((byte)ios.at(no++) == '7');
			assert((byte)ios.at(no++) == '6');
			assert((byte)ios.at(no++) == '5');
			assert((byte)ios.at(no++) == '4');
			assert((byte)ios.at(no++) == '3');
			assert((byte)ios.at(no++) == '2');
			assert((byte)ios.at(no++) == '1');
			assert((byte)ios.at(no++) == '0');
			assert((byte)ios.at(no++) == '1');
			assert((byte)ios.at(no++) == '2');
			assert((byte)ios.at(no++) == '3');
			assert((byte)ios.at(no++) == '4');
			assert((byte)ios.at(no++) == '5');
			assert((byte)ios.at(no++) == '6');
			assert((byte)ios.at(no++) == '7');
			assert((byte)ios.at(no++) == '8');
			assert((byte)ios.at(no++) == '9');
#endif

			ios.clear();
			llp19 = (nat8)0LL;
			ios >> llp19;
			assert(llp19.length() == strlen(V2));
			a = llp19.str();
			assert(llp19.str() == V2);

		}
		void LLNumericTest::setUp() {
		}
		void LLNumericTest::tearDown() {
		}
		CppUnit::Test* LLNumericTest::suite() {
			CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("LLNumericTest");
			CppUnit_addTest(pSuite, LLNumericTest, testLLNumeric);
			CppUnit_addTest(pSuite, LLNumericTest, testLLNumericStringStream);
			return pSuite;
		}
	}
}
