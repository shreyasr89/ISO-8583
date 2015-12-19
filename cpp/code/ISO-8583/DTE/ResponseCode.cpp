/*
 * ResponseCodes.cpp
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/ResponseCode.h"

namespace ISO_8583 {
namespace DTE {
	DTE_API_SCOPE const char* toString(const ResponseCodes& responseCode) {
		const char* literal = "???";
		switch (responseCode) {
			case ResponseCodes::SuccessfulTransaction: literal = "SuccessfulTransaction"; break;
			case ResponseCodes::ReferToCardIssuer: literal = "ReferToCardIssuer"; break;
			case ResponseCodes::ReferToCaseIssuerSpecialCondition: literal = "ReferToCaseIssuerSpecialCondition"; break;
			case ResponseCodes::InvalidMerchant: literal = "InvalidMerchant"; break;
			case ResponseCodes::Pickup: literal = "Pickup"; break;
			case ResponseCodes::DoNotHonour: literal = "DoNotHonour"; break;
			case ResponseCodes::Error: literal = "Error"; break;
			case ResponseCodes::PickupCardSpecialCondition: literal = "PickupCardSpecialCondition"; break;
			case ResponseCodes::HonourWithIdentification: literal = "HonourWithIdentification"; break;
			case ResponseCodes::RequestInProgress: literal = "RequestInProgress"; break;
			case ResponseCodes::ApprovedForPartialAmount: literal = "ApprovedForPartialAmount"; break;
			case ResponseCodes::ApprovedVIP: literal = "ApprovedVIP"; break;
			case ResponseCodes::InvalidTransaction: literal = "InvalidTransaction"; break;
			case ResponseCodes::InvalidAmount: literal = "InvalidAmount"; break;
			case ResponseCodes::InvalidCardNumber: literal = "InvalidCardNumber"; break;
			case ResponseCodes::NoSuchIssuer: literal = "NoSuchIssuer"; break;
			case ResponseCodes::ApprovedUpdateTrack3 : literal = "ApprovedUpdateTrack3"; break;
			case ResponseCodes::CustomerCancellation: literal = "CustomerCancellation"; break;
			case ResponseCodes::CustormerDispute: literal = "CustormerDispute"; break;
			case ResponseCodes::ReEnterTransaction: literal = "ReEnterTransaction"; break;
			case ResponseCodes::InvalidResponse: literal = "InvalidResponse"; break;
			case ResponseCodes::NoActionTaken: literal = "NoActionTaken"; break;
			case ResponseCodes::SuspectedMalfunction: literal = "SuspectedMalfunction"; break;
			case ResponseCodes::UnacceptableTransactionFee: literal = "UnacceptableTransactionFee"; break;
		}
		return literal;
	}

	
	SERIALIZE(ResponseCode)
		string ResponseCode::toString() const {
			string s(str());
			return s;
		}
}
}
