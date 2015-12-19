#ifndef AlphaNumericBinaryTest_INCLUDED
#define AlphaNumericBinaryTest_INCLUDED

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
namespace ISO_8583 {
	namespace DTT {
		class AlphaNumericBinaryTest : public CppUnit::TestCase	{
		public:
			AlphaNumericBinaryTest(const std::string& name);
			~AlphaNumericBinaryTest();

			void testAlphaNumericBinary();

			void setUp();
			void tearDown();

			static CppUnit::Test* suite();
		};
	}
}
#endif

