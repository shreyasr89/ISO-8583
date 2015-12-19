#ifndef AlphaNumericSpaceTest_INCLUDED
#define AlphaNumericSpaceTest_INCLUDED

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
namespace ISO_8583 {
	namespace DTT {
		class AlphaNumericSpaceTest : public CppUnit::TestCase	{
		public:
			AlphaNumericSpaceTest(const std::string& name);
			~AlphaNumericSpaceTest();

			void testAlphaNumericSpace();
			void testStream();

			void setUp();
			void tearDown();

			static CppUnit::Test* suite();
		};
	}
}
#endif

