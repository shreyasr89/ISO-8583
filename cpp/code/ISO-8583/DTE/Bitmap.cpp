#include "ISO-8583/DTE/Bitmap.h"

namespace ISO_8583 {
	namespace DTE {
		DTE_API_SCOPE	const char* toString(Bitmap bitmap) {
			const char* literal = "???";
			switch (bitmap) {
			case Bitmap::ContinuationBit:			literal = "ContinuationBit"; break;
			case Bitmap::PrimaryAccountNumber:		literal = "PrimaryAccountNumber"; break;
			case Bitmap::ProcessingCode:			literal = "ProcessingCode"; break;
			case Bitmap::TransactionAmount:			literal = "TransactionAmount"; break;
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			case Bitmap::SettlementAmount:			literal = "SettlementAmount"; break;
#elif STD_ISO_8583 == 2003
			case Bitmap::ReconciliationAmount:		literal = "ReconciliationAmount"; break;
#endif 
			case Bitmap::CardHolderBillingAmount:	literal = "CardHolderBillingAmount"; break;
			case Bitmap::TransmissionDateAndTime:	literal = "TransmissionDateAndTime"; break;
			case Bitmap::CardHolderBillingFeeAmount:literal = "CardHolderBillingFeeAmount"; break;
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			case Bitmap::SettlementConversionRate:	literal = "SettlementConversionRate"; break;
#elif STD_ISO_8583 == 2003
			case Bitmap::ReconciliationConversionRate: literal = "ReconciliationConversionRate"; break;
#endif 
			case Bitmap::CardHolderBillingConversionRate: literal = "CardHolderBillingConversionRate"; break;
			case Bitmap::SystemsTraceAuditNumber:	literal = "SystemsTraceAuditNumber"; break;
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			case Bitmap::TransactionLocalTime:		literal = "TransactionLocalTime"; break;
			case Bitmap::TransactionLocalDate:		literal = "TransactionLocalDate"; break;
#elif STD_ISO_8583 == 2003
			case Bitmap::DateAndTimeLocalTransaction: literal = "DateAndTimeLocalTransaction"; break;
			case Bitmap::EffectiveDate: literal = "EffectiveDate"; break;
#endif 
			case Bitmap::ExpirationDate:			literal = "ExpirationDate"; break;
			case Bitmap::SettlementDate:			literal = "SettlementDate"; break;
			case Bitmap::ConversionDate:			literal = "ConversionDate"; break;
			case Bitmap::CaptureDate:				literal = "CaptureDate"; break;
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			case Bitmap::MerchantType:				literal = "MerchantType"; break;
#elif STD_ISO_8583 == 2003
			case Bitmap::MessageErrorIndicator: literal = "MessageErrorIndicator"; break;
#endif 
			case Bitmap::AcquiringInstitutionCountryCode: literal = "AcquiringInstitutionCountryCode"; break;
			case Bitmap::PrimaryAccountNumberCountryCode: literal = "PrimaryAccountNumberCountryCode"; break;
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			case Bitmap::ForwardingInstitutionCountryCode: literal = "ForwardingInstitutionCountryCode"; break;
			case Bitmap::PointOfServiceEntryMode:	literal = "PointOfServiceEntryMode"; break;
#elif STD_ISO_8583 == 2003
			case Bitmap::TransactionLifeCycleIdentificationData: literal = "TransactionLifeCycleIdentificationData"; break;
			case Bitmap::POSDataCode: literal = "POSDataCode"; break;
#endif 
			case Bitmap::CardSequenceNumber:		literal = "CardSequenceNumber"; break;
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			case Bitmap::NetworkInternationalIdentifier: literal = "NetworkInternationalIdentifier"; break;
			case Bitmap::PointOfServiceConditionCode: literal = "PointOfServiceConditionCode"; break;
			case Bitmap::PointOfServicePINCaptureCode: literal = "PointOfServicePINCaptureCode"; break;
			case Bitmap::AuthorizationIdentificationResponseLength: literal = "AuthorizationIdentificationResponseLength"; break;
			case Bitmap::TransactionFeeAmount:		literal = "TransactionFeeAmount"; break;
			case Bitmap::SettlementFeeAmount:		literal = "SettlementFeeAmount"; break;
			case Bitmap::TransactionProcessingFeeAmount: literal = "TransactionProcessingFeeAmount"; break;
			case Bitmap::SettlementProcessingFeeAmount: literal = "SettlementProcessingFeeAmount"; break;
#elif STD_ISO_8583 == 2003
			case Bitmap::FunctionCode: literal = "FunctionCode"; break;
			case Bitmap::MessageReasonCode: literal = "MessageReasonCode"; break;
			case Bitmap::MerchantCategoryCode: literal = "MerchantCategoryCode"; break;
			case Bitmap::POSCapability: literal = "POSCapability"; break;
			case Bitmap::DateReconciliation: literal = "DateReconciliation"; break;
			case Bitmap::ReconciliationIndicator: literal = "ReconciliationIndicator"; break;
			case Bitmap::AmountsOriginal: literal = "AmountsOriginal"; break;
			case Bitmap::AcquirerReferenceNumber: literal = "AcquirerReferenceNumber"; break;
#endif 
			case Bitmap::AcquiringInstitutionIdentificationCode: literal = "AcquiringInstitutionIdentificationCode"; break;
			case Bitmap::ForwardingInstitutionIdentificationCode: literal = "ForwardingInstitutionIdentificationCode"; break;
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			case Bitmap::PrimaryAccountNumberExtended: literal = "PrimaryAccountNumberExtended"; break;
#elif STD_ISO_8583 == 2003
			case Bitmap::ElectronicCommerceData: literal = "ElectronicCommerceData"; break;
#endif 
			case Bitmap::Track2Data:				literal = "Track2Data"; break;
			case Bitmap::Track3Data:				literal = "Track3Data"; break;
			case Bitmap::RetrievalReferenceNumber:	literal = "RetrievalReferenceNumber"; break;
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			case Bitmap::AuthorizationIdentificationResponse: literal = "AuthorizationIdentificationResponse"; break;
			case Bitmap::ResponseCode:				literal = "ResponseCode"; break;
			case Bitmap::ServiceRestrictionCode:	literal = "ServiceRestrictionCode"; break;
#elif STD_ISO_8583 == 2003
			case Bitmap::ApprovalCode: literal = "ApprovalCode"; break;
			case Bitmap::ActionCode: literal = "ActionCode"; break;
			case Bitmap::ServiceCode: literal = "ServiceCode"; break;
#endif 
			case Bitmap::CardAcceptorTerminalIdentification: literal = "CardAcceptorTerminalIdentification"; break;
			case Bitmap::CardAcceptorIdentificationCode: literal = "CardAcceptorIdentificationCode"; break;
			case Bitmap::CardAcceptorNameOrlocation: literal = "CardAcceptorNameOrlocation"; break;
			case Bitmap::AdditionalResponseData:	literal = "AdditionalResponseData"; break;
			case Bitmap::Track1Data:				literal = "Track1Data"; break;
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			case Bitmap::AdditionalDataISO:			literal = "AdditionalDataISO"; break;
#elif STD_ISO_8583 == 2003
			case Bitmap::AmountsFees: literal = "AmountsFees"; break;
#endif 
			case Bitmap::AdditionalDataNational:	literal = "AdditionalDataNational"; break;
			case Bitmap::AdditionalDataPrivate:		literal = "AdditionalDataPrivate"; break;
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			case Bitmap::TransactionCurrencyCode:	literal = "TransactionCurrencyCode"; break;
			case Bitmap::SettlementCurrencyCode:	literal = "SettlementCurrencyCode"; break;
			case Bitmap::CardHolderBillingCurrencyCode: literal = "CardHolderBillingCurrencyCode"; break;
#elif STD_ISO_8583 == 2003
			case Bitmap::VerificationData: literal = "VerificationData"; break;
			case Bitmap::ReservedForISO_50: literal = "ReservedForISO_50"; break;
			case Bitmap::ReservedForISO_51: literal = ""; break;
#endif 
			case Bitmap::PINData: literal = "PINData"; break;
			case Bitmap::SecurityRelatedControlInformation: literal = "SecurityRelatedControlInformation"; break;
			case Bitmap::AdditionalAmounts: literal = "AdditionalAmounts"; break;
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			case Bitmap::ReservedISO_55: literal = ""; break;
			case Bitmap::ReservedISO_56: literal = ""; break;
			case Bitmap::ReservedNational_57: literal = ""; break;
			case Bitmap::ReservedNational_58: literal = ""; break;
			case Bitmap::NationalData: literal = "NationalData"; break;
			case Bitmap::ReservedPrivate_60: literal = ""; break;
			case Bitmap::ReservedPrivate_61: literal = ""; break;
			case Bitmap::ReservedPrivate_62: literal = ""; break;
			case Bitmap::ReservedPrivate_63: literal = ""; break;
#elif STD_ISO_8583 == 2003
			case Bitmap::ICCSystemRelatedData: literal = ""; break;
			case Bitmap::OriginalDataElements: literal = ""; break;
			case Bitmap::AuthorizationLifeCycleCode: literal = ""; break;
			case Bitmap::AuthorizingAgentInstitutionIdentificationCode: literal = ""; break;
			case Bitmap::TransportData: literal = ""; break;
			case Bitmap::ReservedForNationalUse_60: literal = ""; break;
			case Bitmap::ReservedForNationalUse_61: literal = ""; break;
			case Bitmap::ReservedForPrivateUse_62: literal = ""; break;
			case Bitmap::ReservedForPrivateUse_63: literal = ""; break;
#endif 
			case Bitmap::MACField: literal = "MACField"; break;

			case Bitmap::ReservedForISOUse: literal = ""; break;
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			case Bitmap::SettlementCode: literal = "SettlementCode"; break;
			case Bitmap::ExtendedPaymentCode: literal = "ExtendedPaymentCode"; break;
			case Bitmap::ReceivingInstitutionCountryCode: literal = "ReceivingInstitutionCountryCode"; break;
			case Bitmap::SettlementInstitutionCountryCode: literal = "SettlementInstitutionCountryCode"; break;
			case Bitmap::NetworkManagementInformationCode: literal = "NetworkManagementInformationCode"; break;
			case Bitmap::MessageNumber: literal = "MessageNumber"; break;
			case Bitmap::MessageNumberLast: literal = "MessageNumberLast"; break;
			case Bitmap::DateAction: literal = "DateAction"; break;
			case Bitmap::NumberCredits: literal = "CreditsNumber"; break;
			case Bitmap::NumberReversalCredits: literal = "CreditsReversalNumber"; break;
			case Bitmap::NumberDebits: literal = "DebitsNumber"; break;
			case Bitmap::NumberReversalDebits: literal = "DebitsReversalNumber"; break;
			case Bitmap::NumberTransfer: literal = "TransferNumber"; break;
			case Bitmap::NumberReversalTransfer: literal = "TransferReversalNumber"; break;
			case Bitmap::NumberInquiries: literal = "InquiriesNumber"; break;
			case Bitmap::NumberAuthorizations: literal = "AuthorizationsNumber"; break;
			case Bitmap::CreditsProcessingFeeAmount: literal = "CreditsProcessingFeeAmount"; break;
			case Bitmap::CreditsTransactionFeeAmount: literal = ""; break;
			case Bitmap::DebitsProcessingFeeAmount: literal = ""; break;
			case Bitmap::DebitsTransactionFeeAmount: literal = ""; break;
			case Bitmap::CreditsAmount: literal = ""; break;
			case Bitmap::ReversalCreditsAmount: literal = ""; break;
			case Bitmap::DebitsAmount: literal = ""; break;
			case Bitmap::ReversalDebitsAmount: literal = ""; break;
			case Bitmap::OriginalDataElements: literal = ""; break;
			case Bitmap::FileUpdateCode: literal = ""; break;
			case Bitmap::FileSecurityCode: literal = ""; break;
			case Bitmap::ResponseIndicator: literal = ""; break;
			case Bitmap::ServiceIndicator: literal = ""; break;
			case Bitmap::ReplacementAmounts: literal = ""; break;
			case Bitmap::MessageSecurityCode: literal = ""; break;
			case Bitmap::AmountNetSettlement: literal = ""; break;
#elif STD_ISO_8583 == 2003
			case Bitmap::AmountsOriginalFees: literal = ""; break;
			case Bitmap::ExtendedPaymentData: literal = ""; break;
			case Bitmap::FileTransferMessageControl: literal = ""; break;
			case Bitmap::FileTransferControlData: literal = ""; break;
			case Bitmap::FileTransferDescriptionData: literal = ""; break;
			case Bitmap::ReservedForISOUse_71: literal = ""; break;
			case Bitmap::DataRecord: literal = ""; break;
			case Bitmap::DateAction: literal = ""; break;
			case Bitmap::ReconciliationDataPrimary: literal = ""; break;
			case Bitmap::ReconciliationDataSecondary: literal = ""; break;
			case Bitmap::ReservedForISOUse_76: literal = ""; break;
			case Bitmap::ReservedForISOUse_77: literal = ""; break;
			case Bitmap::ReservedForISOUse_78: literal = ""; break;
			case Bitmap::ReservedForISOUse_79: literal = ""; break;
			case Bitmap::ReservedForISOUse_80: literal = ""; break;
			case Bitmap::ReservedForISOUse_81: literal = ""; break;
			case Bitmap::ReservedForISOUse_82: literal = ""; break;
			case Bitmap::ReservedForISOUse_83: literal = ""; break;
			case Bitmap::ReservedForISOUse_84: literal = ""; break;
			case Bitmap::ReservedForISOUse_85: literal = ""; break;
			case Bitmap::ReservedForISOUse_86: literal = ""; break;
			case Bitmap::ReservedForISOUse_87: literal = ""; break;
			case Bitmap::ReservedForISOUse_88: literal = ""; break;
			case Bitmap::ReservedForISOUse_89: literal = ""; break;
			case Bitmap::ReservedForISOUse_90: literal = ""; break;
			case Bitmap::ReservedForISOUse_91: literal = ""; break;
			case Bitmap::ReservedForISOUse_92: literal = ""; break;
			case Bitmap::TransactionDestinationInstitutionIdentificationCode: literal = ""; break;
			case Bitmap::TransactionOriginatorInstitutionIdentificationCode: literal = ""; break;
			case Bitmap::CardIssuerReferenceData: literal = ""; break;
			case Bitmap::KeyManagementData: literal = ""; break;
			case Bitmap::NetReconciliationAmount: literal = ""; break;
#endif 
			case Bitmap::Payee: literal = "Payee"; break;
			case Bitmap::SettlementInstitutionIdentificationCode: literal = "SettlementInstitutionIdentificationCode"; break;
			case Bitmap::ReceivingInstitutionIdentificationCode: literal = "ReceivingInstitutionIdentificationCode"; break;
			case Bitmap::FileName: literal = "FileName"; break;
			case Bitmap::AccountIdentification1: literal = "AccountIdentification1"; break;
			case Bitmap::AccountIdentification2: literal = "AccountIdentification2"; break;
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			case Bitmap::TransactionDescription: literal = "TransactionDescription"; break;
#elif STD_ISO_8583 == 2003
			case Bitmap::TransactionSpecificData: literal = ""; break;
			case Bitmap::ReconciliationFeeAmountsCredit: literal = ""; break;
			case Bitmap::ReconciliationFeeAmountsDebit: literal = ""; break;
#endif 
			}
			return literal;
		}
	}
}
