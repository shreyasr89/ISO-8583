#include <string>
#include <sstream>
#include <memory>

#include "Poco/Logger.h"
#include "Poco/Util/Application.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/SocketStream.h"
using Poco::Logger;
using Poco::Util::Application;
using Poco::Net::SocketAddress;
using Poco::Net::StreamSocket;
using Poco::Net::SocketStream;


#if STD_CB2A == 150 || STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 
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
#include "ISO-8583/DTE/NetReconciliationAmount.h"
#include "ISO-8583/DTE/AuthorizationLifeCycleCode.h"
#include "ISO-8583/DTE/AuthorizingAgentInstitutionIdentificationCode.h"
#include "ISO-8583/DTE/DataRecord.h"
#include "ISO-8583/DTE/DateAction.h"
#include "ISO-8583/DTE/ElectronicCommerceData.h"
#include "ISO-8583/DTE/ExtendedPaymentData.h"
#include "ISO-8583/DTE/FileTransferControlData.h"
#include "ISO-8583/DTE/FileTransferDescriptionData.h"
#include "ISO-8583/DTE/FileTransferMessageControl.h"
#include "ISO-8583/DTE/ICCSystemRelatedData.h"
#include "ISO-8583/DTE/KeyManagementData.h"
#include "ISO-8583/DTE/ReconciliationDataPrimary.h"
#include "ISO-8583/DTE/ReconciliationDataSecondary.h"
#include "ISO-8583/DTE/ReconciliationFeeAmountsCredit.h"
#include "ISO-8583/DTE/ReconciliationFeeAmountsDebit.h"
#include "ISO-8583/DTE/TransactionDestinationInstitutionIdentificationCode.h"
#include "ISO-8583/DTE/TransactionLifeCycleIdentificationData.h"
#include "ISO-8583/DTE/TransactionOriginatorInstitutionIdentificationCode.h"
#include "ISO-8583/DTE/TransactionSpecificData.h"
#include "ISO-8583/DTE/VerificationData.h"
#include "ISO-8583/DTE/ActionCode.h"
#include "ISO-8583/DTE/AcquirerReferenceNumber.h"
#include "ISO-8583/DTE/AmountReconciliation.h"
#include "ISO-8583/DTE/AmountsFees.h"
#include "ISO-8583/DTE/AmountsOriginal.h"
#include "ISO-8583/DTE/ApprovalCode.h"
#include "ISO-8583/DTE/ConversionRateReconciliation.h"
#include "ISO-8583/DTE/DateAndTimeLocalTransaction.h"
#include "ISO-8583/DTE/FunctionCode.h"
#include "ISO-8583/DTE/DateReconciliation.h"
#include "ISO-8583/DTE/MerchantCategoryCode.h"
#include "ISO-8583/DTE/POSDataCode.h"
#include "ISO-8583/DTE/MessageReasonCode.h"
#include "ISO-8583/DTE/POSCapability.h"
#include "ISO-8583/DTE/ReconciliationIndicator.h"
#include "ISO-8583/DTE/ServiceCode.h"
#include "ISO-8583/DTE/MessageErroIndicator.h"
#endif
#include "ISO-8583/MSG/SocketChannel.h"
#include "ISO-8583/MSG/Factory.h"

#include "ISO-8583/MSG/RequestResponse.h"
#include "ISO-8583/MSG/AuthorizationRequest.h"
#include "ISO-8583/MSG/AuthorizationRequestResponse.h"
#include "ISO-8583/DFT/DefaultAuthorizationRequest.h"

using namespace ISO_8583::COM;
using namespace ISO_8583::MSG;
using namespace ISO_8583::DTT;
using namespace ISO_8583::DTE;
using namespace ISO_8583::DTE::AdditionalDataNationalNamespace;
using namespace ISO_8583::DTE::NationalDataNamespace;

using namespace std;

DataElement* newDataElement(Bitmap bitno, int turn);

class ISO_8583_CLI_1987 : public Application {
public:
	ISO_8583_CLI_1987() : Application() {
	}
	
	ISO_8583_CLI_1987(int argc, char* argv[]) : Application( argc, argv) {
	}

	void initialize(Application& self) {
		loadConfiguration();
		Application::initialize(self);
	}
		
	void uninitialize() {
		Application::uninitialize();
	}
	int main(const vector<string>& args) {
		bool doit = true;

		Application& application = Application::instance();
		Logger& logger = application.logger();

		// get parameters from configuration file
		string host = config().getString("host", "localhost");
		unsigned short port = (unsigned short)config().getInt("port", 11019);
		string library = config().getString("library", "ISO-8583-DFT-1987");
		Factory factory(library);

		try {
			unique_ptr<NetworkChannel> channel(new SocketChannel(&logger, host, port));
			logger.information(">>> connect");
			channel->connect();

			for (int no = 0; no < 4; no++) {
				BinaryOutputStream os(2048);
				BinaryInputStream is;
				{
					Request* r = factory.newAuthorizationRequest(Origin::Acquirer);
					unique_ptr<AuthorizationRequest> ar(static_cast<AuthorizationRequest*>(r));
					Bitmaps mandatory = ar->mandatory();
					Bitmaps optional = ar->optional();
					for (int bitno = 1; bitno <= mandatory.size(); bitno++) {
						if (mandatory.get(bitno) || optional.get(bitno)) {
							DataElement* de = newDataElement(static_cast<Bitmap>(bitno), 0);
							assert(de != NULL);
							if (de) {
								ar->addAndSet(de);
								if (logger.debug()) {
									string name = typeid(*de).name();
									ostringstream ss; ss.width(3);
									ss << bitno;
									string message = ss.str() + " " + name;
									message += "\t\t"; message += de->toString();
									logger.debug(message);
								}
							}
						}
					}
					os << *ar;
					logger.information(string(">>> ") + typeid(*ar).name() );
					channel->send(os);
				}
				{
					RequestResponse* rr = NULL;
					int result;
					if ((result = channel->recv(is)) > 0) {
						unique_ptr<Message> message(factory.newMessage(is));
						AuthorizationRequestResponse* arr;
						arr = dynamic_cast<AuthorizationRequestResponse*>(message.get());
						if (arr) {
							logger.information(string("<<< ") + typeid(*arr).name() );
							if (logger.debug())
								arr->dump(cout);
							arr->confirmation(is, os);
						}
						else {
							logger.error(string("<<< Expecting AuthorizationRequestResponse but got"));
							logger.error(string(typeid(*message.get()).name()));
						}
					}
					else {
						logger.error("invalid result: " + to_string(result));
					}
				}
			}
			logger.information(">>> disconnect");
			channel->disconnect();
		}
		catch (const Poco::Exception& e) {
			logger.log(e);
		}
		catch (const exception& e) {
			cout << e.what() << endl;
		}
		return Application::EXIT_OK;
	}

};
POCO_APP_MAIN(ISO_8583_CLI_1987)

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
const static char* DateCaptures[] = { "" };
const static char* DateConversions[] = { "" };
const static char* DateEffectives[] = { "1405" };
const static char* DateExpirations[] = { "2110" };
const static char* DateReconciliations[] = { "" };
const static char* DateSettlements[] = { "" };
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
const static char* ResponseCodes[] = { "" };
const static char* RetrievalReferenceNumbers[] = { "ABCD5678ijkl" };
const static char* SecurityRelatedControlInformations[] = { "666" };
const static char* ServiceCodes[] = { "" };
const static char* SettlementInstitutionIdentificationCodes[] = { "" };
const static char* SystemsTraceAuditNumbers[] = { "333333" };
const static char* Track1Datas[] = { "" };
const static char* Track2Datas[] = { "" };
const static char* Track3Datas[] = { "" };
const static char* TransactionAmounts[] = { "987654321" };
const static char* TransactionCurrencyCodes[] = { "978" };
const static char* TransactionDestinationInstitutionIdentificationCodes[] = { "" };
const static char* TransactionLifeCycleIdentificationDatas[] = { "" };
const static char* TransactionLocalDates[] = { "1225" };
const static char* TransactionLocalTimes[] = { "235959" };
const static char* TransactionOriginatorInstitutionIdentificationCodes[] = { "" };
const static char* TransactionSpecificDatas[] = { "" };

enum TestAdditionalDataNational {
	TestCodeDonneesPointService = 1,
	TestTypeSite,
	TestConversionChamp,
	TestNumeroDossier,
	TestCapaciteAdditionnelleLectureCarte,
	TestPointAcceptation,
	TestSiret,
	TestIDPA,
	TestIDSA
};


enum TestNationalData {
	TestCodeFonction = 1,
	TestRaisonDuMessage,
	TestAnneeTransaction,
	TestEnvironnementReglementaire,
	TestITPAcceptation,
	TestNumeroContratAccepteur,
	TestNumeroSystemeAcceptation,
	TestNumeroPointAcceptation,
	TestCodePaysSystemAcceptation,
	TestMontantCumuleParPorteur,
	TestTASA,
	TestITPPointAcceptation,
	TestCryptogrammeVisuel,
	TestTraitementCryptogrammeVisuel,
	TestIdentificationTransaction,
	TestCryptogrammeElectronique,
	TestTypeSecurisation,
	TestTraitementCryptogrammeElectronique,
	TestMethodeAuthentificationPorteur,
	TestMethodeCalculCryptogrammeElectronique,
	TestResultat,
	TestModeSecurisationTransactionModifiee,
	TestComplementCommerceElectronique,
	TestDenominationPortefeuilleNumerique,
	TestIndicateurCommerceElectronique,
	TestComplementPortefeuilleElectronique,
	TestIdentifiantWallet,
	TestAgentUniqueId,
	TestTypeFacture,
	TestServicesOptionels
};
void  addTLVs(AdditionalDataNational* adn, const bitset<64>& subfields);
void  addTLVs(NationalData* td, const bitset<64>& subfields);

DataElement* newDataElement(Bitmap bitno, int turn) {
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
#if STD_ISO_8583 == 1987
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
#endif
	case  Bitmap::ExpirationDate:
		ExpirationDate* dex;
		dex = (ExpirationDate*)de;
		*dex = DateExpirations[turn];
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
#if STD_ISO_8583 == 1987
	case  Bitmap::NationalData: {
		NationalData* nd;
		nd = (NationalData*)de;
		bitset<64> toAdd;
		toAdd.set(TestCodeFonction);
		toAdd.set(TestRaisonDuMessage);
		toAdd.set(TestAnneeTransaction);
		toAdd.set(TestEnvironnementReglementaire);
		toAdd.set(TestITPAcceptation);
		toAdd.set(TestNumeroContratAccepteur);
		toAdd.set(TestNumeroSystemeAcceptation);
		toAdd.set(TestNumeroPointAcceptation);
		toAdd.set(TestCodePaysSystemAcceptation);
		toAdd.set(TestMontantCumuleParPorteur);
		toAdd.set(TestTASA);
		toAdd.set(TestITPPointAcceptation);
		toAdd.set(TestCryptogrammeVisuel);
		toAdd.set(TestTraitementCryptogrammeVisuel);
		toAdd.set(TestIdentificationTransaction);
		toAdd.set(TestCryptogrammeElectronique);
		toAdd.set(TestTypeSecurisation);
		toAdd.set(TestTraitementCryptogrammeElectronique);
		toAdd.set(TestMethodeAuthentificationPorteur);
		toAdd.set(TestMethodeCalculCryptogrammeElectronique);
		toAdd.set(TestResultat);
		toAdd.set(TestModeSecurisationTransactionModifiee);
		toAdd.set(TestComplementCommerceElectronique);
		toAdd.set(TestDenominationPortefeuilleNumerique);
		toAdd.set(TestIndicateurCommerceElectronique);
		toAdd.set(TestComplementPortefeuilleElectronique);
		toAdd.set(TestIdentifiantWallet);
//		toAdd.set(TestAgentUniqueId);
//		toAdd.set(TestTypeFacture);
//		toAdd.set(TestServicesOptionels);
		addTLVs(nd, toAdd);
		nd->marshall();
	} break;
#endif
	case  Bitmap::MACField:
		break;
	case  Bitmap::Payee:  break;
	case  Bitmap::AccountIdentification1: break;
	case  Bitmap::AccountIdentification2: break;
	case  Bitmap::ForwardingInstitutionCountryCode:  break;
#if STD_ISO_8583 == 1987
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
#endif
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

		void  addTLVs(AdditionalDataNational* adn, const bitset<64>&	subfields) {
		}
		void  addTLVs(NationalData* td, const bitset<64>& subfields) {
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

