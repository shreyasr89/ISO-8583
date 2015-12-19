#ifndef LLAlphabeticTest_INCLUDED
#define LLAlphabeticTest_INCLUDED

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
namespace ISO_8583 {
	namespace DTT {
		class LLAlphabeticTest : public CppUnit::TestCase	{
		public:
			LLAlphabeticTest(const std::string& name);
			~LLAlphabeticTest();

			void testLLAlphabeticTest();
			void testStream();

			void setUp();
			void tearDown();

			static CppUnit::Test* suite();
		};
	}
}
#endif

