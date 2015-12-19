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


#include "ISO-8583-DTT-TestSuite.h"
#include "AlphabeticTest.h"
#include "AlphaNumericTest.h"
#include "AlphaNumericSpecialTest.h"
#include "NumericTest.h"
#include "SignedNumericTest.h"
#include "BitmapsTest.h"

#include "LLAlphabeticTest.h"
#include "LLAlphaNumericSpecialTest.h"
#include "LLLAlphaNumericTest.h"
#include "LLNumericTest.h"
#include "InputOutputStreamTest.h"

namespace ISO_8583 {
	namespace DTT {
		CppUnit::Test* TestSuite::suite()
		{
			CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("TestSuite");

			pSuite->addTest(InputOutputStreamTest::suite());
			pSuite->addTest(AlphabeticTest::suite());
			pSuite->addTest(AlphaNumericTest::suite());
			pSuite->addTest(AlphaNumericSpecialTest::suite());
			pSuite->addTest(NumericTest::suite());
			pSuite->addTest(SignedNumericTest::suite());
			pSuite->addTest(BitmapsTest::suite());


			pSuite->addTest(LLAlphabeticTest::suite());
			pSuite->addTest(LLAlphaNumericSpecialTest::suite());
			pSuite->addTest(LLLAlphaNumericTest::suite());
			pSuite->addTest(LLNumericTest::suite());

			return pSuite;
		}
	}
}
