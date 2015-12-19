/*
 * AuthorizationRequestResponse.h
 *
 *  Created on: 18 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef AuthorizationRequestRESPONSE_H_
#define AuthorizationRequestRESPONSE_H_
#include <iostream>
using  std::istream;
using  std::ostream;

#include "ISO-8583/MSG/ISO-8583-MSG.h"

#include "ISO-8583/DTT/Bitmaps.h"
#include "ISO-8583/MSG/Message.h"
#include "ISO-8583/MSG/RequestResponse.h"

using ISO_8583::MSG::Message;
using ISO_8583::MSG::Origin;
using ISO_8583::MSG::Version;
using ISO_8583::MSG::Class;
using ISO_8583::MSG::Function;

namespace ISO_8583 {
	namespace DTE {
		// mandatory
		class	PrimaryAccountNumber;
		class	ProcessingCode;
		class	TransactionAmount;
		class	TransmissionDateAndTime;
		class	SystemsTraceAuditNumber;
		class	TransactionLocalTime;
		class	TransactionLocalDate;
		class	ExpirationDate;
		class	SettlementDate;
		class	MerchantType;
		class	PointOfServiceEntryMode;
		class	PointOfServiceConditionCode;
		class	AcquiringInstitutionIdentificationCode;
		class	ResponseCode;
		class	CardAcceptorTerminalIdentification;
		class	CardAcceptorIdentificationCode;
		class	TransactionCurrencyCode;
		class	SecurityRelatedControlInformation;

		//optional
		class	ForwardingInstitutionIdentificationCode;
		class	AuthorizationIdentificationResponse;
		class	RetrievalReferenceNumber;
		class	CardAcceptorNameOrlocation;
		class	AdditionalResponseData;
		class	AdditionalDataNational;
		class	NationalData;
	}
}

using ISO_8583::DTE::PrimaryAccountNumber;
using ISO_8583::DTE::ProcessingCode;
using ISO_8583::DTE::TransactionAmount;
using ISO_8583::DTE::TransmissionDateAndTime;
using ISO_8583::DTE::SystemsTraceAuditNumber;
using ISO_8583::DTE::TransactionLocalTime;
using ISO_8583::DTE::TransactionLocalDate;
using ISO_8583::DTE::ExpirationDate;
using ISO_8583::DTE::SettlementDate;
using ISO_8583::DTE::MerchantType;
using ISO_8583::DTE::PointOfServiceEntryMode;
using ISO_8583::DTE::PointOfServiceConditionCode;
using ISO_8583::DTE::AcquiringInstitutionIdentificationCode;
using ISO_8583::DTE::ResponseCode;
using ISO_8583::DTE::CardAcceptorTerminalIdentification;
using ISO_8583::DTE::CardAcceptorIdentificationCode;
using ISO_8583::DTE::TransactionCurrencyCode;
using ISO_8583::DTE::SecurityRelatedControlInformation;

using ISO_8583::DTE::ForwardingInstitutionIdentificationCode;
using ISO_8583::DTE::AuthorizationIdentificationResponse;
using ISO_8583::DTE::RetrievalReferenceNumber;
using ISO_8583::DTE::CardAcceptorNameOrlocation;
using ISO_8583::DTE::AdditionalResponseData;
using ISO_8583::DTE::AdditionalDataNational;
using ISO_8583::DTE::NationalData;

namespace ISO_8583 {
	namespace MSG {

		class MSG_API_SCOPE AuthorizationRequestResponse  : public Message, public RequestResponse {
		private:
			static const Bitmaps		mandatoryBits;
			static const Bitmaps		optionalBits;

		public:
			struct Mandatory {
				PrimaryAccountNumber* pam = NULL;
				ProcessingCode* pc = NULL;
				TransactionAmount* ta = NULL;
				TransmissionDateAndTime* tdat = NULL;
				SystemsTraceAuditNumber* stan = NULL;
				AcquiringInstitutionIdentificationCode* aiic = NULL;
				ResponseCode* rc = NULL;
				CardAcceptorTerminalIdentification* cati = NULL;
				CardAcceptorIdentificationCode* caic = NULL;
				TransactionCurrencyCode* tcc = NULL;
				SecurityRelatedControlInformation* srci = NULL;
			};
			struct Optional {
				TransactionLocalTime* tlt = NULL;
				TransactionLocalDate* tld = NULL;
				ExpirationDate* de = NULL;
				SettlementDate* ds = NULL;
				MerchantType* mt = NULL;
				PointOfServiceEntryMode* posem = NULL;
				PointOfServiceConditionCode* poscc = NULL;
				ForwardingInstitutionIdentificationCode* fiic = NULL;
				RetrievalReferenceNumber* rrn = NULL;
				CardAcceptorNameOrlocation* canol = NULL;
				AdditionalResponseData* ard = NULL;
				AdditionalDataNational* adn = NULL;
				NationalData* nd = NULL;
			};
		public:
			AuthorizationRequestResponse() {
			}
			AuthorizationRequestResponse(Origin origin) :
				Message(Class::Authorization, Function::RequestResponse, origin) {
			}
			virtual ~AuthorizationRequestResponse() {
			}
			virtual const Bitmaps& mandatory() const;
			virtual const Bitmaps& optional() const;

			virtual BinaryInputStream& decode(BinaryInputStream& is);
			virtual BinaryOutputStream& encode(BinaryOutputStream& os) const;

			friend MSG_API_SCOPE BinaryInputStream& operator>>(BinaryInputStream& is,       AuthorizationRequestResponse& arr);
			friend MSG_API_SCOPE BinaryOutputStream& operator<<(BinaryOutputStream& os, const AuthorizationRequestResponse& arr);

			virtual void dump(ostream& os);

			void mapDTEs(Mandatory& mandatory, Optional& optional) const;
		};
	}
}

#endif
