/*
 * AuthorizationRequest.cpp
 *
 *  Created on: 18 mai 2015
 *      Author: FrancisANDRE
 */

#include <memory>
#include <stdexcept>
using  namespace std;

#include "ISO-8583/DTE/Bitmap.h"


#include "ISO-8583/DTE/PrimaryAccountNumber.h"
#include "ISO-8583/DTE/ProcessingCode.h"
#include "ISO-8583/DTE/TransactionAmount.h"
#include "ISO-8583/DTE/TransmissionDateAndTime.h"
#include "ISO-8583/DTE/SystemsTraceAuditNumber.h"
#include "ISO-8583/DTE/TransactionLocalTime.h"
#include "ISO-8583/DTE/TransactionLocalDate.h"
#include "ISO-8583/DTE/ExpirationDate.h"
#include "ISO-8583/DTE/MerchantType.h"
#include "ISO-8583/DTE/PointOfServiceEntryMode.h"
#include "ISO-8583/DTE/PointOfServiceConditionCode.h"
#include "ISO-8583/DTE/AcquiringInstitutionIdentificationCode.h"
#include "ISO-8583/DTE/CardAcceptorTerminalIdentification.h"
#include "ISO-8583/DTE/CardAcceptorIdentificationCode.h"
#include "ISO-8583/DTE/TransactionCurrencyCode.h"
#include "ISO-8583/DTE/SecurityRelatedControlInformation.h"

#include "ISO-8583/DTE/AuthorizationIdentificationResponseLength.h"
#include "ISO-8583/DTE/ForwardingInstitutionIdentificationCode.h"
#include "ISO-8583/DTE/RetrievalReferenceNumber.h"
#include "ISO-8583/DTE/AuthorizationIdentificationResponse.h"
#include "ISO-8583/DTE/CardAcceptorNameOrlocation.h"
#include "ISO-8583/DTE/AdditionalDataNational.h"
#include "ISO-8583/DTE/NationalData.h"
#include "ISO-8583/DTE/ResponseCode.h"

#include "ISO-8583/MSG/AuthorizationRequest.h"
#include "ISO-8583/MSG/AuthorizationRequestResponse.h"

using namespace ISO_8583::DTE;

namespace ISO_8583 {
	namespace MSG {
		// 723C448100C0880000000000000000000000000000000000
		const Bitmaps		AuthorizationRequest::mandatoryBits(16,
			Bitmap::PrimaryAccountNumber,
			Bitmap::ProcessingCode,
			Bitmap::TransactionAmount,
			Bitmap::TransmissionDateAndTime,
			Bitmap::SystemsTraceAuditNumber,
#if STD_ISO_8583 == 1987
			Bitmap::TransactionLocalTime,
			Bitmap::TransactionLocalDate,
			Bitmap::PointOfServiceEntryMode,
			Bitmap::PointOfServiceConditionCode,
			Bitmap::TransactionCurrencyCode,
			Bitmap::MerchantType,
#elif STD_ISO_8583 == 1993
#elif STD_ISO_8583 == 2003
#endif
			Bitmap::ExpirationDate,
			Bitmap::AcquiringInstitutionIdentificationCode,
			Bitmap::CardAcceptorTerminalIdentification,
			Bitmap::CardAcceptorIdentificationCode,
			Bitmap::SecurityRelatedControlInformation
			);

		// 000000208C22002000000000000000000000000000000000
		const Bitmaps		AuthorizationRequest::optionalBits(7,
#if STD_ISO_8583 == 1987
			Bitmap::AuthorizationIdentificationResponseLength,
			Bitmap::AuthorizationIdentificationResponse,
			Bitmap::NationalData,
#elif STD_ISO_8583 == 1993
#elif STD_ISO_8583 == 2003
#endif
			Bitmap::ForwardingInstitutionIdentificationCode,
			Bitmap::RetrievalReferenceNumber,
			Bitmap::CardAcceptorNameOrlocation,
			Bitmap::AdditionalDataNational
			);

		const Bitmaps& AuthorizationRequest::mandatory() const {
			return mandatoryBits;
		}
		const Bitmaps& AuthorizationRequest::optional() const {
			return optionalBits;
		}

		BinaryInputStream& AuthorizationRequest::decode(BinaryInputStream& is) {
			is >> *this;
			return is;
		}
		BinaryOutputStream& AuthorizationRequest::encode(BinaryOutputStream& os) const {
			os << *this;
			return os;
		}
		MSG_API_SCOPE BinaryInputStream& operator>>(BinaryInputStream& is, AuthorizationRequest& ar) {
			is >> static_cast<Message&>(ar);
			return is;
		}
		MSG_API_SCOPE BinaryOutputStream& operator<<(BinaryOutputStream& os, const AuthorizationRequest& ar) {
			os << static_cast<const Message&>(ar);
			return os;
		}
		void AuthorizationRequest::dump(ostream& os) {
			Mandatory mandatory;
			Optional optional;

			mapDTEs(mandatory, optional);

			const string FORMAT = "%3d %-65s:%s";
			char buffer[4 * 1024];
			string label, value;

#define DUMP(type, area, var) \
			if (area.var) { \
				label = typeid(*area.var).name(); value =  area.var->toString(); \
				sprintf(buffer, FORMAT.c_str(), area.var->bitno(), label.c_str(), value.c_str()); \
				os << buffer << endl; \
			}
			
			DUMP(PrimaryAccountNumber, mandatory, pam)
			DUMP(ProcessingCode, mandatory, pc)
			DUMP(TransactionAmount, mandatory, ta)
			DUMP(SystemsTraceAuditNumber, mandatory, stan)
			DUMP(TransactionLocalTime, mandatory, tlt)
			DUMP(TransactionLocalDate, mandatory, tld)
			DUMP(ExpirationDate, mandatory, de)
			DUMP(MerchantType, mandatory, mt)
			DUMP(PointOfServiceEntryMode, mandatory, posem)
			DUMP(PointOfServiceConditionCode, mandatory, poscc)
			DUMP(AcquiringInstitutionIdentificationCode, mandatory, aiic)
			DUMP(CardAcceptorTerminalIdentification, mandatory, cati)
			DUMP(CardAcceptorIdentificationCode, mandatory, caic)
			DUMP(TransactionCurrencyCode, mandatory, tcc)
			DUMP(SecurityRelatedControlInformation, mandatory, srci)
			DUMP(TransmissionDateAndTime, mandatory, tdat)

			DUMP(AuthorizationIdentificationResponseLength, optional, airl)
			DUMP(ForwardingInstitutionIdentificationCode, optional, fiic)
			DUMP(RetrievalReferenceNumber, optional, rrn)
			DUMP(AuthorizationIdentificationResponse, optional, air)
			DUMP(CardAcceptorNameOrlocation, optional, canol)
			DUMP(AdditionalDataNational, optional, adn)
			if (optional.nd) {
				label = typeid(*optional.nd).name(); value = optional.nd->str();
				os.width(3);
				os << optional.nd->bitno() << " " << label << endl;
				optional.nd->dump(os);
			}
		}
		void AuthorizationRequest::mapDTEs(Mandatory& mandatory, Optional& optional) const {
			for (int no = 0; no < fields.size(); no++) {
				DataElement* dte = fields[no];
				switch (static_cast<Bitmap>(dte->bitno())) {
					// mandatory
				case Bitmap::PrimaryAccountNumber: 
					mandatory.pam = dynamic_cast<PrimaryAccountNumber*>(dte);	break;

				case Bitmap::ProcessingCode:
					mandatory.pc = dynamic_cast<ProcessingCode*>(dte); break;

				case Bitmap::TransactionAmount:
					mandatory.ta = dynamic_cast<TransactionAmount*>(dte); break;

				case Bitmap::SystemsTraceAuditNumber:
					mandatory.stan = dynamic_cast<SystemsTraceAuditNumber*>(dte); break;

#if STD_ISO_8583 == 1987
				case Bitmap::TransactionLocalTime:
					mandatory.tlt = dynamic_cast<TransactionLocalTime*>(dte); break;

				case Bitmap::TransactionLocalDate:
					mandatory.tld = dynamic_cast<TransactionLocalDate*>(dte); break;

				case Bitmap::MerchantType:
					mandatory.mt = dynamic_cast<MerchantType*>(dte);  break;
#elif STD_ISO_8583 == 1993
#elif STD_ISO_8583 == 2003
#endif
				case Bitmap::ExpirationDate:
					mandatory.de = dynamic_cast<ExpirationDate*>(dte); break;


#if STD_ISO_8583 == 1987
				case Bitmap::PointOfServiceEntryMode:
					mandatory.posem = dynamic_cast<PointOfServiceEntryMode*>(dte); break;

				case Bitmap::PointOfServiceConditionCode:
					mandatory.poscc = dynamic_cast<PointOfServiceConditionCode*>(dte); break;

				case Bitmap::TransactionCurrencyCode:
					mandatory.tcc = dynamic_cast<TransactionCurrencyCode*>(dte); break;

#elif STD_ISO_8583 == 1993
#elif STD_ISO_8583 == 2003
#endif

				case Bitmap::AcquiringInstitutionIdentificationCode:
					mandatory.aiic = dynamic_cast<AcquiringInstitutionIdentificationCode*>(dte); break;

				case Bitmap::CardAcceptorTerminalIdentification:
					mandatory.cati = dynamic_cast<CardAcceptorTerminalIdentification*>(dte); break;

				case Bitmap::CardAcceptorIdentificationCode:
					mandatory.caic = dynamic_cast<CardAcceptorIdentificationCode*>(dte); break;

				case Bitmap::SecurityRelatedControlInformation:
					mandatory.srci = dynamic_cast<SecurityRelatedControlInformation*>(dte); break;

				case Bitmap::TransmissionDateAndTime:
					mandatory.tdat = dynamic_cast<TransmissionDateAndTime*>(dte); break;

				// optional
#if STD_ISO_8583 == 1987
				case Bitmap::AuthorizationIdentificationResponseLength:
					optional.airl = dynamic_cast<AuthorizationIdentificationResponseLength*>(dte); break;

#elif STD_ISO_8583 == 1993
#elif STD_ISO_8583 == 2003
#endif
				case Bitmap::ForwardingInstitutionIdentificationCode:
					optional.fiic = dynamic_cast<ForwardingInstitutionIdentificationCode*>(dte); break;

				case Bitmap::RetrievalReferenceNumber:
					optional.rrn = dynamic_cast<RetrievalReferenceNumber*>(dte); break;

#if STD_ISO_8583 == 1987
				case Bitmap::AuthorizationIdentificationResponse:
					optional.air = dynamic_cast<AuthorizationIdentificationResponse*>(dte); break;
#elif STD_ISO_8583 == 1993
#elif STD_ISO_8583 == 2003
#endif

				case Bitmap::CardAcceptorNameOrlocation:
					optional.canol = dynamic_cast<CardAcceptorNameOrlocation*>(dte); break;

				case Bitmap::AdditionalDataNational:
					optional.adn = dynamic_cast<AdditionalDataNational*>(dte); break;

#if STD_ISO_8583 == 1987
				case Bitmap::NationalData:
					optional.nd = dynamic_cast<NationalData*>(dte); break;

#elif STD_ISO_8583 == 1993
#elif STD_ISO_8583 == 2003
#endif
				}
			}
		}
	}
}
