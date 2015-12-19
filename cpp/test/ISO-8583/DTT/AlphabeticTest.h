#ifndef AlphabeticTest_INCLUDED
#define AlphabeticTest_INCLUDED

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
namespace ISO_8583 {
	namespace DTT {
		class AlphabeticTest : public CppUnit::TestCase	{
		public:
			AlphabeticTest(const std::string& name);
			~AlphabeticTest();

			void testAlphabetic();
			void testStream();

			void setUp();
			void tearDown();

			static CppUnit::Test* suite();
		};
	}
}
#endif

