#ifndef BitmapsTest_INCLUDED
#define BitmapsTest_INCLUDED

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
namespace ISO_8583 {
	namespace DTT {
		class BitmapsTest : public CppUnit::TestCase	{
		public:
			BitmapsTest(const std::string& name);
			~BitmapsTest();

			void testBitmaps();
			void testStream();

			void setUp();
			void tearDown();

			static CppUnit::Test* suite();
		};
	}
}
#endif

