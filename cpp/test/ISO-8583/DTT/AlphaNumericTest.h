#ifndef AlphaNumericTest_INCLUDED
#define AlphaNumericTest_INCLUDED

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
namespace ISO_8583 {
	namespace DTT {
		class AlphaNumericTest : public CppUnit::TestCase	{
		public:
			AlphaNumericTest(const std::string& name);
			~AlphaNumericTest();

			void testAlphaNumeric();
			void testStream();

			void setUp();
			void tearDown();

			static CppUnit::Test* suite();
		};
	}
}
#endif

