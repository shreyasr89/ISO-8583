#ifndef BITMAP_H_
#define	BITMAP_H_

#include "ISO-8583/DTE/ISO-8583-DTE.h"
// https://github.com/zosrothko/poco.git
// sudo mount.cifs //idefix/git /home/francis/Desktop/WindowsShare -o user=FrancisANDRE
namespace ISO_8583 {
	namespace DTE {
		enum class Bitmap : unsigned char {
			ContinuationBit = 1,
			PrimaryAccountNumber = 2,
			ProcessingCode = 3,
			TransactionAmount = 4,
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			SettlementAmount = 5,
#elif STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
			ReconciliationAmount = 5,
#endif 
			CardHolderBillingAmount = 6,
			TransmissionDateAndTime = 7,
			CardHolderBillingFeeAmount = 8,
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			SettlementConversionRate = 9,
#elif STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
			ReconciliationConversionRate = 9,
#endif 
			CardHolderBillingConversionRate = 10,
			SystemsTraceAuditNumber = 11,
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			TransactionLocalTime = 12,
			TransactionLocalDate = 13,
#elif STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
			DateAndTimeLocalTransaction = 12,
			EffectiveDate = 13,
#endif 
			ExpirationDate = 14,
			SettlementDate = 15,
			ConversionDate = 16,
			CaptureDate = 17,
#if STD_CB2A == 150 || STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993
			MerchantType = 18,
#elif STD_ISO_8583 == 2003
			MessageErrorIndicator = 18,
#endif 
			AcquiringInstitutionCountryCode = 19,
			PrimaryAccountNumberCountryCode = 20,
#if STD_CB2A == 150 || STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993
			ForwardingInstitutionCountryCode = 21,
#elif  STD_ISO_8583 == 2003
			TransactionLifeCycleIdentificationData = 21,
#endif
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			PointOfServiceEntryMode = 22,
#elif  STD_ISO_8583 == 1993
			PointOfServiceDataCode = 22,
#elif  STD_ISO_8583 == 2003
			POSDataCode = 22,
#endif 
			CardSequenceNumber = 23,
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			NetworkInternationalIdentifier = 24,
			PointOfServiceConditionCode = 25,
			PointOfServicePINCaptureCode = 26,
			AuthorizationIdentificationResponseLength = 27,
			TransactionFeeAmount = 28,
			SettlementFeeAmount = 29,
			TransactionProcessingFeeAmount = 30,
			SettlementProcessingFeeAmount = 31,
#elif STD_ISO_8583 == 1993
			FunctionCode = 24,
			MessageReasonCode = 25,
			CardAcceptorBusinessCode = 26,
			ApprovalCodeLength = 27,
			DateReconciliation = 28,
			ReconciliationIndicator = 29,
			AmountsOriginal = 30,
			AcquirerReferenceData = 31,
#elif STD_ISO_8583 == 2003
			FunctionCode = 24,
			MessageReasonCode = 25,
			MerchantCategoryCode = 26,
			POSCapability = 27,
			DateReconciliation = 28,
			ReconciliationIndicator = 29,
			AmountsOriginal = 30,
			AcquirerReferenceNumber = 31,
#endif 
			AcquiringInstitutionIdentificationCode = 32,
			ForwardingInstitutionIdentificationCode = 33,
#if STD_CB2A == 150 || STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993
			PrimaryAccountNumberExtended = 34,
#elif STD_ISO_8583 == 2003
			ElectronicCommerceData = 34,
#endif 
			Track2Data = 35,
			Track3Data = 36,
			RetrievalReferenceNumber = 37,
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			AuthorizationIdentificationResponse = 38,
			ResponseCode = 39,
			ServiceRestrictionCode = 40,
#elif STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
			ApprovalCode = 38,
			ActionCode = 39,
			ServiceCode = 40,
#endif 
			CardAcceptorTerminalIdentification = 41,
			CardAcceptorIdentificationCode = 42,
			CardAcceptorNameOrlocation = 43,
			AdditionalResponseData = 44,
			Track1Data = 45,
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			AdditionalDataISO = 46,
#elif STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
			AmountsFees = 46,
#endif 
			AdditionalDataNational = 47,
			AdditionalDataPrivate = 48,
#if STD_CB2A == 150 || STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993
			TransactionCurrencyCode = 49,
#if STD_ISO_8583 == 1993
			ReconciliationCurrencyCode = 50,
#else
			SettlementCurrencyCode = 50,
#endif
			CardHolderBillingCurrencyCode = 51,
#elif STD_ISO_8583 == 2003
			VerificationData = 49,
			ReservedForISO_50 = 50,
			ReservedForISO_51 = 51,
#endif 
			PINData = 52,
			SecurityRelatedControlInformation = 53,
			AdditionalAmounts = 54,
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			ReservedISO_55 = 55,
			ReservedISO_56 = 56,
			ReservedNational_57 = 57,
			ReservedNational_58 = 58,
			NationalData = 59,
			ReservedPrivate_60 = 60,
			ReservedPrivate_61 = 61,
			ReservedPrivate_62 = 62,
			ReservedPrivate_63 = 63,
#elif STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
			ICCSystemRelatedData = 55,
			OriginalDataElements = 56,
			AuthorizationLifeCycleCode = 57,
			AuthorizingAgentInstitutionIdentificationCode = 58,
			TransportData = 59,
			ReservedForNationalUse_60 = 60,
			ReservedForNationalUse_61 = 61,
			ReservedForPrivateUse_62 = 62,
			ReservedForPrivateUse_63 = 63,
#endif 
			MACField = 64,

			ReservedForISOUse = 65,
#if STD_CB2A == 150 || STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 
#if STD_ISO_8583 == 1993
			OriginalFeesAmounts = 66,
#else
			SettlementCode = 66,
#endif
			ExtendedPaymentCode = 67,
			ReceivingInstitutionCountryCode = 68,
			SettlementInstitutionCountryCode = 69,
#if STD_ISO_8583 == 1993
			AuthorizingAgentInstitutionCountryCode = 70,
#else
			NetworkManagementInformationCode = 70,
#endif
			MessageNumber = 71,
#if STD_ISO_8583 == 1993
			DataRecord = 72,
#else
			MessageNumberLast = 72,
#endif
			DateAction = 73,
			NumberCredits = 74,
			NumberReversalCredits = 75,
			NumberDebits = 76,
			NumberReversalDebits = 77,
			NumberTransfer = 78,
			NumberReversalTransfer = 79,
			NumberInquiries = 80,
			NumberAuthorizations = 81,
#if STD_ISO_8583 == 1993
			NumberReversalInquiries = 82,
			NumberPayments = 83,
			NumberReversalPayments = 84,
			NumberFeeCollections = 85,
#else
			CreditsProcessingFeeAmount = 82,
			CreditsTransactionFeeAmount = 83,
			DebitsProcessingFeeAmount = 84,
			DebitsTransactionFeeAmount = 85,
#endif
			CreditsAmount = 86,
			ReversalCreditsAmount = 87,
			DebitsAmount = 88,
			ReversalDebitsAmount = 89,
#if STD_ISO_8583 == 1993
			NumberReversalAuthorizations = 90,
			TransactionDestinationInstitutionCountryCode = 91,
			TransactionOriginatorInstitutionCountryCode = 92,
			TransactionDestinationInstitutionIdentificationCode = 93,
			TransactionOriginatorInstitutionIdentificationCode = 94,
			CardIssuerReferenceData = 95,
			KeyManagementData = 96,
			NetReconciliationAmount = 97,
#else
			OriginalDataElements = 90,
			FileUpdateCode = 91,
			FileSecurityCode = 92,
			ResponseIndicator = 93,
			ServiceIndicator = 94,
			ReplacementAmounts = 95,
			MessageSecurityCode = 96,
			AmountNetSettlement = 97,
#endif
#elif  STD_ISO_8583 == 2003
			AmountsOriginalFees = 66,
			ExtendedPaymentData = 67,
			FileTransferMessageControl = 68,
			FileTransferControlData = 69,
			FileTransferDescriptionData = 70,
			ReservedForISOUse_71 = 71,
			DataRecord = 72,
			DateAction = 73,
			ReconciliationDataPrimary = 74,
			ReconciliationDataSecondary = 75,
			ReservedForISOUse_76 = 76,
			ReservedForISOUse_77 = 77,
			ReservedForISOUse_78 = 78,
			ReservedForISOUse_79 = 79,
			ReservedForISOUse_80 = 80,
			ReservedForISOUse_81 = 81,
			ReservedForISOUse_82 = 82,
			ReservedForISOUse_83 = 83,
			ReservedForISOUse_84 = 84,
			ReservedForISOUse_85 = 85,
			ReservedForISOUse_86 = 86,
			ReservedForISOUse_87 = 87,
			ReservedForISOUse_88 = 88,
			ReservedForISOUse_89 = 89,
			ReservedForISOUse_90 = 90,
			ReservedForISOUse_91 = 91,
			ReservedForISOUse_92 = 92,
			TransactionDestinationInstitutionIdentificationCode = 93,
			TransactionOriginatorInstitutionIdentificationCode = 94,
			CardIssuerReferenceData = 95,
			KeyManagementData = 96,
			NetReconciliationAmount = 97,
#endif 
			Payee = 98,
			SettlementInstitutionIdentificationCode = 99,
			ReceivingInstitutionIdentificationCode = 100,
			FileName = 101,
			AccountIdentification1 = 102,
			AccountIdentification2 = 103,
#if STD_CB2A == 150 || STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993
			TransactionDescription = 104,
			ChargebackCreditsAmount = 105,
			ChargebackDebitsAmount = 106,
			ChargebackCreditsNumber = 107,
			ChargebackDebitsNumber = 108,
			CreditsFeeAmounts = 109,
			DebitsFeeAmounts = 110,
			LAST = DebitsFeeAmounts,
#elif  STD_ISO_8583 == 2003
			TransactionSpecificData = 104,
			ReconciliationFeeAmountsCredit = 109,
			ReconciliationFeeAmountsDebit = 110,
			LAST = ReconciliationFeeAmountsDebit,
#endif 
		};

		DTE_API_SCOPE const char* toString(Bitmap bitmap);
	}
}
#endif
