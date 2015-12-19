/*
 * NetworkRequestResponse.cpp
 *
 *  Created on: 28 juin 2015
 *      Author: FrancisANDRE
 */

#include <memory>
#include <stdexcept>
using  namespace std;

#include "ISO-8583/DTE/Bitmap.h"
#include "ISO-8583/MSG/NetworkRequestResponse.h"
using namespace ISO_8583::DTE;

namespace ISO_8583 {
	namespace MSG {
		// 723C448100C0880000000000000000000000000000000000
		const Bitmaps		NetworkRequestResponse::mandatoryBits(15,
			Bitmap::PrimaryAccountNumber,
			Bitmap::ProcessingCode,
			Bitmap::TransactionAmount,
			Bitmap::SystemsTraceAuditNumber,
#if STD_ISO_8583 == 1987
			Bitmap::TransactionLocalTime,
			Bitmap::TransactionLocalDate,
#elif STD_ISO_8583 == 1993
#elif STD_ISO_8583 == 2003
#endif
			Bitmap::ExpirationDate,
			Bitmap::MerchantType,
#if STD_ISO_8583 == 1987
			Bitmap::PointOfServiceEntryMode,
			Bitmap::PointOfServiceConditionCode,
#elif STD_ISO_8583 == 1993
#elif STD_ISO_8583 == 2003
#endif
			Bitmap::AcquiringInstitutionIdentificationCode,
			Bitmap::CardAcceptorTerminalIdentification,
			Bitmap::CardAcceptorIdentificationCode,
			Bitmap::TransactionCurrencyCode,
			Bitmap::SecurityRelatedControlInformation
			);

		// 000000208C22002000000000000000000000000000000000
		const Bitmaps		NetworkRequestResponse::optionalBits(8,
			Bitmap::TransmissionDateAndTime,
#if STD_ISO_8583 == 1987
			Bitmap::AuthorizationIdentificationResponseLength,
#elif STD_ISO_8583 == 1993
#elif STD_ISO_8583 == 2003
#endif
			Bitmap::ForwardingInstitutionIdentificationCode,
			Bitmap::RetrievalReferenceNumber,
#if STD_ISO_8583 == 1987
			Bitmap::AuthorizationIdentificationResponse,
#elif STD_ISO_8583 == 1993
#elif STD_ISO_8583 == 2003
#endif
			Bitmap::CardAcceptorNameOrlocation,
			Bitmap::AdditionalDataNational
#if STD_ISO_8583 == 1987
			, Bitmap::NationalData
#elif STD_ISO_8583 == 1993
#elif STD_ISO_8583 == 2003
#endif
			);

		const Bitmaps& NetworkRequestResponse::mandatory() const {
			return mandatoryBits;
		}
		const Bitmaps& NetworkRequestResponse::optional() const {
			return optionalBits;
		}
		BinaryInputStream& NetworkRequestResponse::decode(BinaryInputStream& is) {
			is >> *this;
			return is;
		}
		BinaryOutputStream& NetworkRequestResponse::encode(BinaryOutputStream& os) const {
			os << *this;
			return os;
		}
		MSG_API_SCOPE BinaryInputStream& operator>>(BinaryInputStream& is, NetworkRequestResponse& ar) {
			is >> static_cast<Message&>(ar);
			return is;
		}
		MSG_API_SCOPE BinaryOutputStream& operator<<(BinaryOutputStream& os, const NetworkRequestResponse& ar) {
			os << static_cast<const Message&>(ar);
			return os;
		}
		void NetworkRequestResponse::dump(ostream& os) {
		}
	}
}
