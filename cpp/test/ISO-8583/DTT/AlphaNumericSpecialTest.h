#ifndef AlphaNumericSpecialTest_INCLUDED
#define AlphaNumericSpecialTest_INCLUDED

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
namespace ISO_8583 {
	namespace DTT {
		class AlphaNumericSpecialTest : public CppUnit::TestCase	{
		public:
			AlphaNumericSpecialTest(const std::string& name);
			~AlphaNumericSpecialTest();

			void testAlphaNumericSpecial();
			void testStream();

			void setUp();
			void tearDown();

			static CppUnit::Test* suite();
		};
	}
}
#endif

