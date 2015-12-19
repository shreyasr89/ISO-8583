/*
 * ResponseCode.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef RESPONSECODE_H_
#define RESPONSECODE_H_

#if STD_CB2A == 150 || STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003

#include "ISO-8583/DTE/DataElement.h"
#include "ISO-8583/DTT/AlphaNumeric.h"

/*
CB2A-150			39 Code réponse  an2
ISO-8583-1987		39 Response code an2
*/

namespace ISO_8583 {
	namespace DTE {
		enum class ResponseCodes {
			SuccessfulTransaction = 0,
			ReferToCardIssuer = 1,
			ReferToCaseIssuerSpecialCondition = 2,
			InvalidMerchant = 3,
			Pickup = 4,
			DoNotHonour = 5,
			Error = 6,
			PickupCardSpecialCondition = 7,
			HonourWithIdentification = 8,
			RequestInProgress = 9,
			ApprovedForPartialAmount = 10,
			ApprovedVIP = 11,
			InvalidTransaction = 12,
			InvalidAmount = 13,
			InvalidCardNumber = 14,
			NoSuchIssuer = 15,
			ApprovedUpdateTrack3 = 16,
			CustomerCancellation = 17,
			CustormerDispute = 18,
			ReEnterTransaction = 19,
			InvalidResponse = 20,
			NoActionTaken = 21,
			SuspectedMalfunction = 22,
			UnacceptableTransactionFee = 23,
#if 0
			InvalidResponse = 24,
			InvalidResponse = 25,
			InvalidResponse = 26,
			InvalidResponse = 27,
			InvalidResponse = 28,
			InvalidResponse = 29,
			InvalidResponse = 30,
			InvalidResponse = 31,
			InvalidResponse = 32,
			InvalidResponse = 33,
			InvalidResponse = 34,
			InvalidResponse = 35,
			InvalidResponse = 36,
			InvalidResponse = 37,
			InvalidResponse = 38,
			InvalidResponse = 39,
			InvalidResponse = 40,
			InvalidResponse = 41,
			InvalidResponse = 42,
			InvalidResponse = 43,
			InvalidResponse = 44,
			InvalidResponse = 45,
			InvalidResponse = 46,
			InvalidResponse = 47,
			InvalidResponse = 48,
			InvalidResponse = 49,
			InvalidResponse = 50,
			InvalidResponse = 51,
			InvalidResponse = 52,
			InvalidResponse = 53,
			InvalidResponse = 54,
			InvalidResponse = 55,
			InvalidResponse = 56,
			InvalidResponse = 57,
			InvalidResponse = 58,
			InvalidResponse = 59,
			InvalidResponse = 60,
			InvalidResponse = 61,
			InvalidResponse = 62,
			InvalidResponse = 63,
			InvalidResponse = 64,
			InvalidResponse = 65,
			InvalidResponse = 66,
			InvalidResponse = 67,
			InvalidResponse = 68,
			InvalidResponse = 69,
			InvalidResponse = 70,
			InvalidResponse = 71,
			InvalidResponse = 72,
			InvalidResponse = 77,
			InvalidResponse = 74,
			InvalidResponse = 75,
			InvalidResponse = 76,
			InvalidResponse = 77,
			InvalidResponse = 78,
			InvalidResponse = 79,
			InvalidResponse = 80,
			InvalidResponse = 81,
			InvalidResponse = 82,
			InvalidResponse = 83,
			InvalidResponse = 84,
			InvalidResponse = 85,
			InvalidResponse = 86,
			InvalidResponse = 87,
			InvalidResponse = 88,
			InvalidResponse = 89,
			InvalidResponse = 90,
			InvalidResponse = 91,
			InvalidResponse = 92,
			InvalidResponse = 93,
			InvalidResponse = 94,
			InvalidResponse = 95,
			InvalidResponse = 96,
			InvalidResponse = 97,
			InvalidResponse = 98,
			InvalidResponse = 99,
#endif
		};

		DTE_API_SCOPE const char* toString(const ResponseCodes& responseCode);

		class DTE_API_SCOPE ResponseCode :
			public AlphaNumeric<2>,
			public DataElement {
		public:
			typedef AlphaNumeric<2> BaseType;
			static const int  bitmapno = 39;
			
		public:
			ResponseCode() {}
			virtual ~ResponseCode() {}

			ResponseCode& operator=(const string& value) {
				static_cast<BaseType&>(*this) = value; return *this;
			}
			ResponseCode& operator=(const char* value) {
				static_cast<BaseType&>(*this) = value; return *this;
			}
			ResponseCode& operator=(nat8 value) {
				static_cast<BaseType&>(*this) = value; return *this;
			}
			ResponseCode& operator=(ResponseCodes value) {
				static_cast<BaseType&>(*this) = static_cast<int>(value); return *this;
			}
			operator ResponseCodes() const { return  (ResponseCodes)((bytes[0] - '0') * 10 + (bytes[1] - '0')); }
			virtual int bitno() const { return bitmapno; }
			virtual void decode(InputStream& is);
			virtual void encode(OutputStream& os);
			virtual string toString() const;
		};
	}
}

#endif
#endif
