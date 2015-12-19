#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <typeinfo> 
using namespace std;

#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"

#include "ISO-8583/MSG/ISO-8583-MSG.h"

#include "ISO-8583/DTE/Bitmap.h"

#if STD_CB2A == 150 || STD_ISO_8583 == 1987
#include "ISO-8583/DTE/AccountIdentification1.h"
#include "ISO-8583/DTE/AccountIdentification2.h"
#include "ISO-8583/DTE/AcquiringInstitutionIdentificationCode.h"
#include "ISO-8583/DTE/AdditionalDataNational.h"
#include "ISO-8583/DTE/AdditionalDataPrivate.h"
#include "ISO-8583/DTE/AdditionalResponseData.h"
#include "ISO-8583/DTE/CardHolderBillingAmount.h"
#include "ISO-8583/DTE/CardHolderBillingFeeAmount.h"
#include "ISO-8583/DTE/TransactionAmount.h"
#include "ISO-8583/DTE/AdditionalAmounts.h"
#include "ISO-8583/DTE/CardAcceptorIdentificationCode.h"
#include "ISO-8583/DTE/CardAcceptorNameOrlocation.h"
#include "ISO-8583/DTE/CardAcceptorTerminalIdentification.h"
#include "ISO-8583/DTE/CardIssuerReferenceData.h"
#include "ISO-8583/DTE/CardSequenceNumber.h"
#include "ISO-8583/DTE/CardHolderBillingConversionRate.h"
#include "ISO-8583/DTE/AcquiringInstitutionCountryCode.h"
#include "ISO-8583/DTE/PrimaryAccountNumberCountryCode.h"
#include "ISO-8583/DTE/CaptureDate.h"
#include "ISO-8583/DTE/ConversionDate.h"
#include "ISO-8583/DTE/ExpirationDate.h"
#include "ISO-8583/DTE/SettlementDate.h"
#include "ISO-8583/DTE/FileName.h"
#include "ISO-8583/DTE/ForwardingInstitutionCountryCode.h"
#include "ISO-8583/DTE/ForwardingInstitutionIdentificationCode.h"
#include "ISO-8583/DTE/MACField.h"
#include "ISO-8583/DTE/OriginalDataElements.h"
#include "ISO-8583/DTE/PINData.h"
#include "ISO-8583/DTE/Payee.h"
#include "ISO-8583/DTE/PrimaryAccountNumber.h"
#include "ISO-8583/DTE/ProcessingCode.h"
#include "ISO-8583/DTE/ReceivingInstitutionIdentificationCode.h"
#include "ISO-8583/DTE/RetrievalReferenceNumber.h"
#include "ISO-8583/DTE/SecurityRelatedControlInformation.h"
#include "ISO-8583/DTE/SettlementInstitutionIdentificationCode.h"
#include "ISO-8583/DTE/SystemsTraceAuditNumber.h"
#include "ISO-8583/DTE/Track1Data.h"
#include "ISO-8583/DTE/Track2Data.h"
#include "ISO-8583/DTE/Track3Data.h"
#include "ISO-8583/DTE/NationalData.h"
#include "ISO-8583/DTE/TransmissionDateAndTime.h"
#include "ISO-8583/DTE/TransactionLocalDate.h"
#include "ISO-8583/DTE/TransactionLocalTime.h"
#include "ISO-8583/DTE/MerchantType.h"
#include "ISO-8583/DTE/ResponseCode.h"
#include "ISO-8583/DTE/ServiceRestrictionCode.h"
#include "ISO-8583/DTE/TransactionCurrencyCode.h"
#include "ISO-8583/DTE/PointOfServiceEntryMode.h"
#include "ISO-8583/DTE/NetworkInternationalIdentifier.h"
#include "ISO-8583/DTE/PointOfServiceConditionCode.h"
#include "ISO-8583/DTE/PointOfServicePINCaptureCode.h"
#include "ISO-8583/DTE/AuthorizationIdentificationResponse.h"
#include "ISO-8583/DTE/AuthorizationIdentificationResponseLength.h"
#include "ISO-8583/DTE/TransactionFeeAmount.h"
#include "ISO-8583/DTE/SettlementFeeAmount.h"
#include "ISO-8583/DTE/TransactionProcessingFeeAmount.h"
#include "ISO-8583/DTE/SettlementProcessingFeeAmount.h"
#include "ISO-8583/DTE/SettlementCurrencyCode.h"
#include "ISO-8583/DTE/CardHolderBillingCurrencyCode.h"
#include "ISO-8583/DTE/PointOfServiceEntryMode.h"



#endif
#if STD_ISO_8583 == 2003
#include "ISO-8583/DTE/2003/NetReconciliationAmount.h"
#include "ISO-8583/DTE/2003/AuthorizationLifeCycleCode.h"
#include "ISO-8583/DTE/2003/AuthorizingAgentInstitutionIdentificationCode.h"
#include "ISO-8583/DTE/2003/DataRecord.h"
#include "ISO-8583/DTE/2003/DateAction.h"
#include "ISO-8583/DTE/2003/EffectiveDate.h"
#include "ISO-8583/DTE/2003/ElectronicCommerceData.h"
#include "ISO-8583/DTE/2003/ExtendedPaymentData.h"
#include "ISO-8583/DTE/2003/FileTransferControlData.h"
#include "ISO-8583/DTE/2003/FileTransferDescriptionData.h"
#include "ISO-8583/DTE/2003/FileTransferMessageControl.h"
#include "ISO-8583/DTE/2003/ICCSystemRelatedData.h"
#include "ISO-8583/DTE/2003/KeyManagementData.h"
#include "ISO-8583/DTE/2003/ReconciliationDataPrimary.h"
#include "ISO-8583/DTE/2003/ReconciliationDataSecondary.h"
#include "ISO-8583/DTE/2003/ReconciliationFeeAmountsCredit.h"
#include "ISO-8583/DTE/2003/ReconciliationFeeAmountsDebit.h"
#include "ISO-8583/DTE/2003/TransactionDestinationInstitutionIdentificationCode.h"
#include "ISO-8583/DTE/2003/TransactionLifeCycleIdentificationData.h"
#include "ISO-8583/DTE/2003/TransactionOriginatorInstitutionIdentificationCode.h"
#include "ISO-8583/DTE/2003/TransactionSpecificData.h"
#include "ISO-8583/DTE/2003/VerificationData.h"
#include "ISO-8583/DTE/2003/ActionCode.h"
#include "ISO-8583/DTE/2003/AcquirerReferenceNumber.h"
#include "ISO-8583/DTE/2003/AmountReconciliation.h"
#include "ISO-8583/DTE/2003/AmountsFees.h"
#include "ISO-8583/DTE/2003/AmountsOriginal.h"
#include "ISO-8583/DTE/2003/ApprovalCode.h"
#include "ISO-8583/DTE/2003/ConversionRateReconciliation.h"
#include "ISO-8583/DTE/2003/DateAndTimeLocalTransaction.h"
#include "ISO-8583/DTE/2003/FunctionCode.h"
#include "ISO-8583/DTE/2003/DateReconciliation.h"
#include "ISO-8583/DTE/2003/MerchantCategoryCode.h"
#include "ISO-8583/DTE/2003/POSDataCode.h"
#include "ISO-8583/DTE/2003/MessageReasonCode.h"
#include "ISO-8583/DTE/2003/POSCapability.h"
#include "ISO-8583/DTE/2003/ReconciliationIndicator.h"
#include "ISO-8583/DTE/2003/ServiceCode.h"
#include "ISO-8583/DTE/2003/MessageErroIndicator.h"
#endif

#include "ISO-8583/DTT/Bitmaps.h"
#include "ISO-8583/DTT/BinaryInputOutputStream.h"
#include "ISO-8583/MSG/AuthorizationRequest.h"
#include "ISO-8583/DFT/DefaultAuthorizationRequest.h"
#include "ISO-8583/DFT/DefaultAuthorizationRequestResponse.h"

#include "AuthorizationRequestTest.h"

using namespace ISO_8583::MSG;
using namespace ISO_8583::DTT;
using namespace ISO_8583::DTE;
using namespace ISO_8583::DTE::AdditionalDataNationalNamespace;
using namespace ISO_8583::DTE::NationalDataNamespace;


namespace ISO_8583 {
	namespace MSG {

		const static char* AccountIdentification1s[] = { "" };
		const static char* AccountIdentification2s[] = { "" };
		const static char* AcquirerReferenceNumbers[] = { "" };
		const static char* AcquiringInstitutionCountryCodes[] = { "" };
		const static char* AcquiringInstitutionIdentificationCodes[] = { "123431" };
		const static char* AdditionalDataNationals[] = { "a b!c-d(e_f)g 1234567" };
		const static char* AdditionalDataPrivates[] = { "" };
		const static char* AdditionalResponseDatas[] = { "" };
		const static char* AdditionalsAmounts[] = { "" };
		const static char* ApprovalCodes[] = { "123BCD" };
		const static char* AuthorizationIdentificationResponseLengths[] = { "6" };
		const static char* AuthorizationIdentificationResponses[] = { "123BCD" };
		const static char* AuthorizationLifeCycleCodes[] = { "" };
		const static char* AuthorizingAgentInstitutionIdentificationCodes[] = { "" };
		const static char* CardAcceptorIdentificationCodes[] = { "EEEEEEE" };
		const static char* CardAcceptorNameOrlocations[] = { "abc-def_ghi" };
		const static char* CardAcceptorTerminalIdentifications[] = { "555" };
		const static char* CardHolderBillingAmounts[] = { "" };
		const static char* CardHolderBillingConversionRates[] = { "" };
		const static char* CardHolderBillingFeeAmounts[] = { "" };
		const static char* CardIssuerReferenceDatas[] = { "" };
		const static char* CardSequenceNumbers[] = { "999" };
		const static char* DataRecords[] = { "" };
		const static char* DateActions[] = { "" };
		const static char* DateAndTimeLocalTransactions[] = { "083059" };
		const static char* TransmissionDateAndTimes[] = { "1234567890" };
		const static char* CaptureDates[] = { "" };
		const static char* ConversionDates[] = { "" };
		const static char* EffectiveDates[] = { "1405" };
		const static char* ExpirationDates[] = { "1510" };
		const static char* ReconciliationDates[] = { "" };
		const static char* SettlementDates[] = { "" };
		const static char* ElectronicCommerceDatas[] = { "" };
		const static char* ExtendedPaymentDatas[] = { "" };
		const static char* FeesAmountss[] = { "" };
		const static char* FileNames[] = { "" };
		const static char* FileTransferControlDatas[] = { "" };
		const static char* FileTransferDescriptionDatas[] = { "" };
		const static char* FileTransferMessageControls[] = { "" };
		const static char* ForwardingInstitutionIdentificationCodes[] = { "987654" };
		const static char* FunctionCodes[] = { "" };
		const static char* ICCSystemRelatedDatas[] = { "" };
		const static char* KeyManagementDatas[] = { "" };
		const static char* MACFields[] = { "" };
		const static char* MerchantCategoryCodes[] = { "" };
		const static char* MerchantTypes[] = { "8888" };
		const static char* MessageReasonCodes[] = { "22" };
		const static char* NationalDatas[] = { "\1\2\1\3__1234567890abcdef &\"'(-_)=!;.:/\1\4\1\5\1\6" };
		const static char* OriginalAmountss[] = { "" };
		const static char* OriginalDataElementss[] = { "" };
		const static char* OriginalFeesAmountss[] = { "" };
		const static char* PINDatas[] = { "A2C4E6G8" };
		const static char* POSCapabilitys[] = { "" };
		const static char* POSDataCodes[] = { "777" };
		const static char* Payees[] = { "" };
		const static char* PointOfServiceConditionCodes[] = { "22" };
		const static char* PointOfServiceEntryModes[] = { "777" };
		const static char* PrimaryAccountNumberCountryCodes[] = { "" };
		const static char* PrimaryAccountNumbers[] = { "1234567890123456" };
		const static char* ProcessingCodes[] = { "0" };
		const static char* ReceivingInstitutionIdentificationCodes[] = { "" };
		const static char* ReconciliationAmounts[] = { "" };
		const static char* ReconciliationConversionRates[] = { "" };
		const static char* ReconciliationDataPrimarys[] = { "" };
		const static char* ReconciliationDataSecondarys[] = { "" };
		const static char* ReconciliationFeeAmountsCredits[] = { "" };
		const static char* ReconciliationFeeAmountsDebits[] = { "" };
		const static char* ReconciliationIndicators[] = { "" };
		const static char* ReconciliationNetAmounts[] = { "" };
		const static char* ResponseCodes[] = { "00" };
		const static char* RetrievalReferenceNumbers[] = { "ABCD5678ijkl" };
		const static char* SecurityRelatedControlInformations[] = { "666" };
		const static char* ServiceCodes[] = { "" };
		const static char* SettlementInstitutionIdentificationCodes[] = { "" };
		const static char* SystemsTraceAuditNumbers[] = { "3333" };
		const static char* Track1Datas[] = { "" };
		const static char* Track2Datas[] = { "" };
		const static char* Track3Datas[] = { "" };
		const static char* TransactionAmounts[] = { "987654321" };
		const static char* TransactionCurrencyCodes[] = { "978" };
		const static char* TransactionDestinationInstitutionIdentificationCodes[] = { "" };
		const static char* TransactionLifeCycleIdentificationDatas[] = { "" };
		const static char* TransactionLocalDates[] = { "1215" };
		const static char* TransactionLocalTimes[] = { "235959" };
		const static char* TransactionOriginatorInstitutionIdentificationCodes[] = { "" };
		const static char* TransactionSpecificDatas[] = { "" };

		enum TestAdditionalDataNational {
			TestCodeDonneesPointService = 1,
			TestTypeSite = 2,
			TestConversionChamp = 3,
			TestNumeroDossier = 4,
			TestCapaciteAdditionnelleLectureCarte = 5,
			TestPointAcceptation = 6,
			TestSiret = 7,
			TestIDPA = 8,
			TestIDSA = 9
		};


		enum TestNationalData {
			TestCodeFonction = 1,
			TestRaisonDuMessage = 2,
			TestAnneeTransaction = 3,
			TestEnvironnementReglementaire = 4,
			TestITPAcceptation = 5,
			TestNumeroContratAccepteur = 6,
			TestNumeroSystemeAcceptation = 7,
			TestNumeroPointAcceptation = 9,
			TestCodePaysSystemAcceptation = 10,
			TestMontantCumuleParPorteur = 11,
			TestTASA = 12,
			TestITPPointAcceptation = 13,
			TestCryptogrammeVisuel = 14,
			TestTraitementCryptogrammeVisuel = 15,
			TestIdentificationTransaction = 16,
			TestCryptogrammeElectronique = 17,
			TestTypeSecurisation = 18,
			TestTraitementCryptogrammeElectronique = 19,
			TestMethodeAuthentificationPorteur = 20,
			TestMethodeCalculCryptogrammeElectronique = 21,
			TestResultat = 22,
			TestModeSecurisationTransactionModifiee = 23,
			TestComplementCommerceElectronique = 24,
			TestDenominationPortefeuilleNumerique = 25,
			TestIndicateurCommerceElectronique = 26,
			TestComplementPortefeuilleElectronique = 27,
			TestIdentifiantWallet = 28,
			TestAgentUniqueId = 29,
			TestTypeFacture = 30,
			TestServicesOptionels = 31
		};

		AuthorizationRequestTest::AuthorizationRequestTest(const std::string& name) :
			CppUnit::TestCase(name),
			factory("ISO-8583-DFT-1987") {
		}
		AuthorizationRequestTest::~AuthorizationRequestTest() {
		}
		void AuthorizationRequestTest::testAuthorizationRequest() {
			cout << endl;
			string hexa;
			{
				concat2(Prefix,  AuthorizationRequest) 	ar(Origin::Acquirer);
				Bitmaps mandatory = ar.mandatory();
				Bitmaps optional = ar.optional();
				for (int bitno = 1; bitno <= mandatory.size(); bitno++) {
					if (mandatory.get(bitno) || optional.get(bitno)) {
						DataElement* de = newDataElement(static_cast<Bitmap>(bitno));
						assert(de != NULL);
						if (de) {
							ar.addAndSet(de);
//							cout << typeid(*de).name()	<< "\t\t\tbitno=" << bitno	<< " " << de->toString() << endl;
						}
					}
				}
				BinaryOutputStream ss(1024);
				ss << ar;
				ss.flip();
				hexa = string_to_hex(ss.str(ss.remaining()));
//				cout << hexa << endl;
				int number = check(hexa);
				assert(number == ar.mandatory().count() + ar.optional().count());
			}
			{
				concat2(Prefix,  AuthorizationRequest) 	ar(Origin::Acquirer);
				Bitmaps mandatory = ar.mandatory();
				Bitmaps optional = ar.optional();
				optional.set((byte)Bitmap::PINData);		// should be ignored on input

				for (int bitno = 1; bitno <= mandatory.size(); bitno++) {
					if (mandatory.get(bitno) || optional.get(bitno)) {
						DataElement* de = newDataElement((Bitmap)bitno);
						assert(de != NULL);
						if (de) 
							ar.addAndSet(de);
					}
				}
				BinaryOutputStream ss(1024);
				ss << ar;
				ss.flip();
				hexa = string_to_hex(ss.str(ss.remaining()));
				std::cout << hexa << endl;
				int number = check(hexa);
				assert(number == ar.mandatory().count() + ar.optional().count());
			}
			{
				concat2(Prefix,  AuthorizationRequest) 	ar(Origin::Acquirer);
				Bitmaps mandatory = ar.mandatory();
				Bitmaps optional = ar.optional();

				mandatory.set((byte)Bitmap::TransactionAmount, false);

				for (int bitno = 1; bitno <= mandatory.size(); bitno++) {
					if (mandatory.get(bitno) || optional.get(bitno)) {
						DataElement* de = newDataElement((Bitmap)bitno);
						assert(de != NULL);
						if (de) 
							ar.addAndSet(de);
					}
				}
				BinaryOutputStream ss(1024);
				try {
					ss << ar;
					assert(false);
				}
				catch (const logic_error&) {
				}
			}
		}
		int AuthorizationRequestTest::check(const string& hexa) {
			int number = 0;
			concat2(Prefix,  AuthorizationRequest) 	ar(Origin::Acquirer);
			BinaryInputOutputStream ss(1024);
			string s = hex_to_string(hexa);

			ss << s;
			ss.flip();
			ss >> ar;
//			cout << endl;
			for (int no = 0; no < ar.fields.size(); no++) {
				DataElement* de = ar.fields[no];
//				std::cout << typeid(*de).name() << '=' << '\t' << de->toString() << endl;

// ======================================================================================
#define CHECK(var, type) \
			if (typeid(*var) == typeid(type)) { \
				type* dde = (type*)var; \
				assert(*dde == type##s[0]); \
				number += 1; \
			} else

// ======================================================================================
#if STD_ISO_8583 == 2003
				CHECK(de, AcquirerReferenceNumber)
				CHECK(de, AmountReconciliation)
				CHECK(de, AmountsFees)
				CHECK(de, AmountsOriginal)
				CHECK(de, ApprovalCode)
				CHECK(de, ConversionRateReconciliation)
				CHECK(de, DateAndTimeLocalTransaction)
				CHECK(de, DateReconciliation)
				CHECK(de, FunctionCode)
				CHECK(de, MerchantCategoryCode)
				CHECK(de, MessageReasonCode)
				CHECK(de, ReconciliationIndicator)
				CHECK(de, POSCapability)
				CHECK(de, POSDataCode)
				CHECK(de, ServiceCode)
				CHECK(de, NetReconciliationAmount)
				CHECK(de, AdditionalAmounts)
				CHECK(de, OriginalFeesAmounts)
				CHECK(de, AuthorizationLifeCycleCode)
				CHECK(de, AuthorizingAgentInstitutionIdentificationCode)
				CHECK(de, DataRecord)
				CHECK(de, DateAction)
				CHECK(de, EffectiveDate)
				CHECK(de, ElectronicCommerceData)
				CHECK(de, ExtendedPaymentData)
				CHECK(de, FileTransferControlData)
				CHECK(de, FileTransferDescriptionData)
				CHECK(de, FileTransferMessageControl)
				CHECK(de, ICCSystemRelatedData)
				CHECK(de, KeyManagementData)
				CHECK(de, MessageErrorIndicator)
				CHECK(de, ReconciliationDataPrimary)
				CHECK(de, ReconciliationDataSecondary)
				CHECK(de, ReconciliationFeeAmountsCredit)
				CHECK(de, ReconciliationFeeAmountsDebit)
				CHECK(de, TransactionDestinationInstitutionIdentificationCode)
				CHECK(de, TransactionLifeCycleIdentificationData)
				CHECK(de, TransactionOriginatorInstitutionIdentificationCode)
				CHECK(de, TransactionSpecificData)
				CHECK(de, VerificationData)
#endif
				CHECK(de, TransmissionDateAndTime)
//				CHECK(de, TransactionLocalTime)
				if (typeid(*de) == typeid(TransactionLocalTime)) {
					TransactionLocalTime* dde = (TransactionLocalTime*)de;
					assert(*dde == TransactionLocalTimes[0]);
					number += 1;
				} else
				CHECK(de, TransactionLocalDate)
				CHECK(de, MerchantType)
				CHECK(de, PointOfServiceEntryMode)
				CHECK(de, TransactionAmount)
				CHECK(de, AccountIdentification1)
				CHECK(de, AccountIdentification2)
				CHECK(de, AcquiringInstitutionIdentificationCode)
				CHECK(de, ResponseCode)
				if (typeid(*de) == typeid(AdditionalDataNational)) {
					AdditionalDataNational* dde = (AdditionalDataNational*)de;
					for (int no = 0; no < dde->fields.size(); no++) {
						Field* f = (Field*)dde->fields.at(no);
						cout << "AdditionalDataNational: " << typeid(*f).name() << endl;
					}
					number += 1;
				}
				else
				CHECK(de, AdditionalDataPrivate)
				CHECK(de, AdditionalResponseData)
				CHECK(de, CardHolderBillingAmount)
				CHECK(de, CardHolderBillingFeeAmount)
				CHECK(de, CardAcceptorIdentificationCode)
				CHECK(de, CardAcceptorNameOrlocation)
				CHECK(de, CardAcceptorTerminalIdentification)
				CHECK(de, CardIssuerReferenceData)
				CHECK(de, CardSequenceNumber)
				CHECK(de, CardHolderBillingConversionRate)
				CHECK(de, AcquiringInstitutionCountryCode)
				CHECK(de, PrimaryAccountNumberCountryCode)
				CHECK(de, CaptureDate)
				CHECK(de, ConversionDate)
				CHECK(de, ExpirationDate)
				CHECK(de, SettlementDate)
				CHECK(de, FileName)
				CHECK(de, ForwardingInstitutionIdentificationCode)
				CHECK(de, MACField)
				CHECK(de, OriginalDataElements)
				CHECK(de, PINData)
				CHECK(de, Payee)
				CHECK(de, PrimaryAccountNumber)
				if (typeid(*de) == typeid(ProcessingCode)) {
					ProcessingCode* dde = (ProcessingCode*)de;
					number += 1;
				}
				else
				CHECK(de, ReceivingInstitutionIdentificationCode)
				CHECK(de, RetrievalReferenceNumber)
				CHECK(de, SecurityRelatedControlInformation)
				CHECK(de, SettlementInstitutionIdentificationCode)
				CHECK(de, SystemsTraceAuditNumber)
				CHECK(de, Track1Data)
				CHECK(de, Track2Data)
				CHECK(de, Track3Data)
				CHECK(de, PointOfServiceEntryMode)
				CHECK(de, PointOfServiceConditionCode)
				CHECK(de, AuthorizationIdentificationResponse)
				CHECK(de, AuthorizationIdentificationResponseLength)
				CHECK(de, TransactionCurrencyCode)
				if (typeid(*de) == typeid(NationalData)) {
					NationalData* nd = (NationalData*)de;
					for (int no = 0; no < nd->fields().size(); no++) {
						Field* f = (Field*)nd->fields().at(no);
						cout << typeid(*f).name() << endl;
					}
					number += 1;
				}
				else {
					string message("AuthorizationRequestTest: unknown data element: ");
					message += typeid(*de).name();
					throw invalid_argument(message);
				}
			}
			cout << endl;
			return number;
		}

		DataElement* AuthorizationRequestTest::newDataElement(Bitmap bitno, int turn) {
			DataElement* de = Message::newDataElement(bitno);
			byte* tlv = NULL;
			int aaaa = 0;
			switch (bitno) {
#if STD_ISO_8583 == 2003
			case  Bitmap::ApprovalCode:
				ApprovalCode*ac;
				ac = (ApprovalCode*)de;
				*ac = ApprovalCodes[turn];
				break;
			case  Bitmap::DateAndTimeLocalTransaction:
				DateAndTimeLocalTransaction* dtlt;
				dtlt = (DateAndTimeLocalTransaction*)de;
				*dtlt = DateAndTimeLocalTransactions[turn];
				break;
			case  Bitmap::POSDataCode:
				POSDataCode* pdc;
				pdc = (POSDataCode*)de;
				*pdc = POSDataCodes[turn];
				break;
			case  Bitmap::MessageReasonCode:
				MessageReasonCode* mrc;
				mrc = (MessageReasonCode*)de;
				*mrc = MessageReasonCodes[turn];
				break;
			case  Bitmap::ActionCode:
				break;
			case  Bitmap::OriginalAmounts:
				break;
			case  Bitmap::AcquirerReferenceNumber:
				break;
			case  Bitmap::FeesAmounts:
				break;
			case  Bitmap::AuthorizationLifeCycleCode:
				break;
			case  Bitmap::AuthorizingAgentInstitutionIdentificationCode:
				break;
			case  Bitmap::ReconciliationAmount:
				break;
			case  Bitmap::ICCSystemRelatedData:
				break;
			case  Bitmap::ReconciliationConversionRate:
				break;
			case  Bitmap::DateReconciliation:
				break;
			case  Bitmap::ElectronicCommerceData:
				break;
			case  Bitmap::FunctionCode:
				break;
			case  Bitmap::MerchantCategoryCode:
				break;
			case  Bitmap::POSCapability:
				break;
			case  Bitmap::ReconciliationIndicator:
				break;
			case  Bitmap::ServiceCode:
				break;
			case  Bitmap::TransactionLifeCycleIdentificationData:
				break;
#endif
			case  Bitmap::TransmissionDateAndTime:
				TransmissionDateAndTime* dtt;
				dtt = (TransmissionDateAndTime*)de;
				*dtt = TransmissionDateAndTimes[turn];
				break;
			case  Bitmap::AcquiringInstitutionIdentificationCode:
				AcquiringInstitutionIdentificationCode* aiic;
				aiic = (AcquiringInstitutionIdentificationCode*)de;
				*aiic = AcquiringInstitutionIdentificationCodes[turn];
				break;
			case  Bitmap::AdditionalResponseData:
				break;
			case  Bitmap::AdditionalDataNational: {
				AdditionalDataNational*adn;
				adn = (AdditionalDataNational*)de;
				bitset<64> toAdd;
				toAdd.set(TestCodeDonneesPointService);
				toAdd.set(TestTypeSite);
				toAdd.set(TestConversionChamp);
				toAdd.set(TestNumeroDossier);
				toAdd.set(TestCapaciteAdditionnelleLectureCarte);
				toAdd.set(TestPointAcceptation);
				toAdd.set(TestSiret);
				toAdd.set(TestIDPA);
				toAdd.set(TestIDSA);
				addTLVs(adn, toAdd);
				adn->marshall();
				// 00111030333132362020202020202020202020
			} break;
			case  Bitmap::AdditionalDataPrivate:
				break;
			case  Bitmap::TransactionAmount:
				TransactionAmount* at;
				at = (TransactionAmount*)de;
				*at = TransactionAmounts[turn];
				break;
			case  Bitmap::CardHolderBillingAmount:
				break;
			case  Bitmap::CardHolderBillingFeeAmount:
				break;
			case  Bitmap::AdditionalAmounts:
				break;
			case  Bitmap::CardAcceptorTerminalIdentification:
				CardAcceptorTerminalIdentification*cati;
				cati = (CardAcceptorTerminalIdentification*)de;
				*cati = CardAcceptorTerminalIdentifications[turn];
				break;
			case  Bitmap::CardAcceptorIdentificationCode:
				CardAcceptorIdentificationCode*caic;
				caic = (CardAcceptorIdentificationCode*)de;
				*caic = CardAcceptorIdentificationCodes[turn];
				break;
			case  Bitmap::CardAcceptorNameOrlocation:
				CardAcceptorNameOrlocation*ccnol;
				ccnol = (CardAcceptorNameOrlocation*)de;
				*ccnol = CardAcceptorNameOrlocations[turn];
				break;
			case  Bitmap::CardSequenceNumber:
				CardSequenceNumber* csn;
				csn = (CardSequenceNumber*)de;
				*csn = CardSequenceNumbers[turn];
				break;
			case  Bitmap::ContinuationBit:
				break;
			case  Bitmap::CardHolderBillingConversionRate:
				break;
			case  Bitmap::AcquiringInstitutionCountryCode:
				break;
			case  Bitmap::PrimaryAccountNumberCountryCode:
				break;
			case  Bitmap::CaptureDate:
				break;
			case  Bitmap::ConversionDate:
				break;
			case  Bitmap::TransactionLocalDate:
				TransactionLocalDate* tld;
				tld = (TransactionLocalDate*)de;
				*tld = TransactionLocalDates[turn];
				break;
			case  Bitmap::TransactionLocalTime:
				TransactionLocalTime* tlt;
				tlt = (TransactionLocalTime*)de;
				*tlt = TransactionLocalTimes[turn];
				break;
			case  Bitmap::ExpirationDate:
				ExpirationDate* dex;
				dex = (ExpirationDate*)de;
				*dex = ExpirationDates[turn];
				break;
			case  Bitmap::SettlementDate:
				break;
			case  Bitmap::MerchantType:
				MerchantType* mei;
				mei = (MerchantType*)de;
				*mei = MerchantTypes[turn];
				break;
			case  Bitmap::PrimaryAccountNumber:
				PrimaryAccountNumber*pan;
				pan = (PrimaryAccountNumber*)de;
				*pan = PrimaryAccountNumbers[turn];
				break;
			case  Bitmap::ProcessingCode:
				ProcessingCode* pc;
				pc = new ProcessingCode(TransactionType::GoodsAndServices);
				delete de;
				de = pc;
				break;
			case  Bitmap::ForwardingInstitutionIdentificationCode:
				ForwardingInstitutionIdentificationCode*fiic;
				fiic = (ForwardingInstitutionIdentificationCode*)de;
				*fiic = ForwardingInstitutionIdentificationCodes[turn];
				break;
			case  Bitmap::RetrievalReferenceNumber:
				RetrievalReferenceNumber*rrn;
				rrn = (RetrievalReferenceNumber*)de;
				*rrn = RetrievalReferenceNumbers[turn];
				break;
			case  Bitmap::SecurityRelatedControlInformation:
				SecurityRelatedControlInformation* srci;
				srci = (SecurityRelatedControlInformation*)de;
				*srci = SecurityRelatedControlInformations[turn];
				break;
			case  Bitmap::SystemsTraceAuditNumber:
				SystemsTraceAuditNumber* stan;
				stan = (SystemsTraceAuditNumber*)de;
				*stan = SystemsTraceAuditNumbers[turn];
				break;
			case  Bitmap::Track1Data:
				break;
			case  Bitmap::Track2Data:
				break;
			case  Bitmap::Track3Data:
				break;
			case  Bitmap::TransactionCurrencyCode:
				TransactionCurrencyCode*vd;
				vd = (TransactionCurrencyCode*)de;
				*vd = TransactionCurrencyCodes[turn];
				break;
			case  Bitmap::PINData:
				PINData*pd;
				pd = (PINData*)de;
				*pd = PINDatas[turn];
				break;
			case  Bitmap::OriginalDataElements:
				break;
			case  Bitmap::NationalData: {
				NationalData* nd;
				nd = (NationalData*)de;
				bitset<64> toAdd;
				toAdd.set(TestCodeFonction);
				toAdd.set(TestRaisonDuMessage);
				toAdd.set(TestAnneeTransaction);
				toAdd.set(TestEnvironnementReglementaire);
				toAdd.set(TestITPAcceptation );
				toAdd.set(TestNumeroContratAccepteur);
				toAdd.set(TestNumeroSystemeAcceptation);
				toAdd.set(TestNumeroPointAcceptation );
				toAdd.set(TestCodePaysSystemAcceptation );
				toAdd.set(TestMontantCumuleParPorteur);
				toAdd.set(TestTASA);
				toAdd.set(TestITPPointAcceptation);
				toAdd.set(TestCryptogrammeVisuel );
				toAdd.set(TestTraitementCryptogrammeVisuel);
				toAdd.set(TestIdentificationTransaction);
				toAdd.set(TestCryptogrammeElectronique);
				toAdd.set(TestTypeSecurisation);
				toAdd.set(TestTraitementCryptogrammeElectronique);
				toAdd.set(TestMethodeAuthentificationPorteur );
				toAdd.set(TestMethodeCalculCryptogrammeElectronique);
				toAdd.set(TestResultat);
				toAdd.set(TestModeSecurisationTransactionModifiee);
				toAdd.set(TestComplementCommerceElectronique);
				toAdd.set(TestDenominationPortefeuilleNumerique );
				toAdd.set(TestIndicateurCommerceElectronique);
				toAdd.set(TestComplementPortefeuilleElectronique );
				toAdd.set(TestIdentifiantWallet);
//				toAdd.set(TestAgentUniqueId);
//				toAdd.set(TestTypeFacture);
//				toAdd.set(TestServicesOptionels);
				addTLVs(nd, toAdd);
				nd->marshall();
				} break;
			case  Bitmap::MACField:
				break;
			case  Bitmap::Payee:  break;
			case  Bitmap::AccountIdentification1: break;
			case  Bitmap::AccountIdentification2: break;
			case  Bitmap::ForwardingInstitutionCountryCode:  break;
			case  Bitmap::PointOfServiceEntryMode:
				PointOfServiceEntryMode* posem;
				posem = (PointOfServiceEntryMode*)de;
				*posem = PointOfServiceEntryModes[turn];
				break;
			case  Bitmap::NetworkInternationalIdentifier: break;
			case  Bitmap::PointOfServiceConditionCode:
				PointOfServiceConditionCode* poscc;
				poscc = (PointOfServiceConditionCode*)de;
				*poscc = PointOfServiceConditionCodes[turn];
				break;
			case  Bitmap::PointOfServicePINCaptureCode: break;
			case  Bitmap::AuthorizationIdentificationResponse:
				AuthorizationIdentificationResponse*air;
				air = (AuthorizationIdentificationResponse*)de;
				*air = AuthorizationIdentificationResponses[turn];
				break;
			case  Bitmap::AuthorizationIdentificationResponseLength:
				AuthorizationIdentificationResponseLength*airl;
				airl = (AuthorizationIdentificationResponseLength*)de;
				*airl = AuthorizationIdentificationResponseLengths[turn];
				break;
			case  Bitmap::TransactionFeeAmount: break;
			case  Bitmap::SettlementFeeAmount: break;
			case  Bitmap::TransactionProcessingFeeAmount: break;
			case  Bitmap::SettlementProcessingFeeAmount: break;
			case  Bitmap::ResponseCode: break;
			case  Bitmap::ServiceRestrictionCode: break;
			case  Bitmap::SettlementCurrencyCode:  break;
			case  Bitmap::CardHolderBillingCurrencyCode:  break;

#ifdef FIXME
			case  Bitmap::TransactionSpecificData: de = new TransactionSpecificData; break;
			case  Bitmap::AmountsOriginalFees: de = new AmountsOriginalFees; break;
			case  Bitmap::ExtendedPaymentData: de = new ExtendedPaymentData; break;
			case  Bitmap::FileTransferMessageControl: de = new FileTransferMessageControl; break;
			case  Bitmap::FileTransferControlData: de = new FileTransferControlData; break;
			case  Bitmap::FileTransferDescriptionData: de = new FileTransferDescriptionData; break;
			case  Bitmap::DataRecord: de = new DataRecord; break;
			case  Bitmap::DateAction: de = new DateAction; break;
			case  Bitmap::ReconciliationDataPrimary: de = new ReconciliationDataPrimary; break;
			case  Bitmap::ReconciliationDataSecondary: de = new ReconciliationDataSecondary; break;
			case  Bitmap::TransactionDestinationInstitutionIdentificationCode: de = new TransactionDestinationInstitutionIdentificationCode; break;
			case  Bitmap::TransactionOriginatorInstitutionIdentificationCode: de = new TransactionOriginatorInstitutionIdentificationCode; break;
			case  Bitmap::CardIssuerReferenceData: de = new CardIssuerReferenceData; break;
			case  Bitmap::KeyManagementData: de = new KeyManagementData; break;
			case  Bitmap::NetReconciliationAmount: de = new NetReconciliationAmount; break;
			case  Bitmap::SettlementInstitutionIdentificationCode: de = new SettlementInstitutionIdentificationCode; break;
			case  Bitmap::ReceivingInstitutionIdentificationCode: de = new ReceivingInstitutionIdentificationCode; break;
			case  Bitmap::FileName: de = new FileName; break;
			case  Bitmap::ReconciliationFeeAmountsCredit: de = new ReconciliationFeeAmountsCredit; break;
			case  Bitmap::ReconciliationFeeAmountsDebit: de = new ReconciliationFeeAmountsDebit; break;
#endif
			default: 
				throw invalid_argument(string("AuthorizationRequestTest: erroneous bitmap no ") + to_string((int)bitno));

			}
			return de;
		}

// ==================================================================================================
#define ADD_FIELD(var, subtype) \
				subtype##Field* subtypeField; \
				subtypeField = new subtype##Field; \
				subtype* sub; \
				sub = static_cast<subtype*>(subtypeField); \
				var->add(subtypeField)
// ==================================================================================================

		// ==================================================================================================
#define TEST_FIELD(var, subtype, value) \
			if (subfields.test(Test##subtype)) { \
				ADD_FIELD(var, subtype); \
				*sub =value; \
			}
// ==================================================================================================

		void  AuthorizationRequestTest::addTLVs(AdditionalDataNational* adn, const bitset<64>&	subfields) {
		}
		void  AuthorizationRequestTest::addTLVs(NationalData* td, const bitset<64>& subfields) {
			TEST_FIELD(td, CodeFonction, CodeFonction::AutorisationInitialMontantEstime)
			TEST_FIELD(td, RaisonDuMessage, RaisonDuMessage::DepassementSeuilAppel)
			TEST_FIELD(td, AnneeTransaction, 3)
			TEST_FIELD(td, EnvironnementReglementaire, "1")
			TEST_FIELD(td, ITPAcceptation, 1)
			TEST_FIELD(td, NumeroContratAccepteur, 1)
			TEST_FIELD(td, NumeroSystemeAcceptation, 1)
			TEST_FIELD(td, NumeroPointAcceptation, 1)
			TEST_FIELD(td, CodePaysSystemAcceptation, 1)
			TEST_FIELD(td, MontantCumuleParPorteur, 1)
			TEST_FIELD(td, TASA, "1")
			TEST_FIELD(td, ITPPointAcceptation, 1)
			TEST_FIELD(td, CryptogrammeVisuel, 1)
			TEST_FIELD(td, TraitementCryptogrammeVisuel, 1)
			TEST_FIELD(td, IdentificationTransaction, "1")
			TEST_FIELD(td, CryptogrammeElectronique, "1")
			TEST_FIELD(td, TypeSecurisation, 1)
			TEST_FIELD(td, TraitementCryptogrammeElectronique, "1")
			TEST_FIELD(td, MethodeAuthentificationPorteur, "1")
			TEST_FIELD(td, MethodeCalculCryptogrammeElectronique, "1")
			TEST_FIELD(td, Resultat, 1)
			TEST_FIELD(td, ModeSecurisationTransactionModifiee, "1")
			TEST_FIELD(td, ComplementCommerceElectronique, "1")
			TEST_FIELD(td, DenominationPortefeuilleNumerique, 1)
			TEST_FIELD(td, IndicateurCommerceElectronique, 1)
			TEST_FIELD(td, ComplementPortefeuilleElectronique, 1)
			TEST_FIELD(td, IdentifiantWallet, 1)
			TEST_FIELD(td, AgentUniqueId, "1")
			TEST_FIELD(td, TypeFacture, 1)
			TEST_FIELD(td, ServicesOptionels, "1")
		}

		void AuthorizationRequestTest::setUp() {
		}
		void AuthorizationRequestTest::tearDown() {
		}
		CppUnit::Test* AuthorizationRequestTest::suite() {
			CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("AuthorizationRequest");
			CppUnit_addTest(pSuite, AuthorizationRequestTest, testAuthorizationRequest);
			return pSuite;
		}
	}
}

