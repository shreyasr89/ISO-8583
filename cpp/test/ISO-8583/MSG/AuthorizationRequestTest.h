#ifndef AuthorizationRequestTest_INCLUDED
#define AuthorizationRequestTest_INCLUDED

#include "Poco/Foundation.h"
#include "CppUnit/TestCase.h"
#include <string>
using std::string;
#include <bitset>
using std::bitset;

#include "ISO-8583/MSG/Factory.h"
#include "ISO-8583/DTE/Bitmap.h"

namespace ISO_8583 {
	namespace DTE {
		class DataElement;
		class AdditionalDataNational;
		class NationalData;
	}
}
namespace ISO_8583 {
	namespace MSG {
		class AuthorizationRequestTest : public CppUnit::TestCase	{
		private:
			Factory factory;

		public:
			AuthorizationRequestTest(const std::string& name);
			~AuthorizationRequestTest();

			void testAuthorizationRequest();

			void setUp();
			void tearDown();

			static CppUnit::Test* suite();
		private:
			static 	ISO_8583::DTE::DataElement* newDataElement(ISO_8583::DTE::Bitmap bitno, int turn = 0);
			int check(const string& hexa);
			static 	void addTLVs(ISO_8583::DTE::AdditionalDataNational* adn, const bitset<64>& subfields);
			static	void addTLVs(ISO_8583::DTE::NationalData* td, const bitset<64>& subfields);
		};
	}
}
#endif

