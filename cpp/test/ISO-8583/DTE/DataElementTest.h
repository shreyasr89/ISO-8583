/*
 * DataElementTest.h
 *
 *  Created on: 8 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef DATAELEMENTTEST_H_
#define DATAELEMENTTEST_H_
#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#include <string>
using std::string;


namespace ISO_8583 {
	namespace DTE {
		class DataElementTest : public CppUnit::TestCase	{
		public:
			DataElementTest(const std::string& name);
			~DataElementTest();

			void testDataElement();

			void setUp();
			void tearDown();

			static CppUnit::Test* suite();
		};
	}
}

#endif
