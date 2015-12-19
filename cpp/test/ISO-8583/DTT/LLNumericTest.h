#ifndef LLNumericTest_INCLUDED
#define LLNumericTest_INCLUDED

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
namespace ISO_8583 {
	namespace DTT {
		class LLNumericTest : public CppUnit::TestCase	{
		public:
			LLNumericTest(const std::string& name);
			~LLNumericTest();

			void testLLNumeric();
			void testLLNumericStringStream();

			void setUp();
			void tearDown();

			static CppUnit::Test* suite();
		};
	}
}
#endif

