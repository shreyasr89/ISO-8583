#ifndef SignedNumericTest_INCLUDED
#define SignedNumericTest_INCLUDED

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
namespace ISO_8583 {
	namespace DTT {
		class SignedNumericTest : public CppUnit::TestCase	{
		public:
			SignedNumericTest(const std::string& name);
			~SignedNumericTest();

			void testSignedNumeric();

			void setUp();
			void tearDown();

			static CppUnit::Test* suite();
		};
	}
}
#endif

