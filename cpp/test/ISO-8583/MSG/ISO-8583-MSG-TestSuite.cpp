#include "ISO-8583-MSG-TestSuite.h"
#include "AuthorizationRequestTest.h"

namespace ISO_8583 {
	namespace MSG {
		CppUnit::Test* TestSuite::suite()
		{
			CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("TestSuite");

			pSuite->addTest(AuthorizationRequestTest::suite());

			return pSuite;
		}
	}
}
