#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#include "ISO-8583/DTT/BinaryOutputStream.h"
#include "ISO-8583/DTT/Bitmaps.h"
#include "ISO-8583/DTE/Bitmap.h"
#include "BitmapsTest.h"

using namespace ISO_8583::DTE;


namespace ISO_8583 {
	namespace DTT {
		BitmapsTest::BitmapsTest(const std::string& name) : CppUnit::TestCase(name) {
		}
		BitmapsTest::~BitmapsTest() {
		}
		void BitmapsTest::testBitmaps() {
			// 723C448100C0880000000000000000000000000000000000
			Bitmaps		bitmaps(16,
				Bitmap::PrimaryAccountNumber,
				Bitmap::ProcessingCode,
				Bitmap::TransactionAmount,
				Bitmap::TransmissionDateAndTime,
				Bitmap::SystemsTraceAuditNumber,
				Bitmap::TransactionLocalTime,
				Bitmap::TransactionLocalDate,
				Bitmap::ExpirationDate,
				Bitmap::MerchantType,
				Bitmap::PointOfServiceEntryMode,
				Bitmap::PointOfServiceConditionCode,
				Bitmap::AcquiringInstitutionIdentificationCode,
				Bitmap::CardAcceptorTerminalIdentification,
				Bitmap::CardAcceptorIdentificationCode,
				Bitmap::TransactionCurrencyCode,
				Bitmap::SecurityRelatedControlInformation
				);
			assert(bitmaps.count() == 16);

			assert(bitmaps.get((int)Bitmap::PrimaryAccountNumber));
			assert(bitmaps.get((int)Bitmap::ProcessingCode));
			assert(bitmaps.get((int)Bitmap::TransactionAmount));
			assert(bitmaps.get((int)Bitmap::TransmissionDateAndTime));
			assert(bitmaps.get((int)Bitmap::SystemsTraceAuditNumber));
			assert(bitmaps.get((int)Bitmap::TransactionLocalTime));
			assert(bitmaps.get((int)Bitmap::TransactionLocalDate));
			assert(bitmaps.get((int)Bitmap::ExpirationDate));
			assert(bitmaps.get((int)Bitmap::PointOfServiceEntryMode));
			assert(bitmaps.get((int)Bitmap::PointOfServiceConditionCode));
			assert(bitmaps.get((int)Bitmap::AcquiringInstitutionIdentificationCode));
			assert(bitmaps.get((int)Bitmap::CardAcceptorTerminalIdentification));
			assert(bitmaps.get((int)Bitmap::CardAcceptorIdentificationCode));
			assert(bitmaps.get((int)Bitmap::TransactionCurrencyCode));
			assert(bitmaps.get((int)Bitmap::SecurityRelatedControlInformation));

			stringstream str;
			str << hex << uppercase << bitmaps.toLong(1);
			assert(str.str() == "723C448100C08800");

			// 000000208C22002000000000000000000000000000000000
			bitmaps.set((byte)Bitmap::AuthorizationIdentificationResponseLength);
			bitmaps.set((byte)Bitmap::ForwardingInstitutionIdentificationCode);
			bitmaps.set((byte)Bitmap::RetrievalReferenceNumber);
			bitmaps.set((byte)Bitmap::AuthorizationIdentificationResponse);
			bitmaps.set((byte)Bitmap::CardAcceptorNameOrlocation);
			bitmaps.set((byte)Bitmap::AdditionalDataNational);
			bitmaps.set((byte)Bitmap::NationalData);
			

			assert(bitmaps.count() == 7 + 16);
			str.clear(); str.seekg(0); str.seekp(0);
			str << hex << uppercase << bitmaps.toLong(1);
			assert(str.str() == "723C44A18CE28820");
		}
		void BitmapsTest::testStream() {
			Bitmaps		bms;
			BinaryOutputStream	ss(256);

			ss.clear();
		}
		void BitmapsTest::setUp() {
		}
		void BitmapsTest::tearDown() {
		}
		CppUnit::Test* BitmapsTest::suite() {
			CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("BitmapsTest");
			CppUnit_addTest(pSuite, BitmapsTest, testBitmaps);
			return pSuite;
		}
	}
}
