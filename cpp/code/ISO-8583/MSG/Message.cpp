/*
 * Message.cpp
 *
 *  Created on: 18 mai 2015
 *      Author: FrancisANDRE
 */
#include <typeinfo>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <cassert>

using namespace std;

#include "ISO-8583/MSG/MTI.h"
#include "ISO-8583/DTE/Bitmap.h"
#include "ISO-8583/DTT/Bitmaps.h"

#include "ISO-8583/DTE/AcquiringInstitutionIdentificationCode.h"

#if STD_CB2A == 150 || STD_ISO_8583 == 1987
#include "ISO-8583/DTE/AdditionalDataISO.h"
#include "ISO-8583/DTE/AuthorizationIdentificationResponse.h"
#include "ISO-8583/DTE/AuthorizationIdentificationResponseLength.h"
#include "ISO-8583/DTE/CardHolderBillingCurrencyCode.h"
#include "ISO-8583/DTE/ForwardingInstitutionCountryCode.h"
#include "ISO-8583/DTE/MerchantType.h"
#include "ISO-8583/DTE/NationalData.h"
#include "ISO-8583/DTE/NetworkInternationalIdentifier.h"
#include "ISO-8583/DTE/OriginalDataElements.h"
#include "ISO-8583/DTE/PointOfServiceConditionCode.h"
#include "ISO-8583/DTE/PointOfServiceEntryMode.h"
#include "ISO-8583/DTE/PointOfServicePINCaptureCode.h"
#include "ISO-8583/DTE/PrimaryAccountNumberExtended.h"
#include "ISO-8583/DTE/ResponseCode.h"
#include "ISO-8583/DTE/ServiceRestrictionCode.h"
#include "ISO-8583/DTE/SettlementAmount.h"
#include "ISO-8583/DTE/SettlementConversionRate.h"
#include "ISO-8583/DTE/SettlementCurrencyCode.h"
#include "ISO-8583/DTE/SettlementFeeAmount.h"
#include "ISO-8583/DTE/SettlementProcessingFeeAmount.h"
#include "ISO-8583/DTE/TransactionCurrencyCode.h"
#include "ISO-8583/DTE/TransactionFeeAmount.h"
#include "ISO-8583/DTE/TransactionLocalDate.h"
#include "ISO-8583/DTE/TransactionLocalTime.h"
#include "ISO-8583/DTE/TransactionProcessingFeeAmount.h"
#if 0
#include "ISO-8583/DTE/SettlementCode.h"
#include "ISO-8583/DTE/ExtendedPaymentCode.h"
#include "ISO-8583/DTE/ReceivingInstitutionCountryCode.h"
#include "ISO-8583/DTE/SettlementInstitutionCountryCode.h"
#include "ISO-8583/DTE/NetworkManagementInformationCode.h"
#include "ISO-8583/DTE/MessageNumber.h"
#include "ISO-8583/DTE/MessageNumberLast.h"
#include "ISO-8583/DTE/DateAction.h"
#include "ISO-8583/DTE/CreditsNumber.h"
#include "ISO-8583/DTE/CreditsReversalNumber.h"
#include "ISO-8583/DTE/DebitsNumber.h"
#include "ISO-8583/DTE/DebitsReversalNumber.h"
#include "ISO-8583/DTE/TransferNumber.h"
#include "ISO-8583/DTE/TransferReversalNumber.h"
#include "ISO-8583/DTE/InquiriesNumbe.h"
#include "ISO-8583/DTE/AuthorizationsNumber.h"
#include "ISO-8583/DTE/CreditsProcessingFeeAmount.h"
#include "ISO-8583/DTE/CreditsTransactionFeeAmount.h"
#include "ISO-8583/DTE/DebitsProcessingFeeAmount.h"
#include "ISO-8583/DTE/DebitsTransactionFeeAmount.h"
#include "ISO-8583/DTE/CreditsAmount.h"
#include "ISO-8583/DTE/CreditsReversalAmount.h"
#include "ISO-8583/DTE/DebitsAmount.h"
#include "ISO-8583/DTE/DebitsReversalAmount.h"
#include "ISO-8583/DTE/FileUpdateCode.h"
#include "ISO-8583/DTE/FileSecurityCode.h"
#include "ISO-8583/DTE/ResponseIndicator.h"
#include "ISO-8583/DTE/ServiceIndicator.h"
#include "ISO-8583/DTE/ReplacementAmounts.h"
#include "ISO-8583/DTE/MessageSecurityCode.h"
#include "ISO-8583/DTE/AmountNetSettlement.h"
#endif

#elif STD_ISO_8583 == 2003
#include "ISO-8583/DTE/AcquirerReferenceNumber.h"
#include "ISO-8583/DTE/ActionCode.h"
#include "ISO-8583/DTE/ReconciliationAmount.h"
#include "ISO-8583/DTE/FeesAmounts.h"
#include "ISO-8583/DTE/OriginalAmounts.h"
#include "ISO-8583/DTE/OriginalFeesAmounts.h"
#include "ISO-8583/DTE/ApprovalCode.h"
#include "ISO-8583/DTE/AuthorizationLifeCycleCode.h"
#include "ISO-8583/DTE/AuthorizingAgentInstitutionIdentificationCode.h"
#include "ISO-8583/DTE/ConversionRateReconciliation.h"
#include "ISO-8583/DTE/DataRecord.h"
#include "ISO-8583/DTE/DateAction.h"
#include "ISO-8583/DTE/DateAndTimeLocalTransaction.h"
#include "ISO-8583/DTE/EffectiveDate.h"
#include "ISO-8583/DTE/ReconciliationDate.h"
#include "ISO-8583/DTE/ElectronicCommerceData.h"
#include "ISO-8583/DTE/ExtendedPaymentData.h"
#include "ISO-8583/DTE/FileTransferControlData.h"
#include "ISO-8583/DTE/FileTransferDescriptionData.h"
#include "ISO-8583/DTE/FileTransferMessageControl.h"
#include "ISO-8583/DTE/FunctionCode.h"
#include "ISO-8583/DTE/ICCSystemRelatedData.h"
#include "ISO-8583/DTE/KeyManagementData.h"
#include "ISO-8583/DTE/MerchantCategoryCode.h"
#include "ISO-8583/DTE/MessageErroIndicator.h"
#include "ISO-8583/DTE/MessageErroIndicator.h"
#include "ISO-8583/DTE/MessageReasonCode.h"
#include "ISO-8583/DTE/NetReconciliationAmount.h"
#include "ISO-8583/DTE/OriginalDataElements.h"
#include "ISO-8583/DTE/POSCapability.h"
#include "ISO-8583/DTE/POSDataCode.h"
#include "ISO-8583/DTE/ReconciliationDataPrimary.h"
#include "ISO-8583/DTE/ReconciliationDataSecondary.h"
#include "ISO-8583/DTE/ReconciliationFeeAmountsCredit.h"
#include "ISO-8583/DTE/ReconciliationFeeAmountsDebit.h"
#include "ISO-8583/DTE/ReconciliationIndicator.h"
#include "ISO-8583/DTE/ServiceCode.h"
#include "ISO-8583/DTE/TransactionDestinationInstitutionIdentificationCode.h"
#include "ISO-8583/DTE/TransactionLifeCycleIdentificationData.h"
#include "ISO-8583/DTE/TransactionLifeCycleIdentificationData.h"
#include "ISO-8583/DTE/TransactionOriginatorInstitutionIdentificationCode.h"
#include "ISO-8583/DTE/TransactionSpecificData.h"
#include "ISO-8583/DTE/VerificationData.h"
#endif
#include "ISO-8583/DTE/AccountIdentification1.h"
#include "ISO-8583/DTE/AccountIdentification2.h"
#include "ISO-8583/DTE/AcquiringInstitutionCountryCode.h"
#include "ISO-8583/DTE/AdditionalAmounts.h"
#include "ISO-8583/DTE/AdditionalDataNational.h"
#include "ISO-8583/DTE/AdditionalDataPrivate.h"
#include "ISO-8583/DTE/AdditionalResponseData.h"
#include "ISO-8583/DTE/CardAcceptorIdentificationCode.h"
#include "ISO-8583/DTE/CardAcceptorNameOrlocation.h"
#include "ISO-8583/DTE/CardAcceptorTerminalIdentification.h"
#include "ISO-8583/DTE/CardHolderBillingAmount.h"
#include "ISO-8583/DTE/CardHolderBillingConversionRate.h"
#include "ISO-8583/DTE/CardHolderBillingFeeAmount.h"
#include "ISO-8583/DTE/CardIssuerReferenceData.h"
#include "ISO-8583/DTE/CardSequenceNumber.h"
#include "ISO-8583/DTE/TransmissionDateAndTime.h"
#include "ISO-8583/DTE/CaptureDate.h"
#include "ISO-8583/DTE/ConversionDate.h"
#include "ISO-8583/DTE/ExpirationDate.h"
#include "ISO-8583/DTE/SettlementDate.h"
#include "ISO-8583/DTE/FileName.h"
#include "ISO-8583/DTE/ForwardingInstitutionIdentificationCode.h"
#include "ISO-8583/DTE/MACField.h"
#include "ISO-8583/DTE/NationalData.h"
#include "ISO-8583/DTE/OriginalDataElements.h"
#include "ISO-8583/DTE/PINData.h"
#include "ISO-8583/DTE/Payee.h"
#include "ISO-8583/DTE/PrimaryAccountNumber.h"
#include "ISO-8583/DTE/PrimaryAccountNumberCountryCode.h"
#include "ISO-8583/DTE/ProcessingCode.h"
#include "ISO-8583/DTE/ReceivingInstitutionIdentificationCode.h"
#include "ISO-8583/DTE/ResponseCode.h"
#include "ISO-8583/DTE/RetrievalReferenceNumber.h"
#include "ISO-8583/DTE/SecurityRelatedControlInformation.h"
#include "ISO-8583/DTE/ServiceRestrictionCode.h"
#include "ISO-8583/DTE/SettlementInstitutionIdentificationCode.h"
#include "ISO-8583/DTE/SystemsTraceAuditNumber.h"
#include "ISO-8583/DTE/Track1Data.h"
#include "ISO-8583/DTE/Track2Data.h"
#include "ISO-8583/DTE/Track3Data.h"
#include "ISO-8583/DTE/TransactionAmount.h"

#include "ISO-8583/MSG/Factory.h"
#include "ISO-8583/MSG/Message.h"

#include "ISO-8583/MSG/Request.h"
#include "ISO-8583/MSG/Advice.h"
#include "ISO-8583/MSG/Notification.h"
#include "ISO-8583/MSG/Instruction.h"
#include "ISO-8583/MSG/RequestResponse.h"
#include "ISO-8583/MSG/AdviceResponse.h"
#include "ISO-8583/MSG/NotificationAcknowledge.h"
#include "ISO-8583/MSG/InstructionAcknowledge.h"



using namespace ISO_8583::DTE;
using namespace ISO_8583::DTT;

namespace ISO_8583 {
	namespace MSG {
		Message::Message() {
		}
		Message::Message(Class klass, Function function, Origin starter) :
			MTI(klass, function, starter) {
		}
		Message::~Message() {
			for (size_t no = 0; no < fields.size(); no++) {
				DataElement* de = fields[no];
				delete de;
			}
		}
		void Message::addAndSet(DataElement* element) {
			add(*element);
			set(*element);
		}
		void Message::add(DataElement& element) {
			byte bitno = element.bitno();
			if (controls.get(bitno)) {
				string message("Message: field already added: ");
				message += typeid(element).name();
				throw logic_error(message);
			} else {
				fields.push_back(&element);
				controls.set(bitno);
			}
		}
		void Message::set(DataElement& element) {
			// ============================================================================================
#define set(type) \
			if (typeid(element) == typeid(type)) { \
				assert(element.bitno() == (int)Bitmap::type); \
				bitmaps.set((byte)Bitmap::type); \
			} else
			// ============================================================================================

			set(AccountIdentification1)
				set(AccountIdentification2)
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
				set(SettlementDate)
				set(ResponseCode)
				set(AcquiringInstitutionIdentificationCode)
				set(TransmissionDateAndTime)
				set(TransactionLocalTime)
				set(TransactionLocalDate)
				set(MerchantType)
				set(ForwardingInstitutionCountryCode)
				set(PointOfServiceEntryMode)
				set(NetworkInternationalIdentifier)
				set(PointOfServiceConditionCode)
				set(PointOfServicePINCaptureCode)
				set(AuthorizationIdentificationResponseLength)
				set(TransactionFeeAmount)
				set(SettlementFeeAmount)
				set(TransactionProcessingFeeAmount)
				set(SettlementProcessingFeeAmount)
				set(PrimaryAccountNumberExtended)
				set(AuthorizationIdentificationResponse)
				set(ServiceRestrictionCode)
				set(AdditionalDataISO)
				set(TransactionCurrencyCode)
				set(SettlementCurrencyCode)
				set(CardHolderBillingCurrencyCode)
				set(NationalData)
				set(AuthorizationIdentificationResponse)
#if 0
				set(SettlementCode)
				set(ExtendedPaymentCode)
				set(ReceivingInstitutionCountryCode)
				set(SettlementInstitutionCountryCode)
				set(NetworkManagementInformationCode)
				set(MessageNumber)
				set(MessageNumberLast)
				set(DateAction)
				set(CreditsNumber)
				set(CreditsReversalNumber)
				set(DebitsNumber)
				set(DebitsReversalNumber)
				set(TransferNumber)
				set(TransferReversalNumber)
				set(InquiriesNumber)
				set(AuthorizationsNumber)
				set(CreditsProcessingFeeAmount )
				set(CreditsTransactionFeeAmount )
				set(DebitsProcessingFeeAmount)
				set(DebitsTransactionFeeAmount)
				set(CreditsAmount)
				set(CreditsReversalAmount)
				set(DebitsAmount)
				set(DebitsReversalAmount)
				set(OriginalDataElements)
				set(FileUpdateCode)
				set(FileSecurityCode)
				set(ResponseIndicator)
				set(ServiceIndicator)
				set(ReplacementAmounts)
				set(MessageSecurityCode)
				set(AmountNetSettlement)
				set(TransactionDescription)
#endif

#elif STD_ISO_8583 == 2003
				set(AcquirerReferenceNumber)
				set(AmountReconciliation)
				set(ActionCode)
				set(AmountsFees)
				set(AmountsOriginal)
				set(AmountsOriginalFees)
				set(ApprovalCode)
				set(ReconciliationConversionRate)
				set(DateAndTimeLocalTransaction)
				set(DateReconciliation)
				set(FunctionCode)
				set(MerchantCategoryCode)
				set(MessageReasonCode)
				set(POSCapability)
				set(POSDataCode)
				set(ReconciliationIndicator)
				set(ServiceCode)
				set(NetReconciliationAmount)
				set(AuthorizationLifeCycleCode)
				set(AuthorizingAgentInstitutionIdentificationCode)
				set(CardIssuerReferenceData)
				set(DataRecord)
				set(DateAction)
				set(EffectiveDate)
				set(ExtendedPaymentData)
				set(ElectronicCommerceData)
				set(FileTransferControlData)
				set(FileTransferDescriptionData)
				set(FileTransferMessageControl)
				set(ICCSystemRelatedData)
				set(KeyManagementData)
				set(MessageErrorIndicator)
				set(ReconciliationDataPrimary)
				set(ReconciliationDataSecondary)
				set(ReconciliationFeeAmountsCredit)
				set(ReconciliationFeeAmountsDebit)
				set(TransactionDestinationInstitutionIdentificationCode)
				set(TransactionLifeCycleIdentificationData)
				set(TransactionOriginatorInstitutionIdentificationCode)
				set(TransactionSpecificData)
				set(TransportData)
				set(VerificationData)
#endif
				set(AcquiringInstitutionCountryCode)
				set(AdditionalAmounts)
				set(AdditionalDataNational)
				set(AdditionalDataPrivate)
				set(AdditionalResponseData)
				set(CardAcceptorIdentificationCode)
				set(CardAcceptorNameOrlocation)
				set(CardAcceptorTerminalIdentification)
				set(CardHolderBillingAmount)
				set(CardHolderBillingConversionRate)
				set(CardHolderBillingFeeAmount)
				set(CardSequenceNumber)
				set(CaptureDate)
				set(ConversionDate)
				set(ExpirationDate)
				set(FileName)
				set(ForwardingInstitutionIdentificationCode)
				set(MACField)
				set(OriginalDataElements)
				set(PINData)
				set(Payee)
				set(PrimaryAccountNumber)
				set(PrimaryAccountNumberCountryCode)
				set(ProcessingCode)
				set(ReceivingInstitutionIdentificationCode)
				set(RetrievalReferenceNumber)
				set(SecurityRelatedControlInformation)
				set(SettlementInstitutionIdentificationCode)
				set(SystemsTraceAuditNumber)
				set(Track1Data)
				set(Track2Data)
				set(Track3Data)
				set(TransactionAmount)			{
				string message("Message: unknown data element: ");
				message += typeid(element).name();
				throw invalid_argument(message);
			}
			;
#undef set
		}
		bool bitnocmp (DataElement* left, DataElement* right) { 
			return (left->bitno() < right->bitno()); 
		}
		MSG_API_SCOPE BinaryInputStream& operator>>(BinaryInputStream& is, Message& m) {
#if 0
			// get length of file:
			int pos = is.tellg();
			is.seekg(0, is.end);
			streamoff length = is.tellg();
			is.seekg(pos, is.beg);
#endif

			streamoff  count = 0;
			is >> static_cast<MTI&>(m);
			is >> m.bitmaps;
			DataElement* de = NULL;
			Bitmaps	check = m.mandatory();
			for (byte no = 1; no <= m.bitmaps.size(); no++) {
#if 0
				if (is.fail()) {
					string message("Message: invalid input stream");
					message += ": bitno=";
					message += to_string(no);
					throw logic_error(message);
				}
				if (is.eof()) {
					string message("Message: EOF found at bitno=");
					message += to_string(no);
					message += "around position ";
					message += to_string(count);
					throw logic_error(message);
				}
#endif
				try {
					if (m.bitmaps.get(no)) {
						de = m.newDataElement(static_cast<Bitmap>(no));
						if (de) {
							de->decode(is);
							count = is.position();
						}
//						cout << typeid(*de).name() << "\t" << de->toString() << endl;
						check.set(no, false);
						if (m.mandatory().get(no) || m.optional().get(no))
							m.add(*de);
						else
							delete de;
					}
				}
				catch (const exception& e) {
					cout << "Message: error at field no " << no << " pos=" << count << " " << typeid(*de).name() << " " << e.what() << endl;
					throw e;
				}
			}
			if (check.any()) {
				string message("Message: missing mandatory element(s): ");
				for (int no = 1; no <= check.size(); no++) {
					if (check.get(no)) {
						message += to_string(no);
						message += ", ";
					}
				}
				throw logic_error(message);
			}
			return is;
		}
		MSG_API_SCOPE BinaryOutputStream& operator<<(BinaryOutputStream& os, const Message& m) {
			int pos = 0;
			os << static_cast<const MTI&>(m);
			pos = os.position();
			os << m.bitmaps;
			pos = os.position();
			Message& message = const_cast<Message&>(m);
			sort (message.fields.begin(), message.fields.end(), bitnocmp);
			Bitmaps	check = m.mandatory();
			for (int no = 0; no < m.fields.size(); no++) {
				DataElement* element = m.fields.at(no);
				element->encode(os);
				check.set(element->bitno(), false);
				pos = os.position();
			}
			if (check.any()) {
				string message("Message: missing mandatory element(s): ");
				for (int no = 1; no <= check.size(); no++) {
					if (check.get(no)) {
						message += to_string(no);
						message += ", ";
					}
				}
				throw logic_error(message);
			}
			return os;
		}


		DataElement* Message::newDataElement(Bitmap bitno) {
			DataElement* de = NULL;
			switch (bitno) {
			case  Bitmap::AccountIdentification1: de = new AccountIdentification1; break;
			case  Bitmap::AccountIdentification2: de = new AccountIdentification2; break;
			case  Bitmap::AcquiringInstitutionCountryCode: de = new AcquiringInstitutionCountryCode; break;
			case  Bitmap::PrimaryAccountNumberCountryCode: de = new PrimaryAccountNumberCountryCode; break;
#if STD_CB2A == 150 || STD_ISO_8583 == 1987
			case  Bitmap::SettlementDate: de = new SettlementDate; break;
			case  Bitmap::TransactionLocalTime: de = new TransactionLocalTime; break;
			case  Bitmap::TransactionLocalDate: de = new TransactionLocalDate; break;
			case  Bitmap::MerchantType: de = new MerchantType; break;
			case  Bitmap::ForwardingInstitutionCountryCode: de = new ForwardingInstitutionCountryCode; break;
			case  Bitmap::PointOfServiceEntryMode: de = new PointOfServiceEntryMode; break;
			case  Bitmap::NetworkInternationalIdentifier: de = new NetworkInternationalIdentifier; break;
			case  Bitmap::PointOfServiceConditionCode: de = new PointOfServiceConditionCode; break;
			case  Bitmap::PointOfServicePINCaptureCode: de = new PointOfServicePINCaptureCode; break;
			case  Bitmap::AuthorizationIdentificationResponseLength: de = new AuthorizationIdentificationResponseLength; break;
			case  Bitmap::TransactionFeeAmount: de = new TransactionFeeAmount; break;
			case  Bitmap::SettlementFeeAmount: de = new SettlementFeeAmount; break;
			case  Bitmap::TransactionProcessingFeeAmount: de = new TransactionProcessingFeeAmount; break;
			case  Bitmap::SettlementProcessingFeeAmount: de = new SettlementProcessingFeeAmount; break;
			case  Bitmap::AcquiringInstitutionIdentificationCode: de = new AcquiringInstitutionIdentificationCode; break;
			case  Bitmap::AuthorizationIdentificationResponse: de = new AuthorizationIdentificationResponse; break;
			case  Bitmap::ResponseCode: de = new ResponseCode; break;
			case  Bitmap::ServiceRestrictionCode: de = new ServiceRestrictionCode; break;
			case  Bitmap::TransactionCurrencyCode: de = new TransactionCurrencyCode; break;
			case  Bitmap::NationalData: de = new NationalData; break;
#elif STD_ISO_8583 == 1993

#elif STD_ISO_8583 == 2003
			case  Bitmap::ActionCode: de = new ActionCode; break;
			case  Bitmap::AcquirerReferenceNumber: de = new AcquirerReferenceNumber; break;
			case  Bitmap::ReconciliationAmount: de = new ReconciliationAmount; break;
			case  Bitmap::FeesAmounts: de = new FeesAmounts; break;
			case  Bitmap::OriginalAmounts: de = new OriginalAmounts; break;
			case  Bitmap::OriginalFeesAmounts: de = new OriginalFeesAmounts; break;
			case  Bitmap::ApprovalCode: de = new ApprovalCode; break;
			case  Bitmap::ConversionRateReconciliation: de = new ConversionRateReconciliation; break;
			case  Bitmap::DataRecord: de = new DataRecord; break;
			case  Bitmap::DateAction: de = new DateAction; break;
			case  Bitmap::DateAndTimeLocalTransaction: de = new DateAndTimeLocalTransaction; break;
			case  Bitmap::ReconciliationIndicator: de = new ReconciliationIndicator; break;
			case  Bitmap::DateReconciliation: de = new DateReconciliation; break;
			case  Bitmap::MerchantCategoryCode: de = new MerchantCategoryCode; break;
			case  Bitmap::MessageReasonCode: de = new MessageReasonCode; break;
			case  Bitmap::POSCapability: de = new POSCapability; break;
			case  Bitmap::POSDataCode: de = new POSDataCode; break;
			case  Bitmap::FunctionCode: de = new FunctionCode; break;
			case  Bitmap::ServiceCode: de = new ServiceCode; break;
			case  Bitmap::NetReconciliationAmount: de = new NetReconciliationAmount; break;
			case  Bitmap::AuthorizationLifeCycleCode: de = new AuthorizationLifeCycleCode; break;
			case  Bitmap::AuthorizingAgentInstitutionIdentificationCode: de = new AuthorizingAgentInstitutionIdentificationCode; break;
			case  Bitmap::CardIssuerReferenceData: de = new CardIssuerReferenceData; break;
			case  Bitmap::EffectiveDate: de = new EffectiveDate; break;
			case  Bitmap::ElectronicCommerceData: de = new ElectronicCommerceData; break;
			case  Bitmap::ExtendedPaymentData: de = new ExtendedPaymentData; break;
			case  Bitmap::FileTransferControlData: de = new FileTransferControlData; break;
			case  Bitmap::FileTransferDescriptionData: de = new FileTransferDescriptionData; break;
			case  Bitmap::FileTransferMessageControl: de = new FileTransferMessageControl; break;
			case  Bitmap::ICCSystemRelatedData: de = new ICCSystemRelatedData; break;
			case  Bitmap::KeyManagementData: de = new KeyManagementData; break;
			case  Bitmap::MessageErrorIndicator: de = new MessageErrorIndicator; break;
			case  Bitmap::ReconciliationDataPrimary: de = new ReconciliationDataPrimary; break;
			case  Bitmap::ReconciliationDataSecondary: de = new ReconciliationDataSecondary; break;
			case  Bitmap::ReconciliationFeeAmountsCredit: de = new ReconciliationFeeAmountsCredit; break;
			case  Bitmap::ReconciliationFeeAmountsDebit: de = new ReconciliationFeeAmountsDebit; break;
			case  Bitmap::TransactionDestinationInstitutionIdentificationCode: de = new TransactionDestinationInstitutionIdentificationCode; break;
			case  Bitmap::TransactionLifeCycleIdentificationData: de = new TransactionLifeCycleIdentificationData; break;
			case  Bitmap::TransactionOriginatorInstitutionIdentificationCode: de = new TransactionOriginatorInstitutionIdentificationCode; break;
			case  Bitmap::TransactionSpecificData: de = new TransactionSpecificData; break;
			case  Bitmap::VerificationData: de = new VerificationData; break;
#endif
			case  Bitmap::TransmissionDateAndTime: de = new TransmissionDateAndTime; break;
			case  Bitmap::AdditionalDataNational: de = new AdditionalDataNational; break;
			case  Bitmap::AdditionalDataPrivate: de = new AdditionalDataPrivate; break;
			case  Bitmap::AdditionalResponseData: de = new AdditionalResponseData; break;
			case  Bitmap::CardHolderBillingAmount: de = new CardHolderBillingAmount; break;
			case  Bitmap::CardHolderBillingFeeAmount: de = new CardHolderBillingFeeAmount; break;
			case  Bitmap::TransactionAmount: de = new TransactionAmount; break;
			case  Bitmap::AdditionalAmounts: de = new AdditionalAmounts; break;
			case  Bitmap::CardAcceptorIdentificationCode: de = new CardAcceptorIdentificationCode; break;
			case  Bitmap::CardAcceptorNameOrlocation: de = new CardAcceptorNameOrlocation; break;
			case  Bitmap::CardAcceptorTerminalIdentification: de = new CardAcceptorTerminalIdentification; break;
			case  Bitmap::CardSequenceNumber: de = new CardSequenceNumber; break;
			case  Bitmap::ContinuationBit: break;
			case  Bitmap::CardHolderBillingConversionRate: de = new CardHolderBillingConversionRate; break;
			case  Bitmap::CaptureDate: de = new CaptureDate; break;
			case  Bitmap::ConversionDate: de = new ConversionDate; break;
			case  Bitmap::ExpirationDate: de = new ExpirationDate; break;
			case  Bitmap::FileName: de = new FileName; break;
			case  Bitmap::ForwardingInstitutionIdentificationCode: de = new ForwardingInstitutionIdentificationCode; break;
			case  Bitmap::MACField: de = new MACField; break;
			case  Bitmap::OriginalDataElements: de = new OriginalDataElements; break;
			case  Bitmap::PINData: de = new PINData; break;
			case  Bitmap::Payee: de = new Payee; break;
			case  Bitmap::PrimaryAccountNumber:	de = new PrimaryAccountNumber; break;
			case  Bitmap::ProcessingCode: de = new ProcessingCode; break;
			case  Bitmap::ReceivingInstitutionIdentificationCode: de = new ReceivingInstitutionIdentificationCode; break;
			case  Bitmap::RetrievalReferenceNumber: de = new RetrievalReferenceNumber; break;
			case  Bitmap::SecurityRelatedControlInformation: de = new SecurityRelatedControlInformation; break;
			case  Bitmap::SettlementInstitutionIdentificationCode: de = new SettlementInstitutionIdentificationCode; break;
			case  Bitmap::SystemsTraceAuditNumber: de = new SystemsTraceAuditNumber; break;
			case  Bitmap::Track1Data: de = new Track1Data; break;
			case  Bitmap::Track2Data: de = new Track2Data; break;
			case  Bitmap::Track3Data: de = new Track3Data; break;
			default: throw invalid_argument(string("Message: erroneous bitmap no:") + to_string((int)bitno));
			}
			return de;
		}
	}
}