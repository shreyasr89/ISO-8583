//
// AddrTestSuite.cpp
//
// $Id$
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "ISO-8583-DTE-TestSuite.h"
//#include "ISO-8583/DTE/AdditionalDataNationalTest.h"
//#include "ISO-8583/DTE/NationalDataTest.h"
#include "DataElementTest.h"

namespace ISO_8583 {
	namespace DTE {
		CppUnit::Test* TestSuite::suite()
		{
			CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("TestSuite");

			pSuite->addTest(DataElementTest::suite());
//			pSuite->addTest(AdditionalDataNationalTest::suite());
//			pSuite->addTest(NationalDataTest::suite());

			return pSuite;
		}
	}
}