/*
 * DataElementTest.cpp
 *
 *  Created on: 8 juil. 2015
 *      Author: FrancisANDRE
 */
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <typeinfo> 
using namespace std;

#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#if STD_CB2A == 150
#include "CB2A/DTE/1_5_0/CB2A-DTE.h"
#elif  ISO_8583_2003	
#include "ISO-8583/DTE/ISO-8583-DTE.h"
#endif 

#include "ISO-8583/DTT/BinaryOutputStream.h"
#include "ISO-8583/DTT/BinaryInputOutputStream.h"
#include "ISO-8583/DTE/ResponseCode.h"
#include "DataElementTest.h"

using namespace ISO_8583::DTT;

namespace ISO_8583 {
	namespace DTE {

		DataElementTest::DataElementTest(const std::string& name) : CppUnit::TestCase(name) {
		}
		DataElementTest::~DataElementTest() {
		}
		void DataElementTest::testDataElement() {
			string hexa;
			string s;
			{
				ResponseCode rc;
				rc = ResponseCodes::Pickup;
				assert(rc == ResponseCodes::Pickup);
				BinaryOutputStream ss(256);
				ss << rc;
				ss.flip();
				assert(ss.at(0) == '0');
				assert(ss.at(1) == '4');
			}
			{
				ResponseCode rc;
				BinaryInputOutputStream ios(32);
				rc = ResponseCodes::Pickup;
				static_cast<BinaryOutputStream&>(ios) << rc;
				rc = ResponseCodes::SuccessfulTransaction;
				ios.flip();
				static_cast<BinaryInputStream&>(ios) >> rc;
				assert(rc == ResponseCodes::Pickup);
			}

		}
		void DataElementTest::setUp() {
		}
		void DataElementTest::tearDown() {
		}
		CppUnit::Test* DataElementTest::suite() {
			CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("NationalData");
			CppUnit_addTest(pSuite, DataElementTest, testDataElement);
			return pSuite;
		}
	}
}
