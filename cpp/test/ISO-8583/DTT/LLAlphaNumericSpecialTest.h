#ifndef LLAlphaNumericSpecialTest_INCLUDED
#define LLAlphaNumericSpecialTest_INCLUDED

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
namespace ISO_8583 {
	namespace DTT {
		class LLAlphaNumericSpecialTest : public CppUnit::TestCase	{
		public:
			LLAlphaNumericSpecialTest(const std::string& name);
			~LLAlphaNumericSpecialTest();

			void testLLAlphaNumericSpecial();

			void setUp();
			void tearDown();

			static CppUnit::Test* suite();
		};
	}
}
#endif

