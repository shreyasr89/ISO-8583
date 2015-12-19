#ifndef LLLAlphaNumericTest_INCLUDED
#define LLLAlphaNumericTest_INCLUDED

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
namespace ISO_8583 {
	namespace DTT {
		class LLLAlphaNumericTest : public CppUnit::TestCase	{
		public:
			LLLAlphaNumericTest(const std::string& name);
			~LLLAlphaNumericTest();

			void testLLLAlphaNumeric();
			void testStream();

			void setUp();
			void tearDown();

			static CppUnit::Test* suite();
		};
	}
}
#endif

