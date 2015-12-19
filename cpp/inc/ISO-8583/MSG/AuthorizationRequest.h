/*
 * AuthorizationRequest.h
 *
 *  Created on: 18 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef AuthorizationRequest_H_
#define AuthorizationRequest_H_
#include <iostream>
using  std::istream;
using  std::ostream;

#include "ISO-8583/MSG/ISO-8583-MSG.h"

#include "ISO-8583/DTT/Bitmaps.h"
#include "ISO-8583/MSG/Request.h"
#include "ISO-8583/MSG/Message.h"

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
		class	MerchantType;
		class	PointOfServiceEntryMode;
		class	PointOfServiceConditionCode;
		class	AcquiringInstitutionIdentificationCode;
		class	CardAcceptorTerminalIdentification;
		class	CardAcceptorIdentificationCode;
		class	TransactionCurrencyCode;
		class	SecurityRelatedControlInformation;

		//optional
		class	AuthorizationIdentificationResponseLength;
		class	ForwardingInstitutionIdentificationCode;
		class	AuthorizationIdentificationResponse;
		class	RetrievalReferenceNumber;
		class	CardAcceptorNameOrlocation;
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
using ISO_8583::DTE::MerchantType;
using ISO_8583::DTE::PointOfServiceEntryMode;
using ISO_8583::DTE::PointOfServiceConditionCode;
using ISO_8583::DTE::AcquiringInstitutionIdentificationCode;
using ISO_8583::DTE::CardAcceptorTerminalIdentification;
using ISO_8583::DTE::CardAcceptorIdentificationCode;
using ISO_8583::DTE::TransactionCurrencyCode;
using ISO_8583::DTE::SecurityRelatedControlInformation;

using ISO_8583::DTE::AuthorizationIdentificationResponseLength;
using ISO_8583::DTE::ForwardingInstitutionIdentificationCode;
using ISO_8583::DTE::AuthorizationIdentificationResponse;
using ISO_8583::DTE::RetrievalReferenceNumber;
using ISO_8583::DTE::CardAcceptorNameOrlocation;
using ISO_8583::DTE::AdditionalDataNational;
using ISO_8583::DTE::NationalData;

namespace ISO_8583 {
	namespace MSG {

		class MSG_API_SCOPE AuthorizationRequest : public Message , public Request {
		private:
			static const Bitmaps	mandatoryBits;
			static const Bitmaps	optionalBits;

		public:
			struct Mandatory {
				PrimaryAccountNumber* pam = NULL;
				ProcessingCode* pc = NULL;
				TransactionAmount* ta = NULL;
				TransmissionDateAndTime* tdat = NULL;
				SystemsTraceAuditNumber* stan = NULL;
				TransactionLocalTime* tlt = NULL;
				TransactionLocalDate* tld = NULL;
				ExpirationDate* de = NULL;
				MerchantType* mt = NULL;
				PointOfServiceEntryMode* posem = NULL;
				PointOfServiceConditionCode* poscc = NULL;
				AcquiringInstitutionIdentificationCode* aiic = NULL;
				CardAcceptorTerminalIdentification* cati = NULL;
				CardAcceptorIdentificationCode* caic = NULL;
				TransactionCurrencyCode* tcc = NULL;
				SecurityRelatedControlInformation* srci = NULL;
			};
			struct Optional {
				AuthorizationIdentificationResponseLength* airl = NULL;
				ForwardingInstitutionIdentificationCode* fiic = NULL;
				RetrievalReferenceNumber* rrn = NULL;
				AuthorizationIdentificationResponse* air = NULL;
				CardAcceptorNameOrlocation* canol = NULL;
				AdditionalDataNational* adn = NULL;
				NationalData* nd = NULL;
			};

		protected:
			AuthorizationRequest() { 
			}
		public:
			AuthorizationRequest(Origin origin) : 
				Message(Class::Authorization, Function::Request, origin) {
			}
			virtual ~AuthorizationRequest() {
			}
			virtual const Bitmaps& mandatory() const;
			virtual const Bitmaps& optional() const;

			virtual BinaryInputStream& decode(BinaryInputStream& is);
			virtual BinaryOutputStream& encode(BinaryOutputStream& os) const;

			friend MSG_API_SCOPE BinaryInputStream& operator>>(BinaryInputStream& is,       AuthorizationRequest& ar);
			friend MSG_API_SCOPE BinaryOutputStream& operator<<(BinaryOutputStream& os, const AuthorizationRequest& ar);

			virtual void dump(ostream& os);

			void mapDTEs(Mandatory& mandatory, Optional& optional) const;
		};
	}
}

#endif
