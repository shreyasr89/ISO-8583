#ifndef NumericTest_INCLUDED
#define NumericTest_INCLUDED

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
namespace ISO_8583 {
	namespace DTT {
		class NumericTest : public CppUnit::TestCase	{
		public:
			NumericTest(const std::string& name);
			~NumericTest();

			void testNumeric();

			void setUp();
			void tearDown();

			static CppUnit::Test* suite();
		};
	}
}
#endif

