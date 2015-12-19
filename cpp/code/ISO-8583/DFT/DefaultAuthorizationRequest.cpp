/*
 * DefaultAuthorizationRequest.cpp
 *
 *  Created on: 2 août 2015
 *      Author: FrancisANDRE
 */
#include <memory>

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

#include "ISO-8583/DFT/DefaultAuthorizationRequest.h"
#include "ISO-8583/DFT/DefaultAuthorizationRequestResponse.h"

using namespace std;
using namespace ISO_8583::DTE;

namespace ISO_8583 {
	namespace MSG {
		RequestResponse* concat2(Prefix,  AuthorizationRequest)::indication(InputStream& is, OutputStream& os) {
			Mandatory mandatory;
			Optional optional;

			mapDTEs(mandatory, optional);
			DataElement* dte;

			unique_ptr<concat2(Prefix,  AuthorizationRequestResponse)> arr(new concat2(Prefix,  AuthorizationRequestResponse) (origin()));

			dte = new PrimaryAccountNumber(*mandatory.pam);
			arr->addAndSet(dte);

			dte = new ProcessingCode(*mandatory.pc);
			arr->addAndSet(dte);

			dte = new TransactionAmount(*mandatory.ta);
			arr->addAndSet(dte);

			dte = new TransmissionDateAndTime(*mandatory.tdat);
			arr->addAndSet(dte);

			dte = new SystemsTraceAuditNumber(*mandatory.stan);
			arr->addAndSet(dte);

			dte = new AcquiringInstitutionIdentificationCode(*mandatory.aiic);
			arr->addAndSet(dte);

			dte = new SecurityRelatedControlInformation(*mandatory.srci);
			arr->addAndSet(dte);

			if (optional.airl) {
				dte = new AuthorizationIdentificationResponseLength(*optional.airl);
				arr->addAndSet(dte);
			}

			dte = new CardAcceptorTerminalIdentification(*mandatory.cati);
			arr->addAndSet(dte);

			dte = new CardAcceptorIdentificationCode(*mandatory.caic);
			arr->addAndSet(dte);

			dte = new TransactionCurrencyCode(*mandatory.tcc);
			arr->addAndSet(dte);
			byte foo = (*mandatory.pam)[1];

			ResponseCode* rc = new ResponseCode;
			if ((*mandatory.pam)[1] == 1)
				*rc = ResponseCodes::SuccessfulTransaction;
			else
				*rc = ResponseCodes::InvalidCardNumber;
			arr->addAndSet(rc);

			return arr.release();
		}

	}
}
