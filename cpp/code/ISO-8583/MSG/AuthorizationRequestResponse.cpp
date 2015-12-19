/*
 * AuthorizationRequestResponse.cpp
 *
 *  Created on: 18 mai 2015
 *      Author: FrancisANDRE
 */

#include <iostream>
#include <stdexcept>
using  namespace std;

#include "ISO-8583/MSG/AuthorizationRequestResponse.h"

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
using namespace ISO_8583::DTE;

namespace ISO_8583 {
	namespace MSG {
		// 7220000102C0880000000000000000000000000000000000
		const Bitmaps		AuthorizationRequestResponse::mandatoryBits(11,
			Bitmap::PrimaryAccountNumber,
			Bitmap::ProcessingCode,
			Bitmap::TransactionAmount,
			Bitmap::TransmissionDateAndTime,
			Bitmap::SystemsTraceAuditNumber,
			Bitmap::AcquiringInstitutionIdentificationCode,
#if STD_ISO_8583 == 1987
			Bitmap::ResponseCode,
			Bitmap::TransactionCurrencyCode,
#elif STD_ISO_8583 == 1993
#elif STD_ISO_8583 == 2003
#endif
			Bitmap::CardAcceptorTerminalIdentification,
			Bitmap::CardAcceptorIdentificationCode,
			Bitmap::SecurityRelatedControlInformation
			);

		// 001E44808C32002000000000000000000000000000000000
		const Bitmaps		AuthorizationRequestResponse::optionalBits(13,
#if STD_ISO_8583 == 1987
			Bitmap::TransactionLocalTime,
			Bitmap::TransactionLocalDate,
#elif STD_ISO_8583 == 1993
#elif STD_ISO_8583 == 2003
#endif
			Bitmap::ExpirationDate,
			Bitmap::SettlementDate,
#if STD_ISO_8583 == 1987
			Bitmap::MerchantType,
			Bitmap::PointOfServiceEntryMode,
			Bitmap::PointOfServiceConditionCode,
#elif STD_ISO_8583 == 1993
#elif STD_ISO_8583 == 2003
#endif
			Bitmap::ForwardingInstitutionIdentificationCode,
			Bitmap::RetrievalReferenceNumber,
			Bitmap::CardAcceptorNameOrlocation,
			Bitmap::AdditionalResponseData,
			Bitmap::AdditionalDataNational
#if STD_ISO_8583 == 1987
			, Bitmap::NationalData
#elif STD_ISO_8583 == 1993
#elif STD_ISO_8583 == 2003
#endif
			);

		const Bitmaps& AuthorizationRequestResponse::mandatory() const {
			return mandatoryBits;
		}
		const Bitmaps& AuthorizationRequestResponse::optional() const {
			return optionalBits;
		}

		BinaryInputStream& AuthorizationRequestResponse::decode(BinaryInputStream& is) {
			is >> *this;
			return is;
		}
		BinaryOutputStream& AuthorizationRequestResponse::encode(BinaryOutputStream& os) const {
			os << *this;
			return os;
		}
		MSG_API_SCOPE BinaryInputStream& operator>>(BinaryInputStream& is, AuthorizationRequestResponse& ar) {
			is >> static_cast<Message&>(ar);
			return is;
		}
		MSG_API_SCOPE BinaryOutputStream& operator<<(BinaryOutputStream& os, const AuthorizationRequestResponse& arr) {
			os << static_cast<const Message&>(arr);
			return os;
		}
		void AuthorizationRequestResponse::dump(ostream& os) {
		}
		void AuthorizationRequestResponse::mapDTEs(Mandatory& mandatory, Optional& optional) const {
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
				case Bitmap::ResponseCode:
					mandatory.rc = dynamic_cast<ResponseCode*>(dte); break;

				case Bitmap::TransactionLocalTime:
					optional.tlt = dynamic_cast<TransactionLocalTime*>(dte); break;

				case Bitmap::TransactionLocalDate:
					optional.tld = dynamic_cast<TransactionLocalDate*>(dte); break;

#elif STD_ISO_8583 == 1993
#elif STD_ISO_8583 == 2003
#endif
				case Bitmap::ExpirationDate:
					optional.de = dynamic_cast<ExpirationDate*>(dte); break;

#if STD_ISO_8583 == 1987
				case Bitmap::MerchantType:
					optional.mt = dynamic_cast<MerchantType*>(dte);  break;

				case Bitmap::PointOfServiceEntryMode:
					optional.posem = dynamic_cast<PointOfServiceEntryMode*>(dte); break;

				case Bitmap::PointOfServiceConditionCode:
					optional.poscc = dynamic_cast<PointOfServiceConditionCode*>(dte); break;

#elif STD_ISO_8583 == 1993
#elif STD_ISO_8583 == 2003
#endif
				case Bitmap::AcquiringInstitutionIdentificationCode:
					mandatory.aiic = dynamic_cast<AcquiringInstitutionIdentificationCode*>(dte); break;

				case Bitmap::CardAcceptorTerminalIdentification:
					mandatory.cati = dynamic_cast<CardAcceptorTerminalIdentification*>(dte); break;

				case Bitmap::CardAcceptorIdentificationCode:
					mandatory.caic = dynamic_cast<CardAcceptorIdentificationCode*>(dte); break;

#if STD_ISO_8583 == 1987
				case Bitmap::TransactionCurrencyCode:
					mandatory.tcc = dynamic_cast<TransactionCurrencyCode*>(dte); break;
#elif STD_ISO_8583 == 1993
#elif STD_ISO_8583 == 2003
#endif

				case Bitmap::SecurityRelatedControlInformation:
					mandatory.srci = dynamic_cast<SecurityRelatedControlInformation*>(dte); break;

				case Bitmap::TransmissionDateAndTime:
					mandatory.tdat = dynamic_cast<TransmissionDateAndTime*>(dte); break;

					// optional
				case Bitmap::ForwardingInstitutionIdentificationCode:
					optional.fiic = dynamic_cast<ForwardingInstitutionIdentificationCode*>(dte); break;

				case Bitmap::RetrievalReferenceNumber:
					optional.rrn = dynamic_cast<RetrievalReferenceNumber*>(dte); break;

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
