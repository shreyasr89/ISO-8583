/*
 * DefaultFactory.cpp
 *
 *  Created on: 4 août 2015
 *      Author: FrancisANDRE
 */
#include "Poco/ClassLibrary.h"

#ifndef POCO_EXPORT_INTERFACE

#define POCO_EXPORT_INTERFACE(cls, itf) \
    pManifest->insert(new Poco::MetaObject<cls, _Base>(itf));

#endif


#include "ISO-8583/MSG/Request.h"
#include "ISO-8583/MSG/Advice.h"
#include "ISO-8583/MSG/Notification.h"
#include "ISO-8583/MSG/Instruction.h"

#include "ISO-8583/MSG/RequestResponse.h"
#include "ISO-8583/MSG/AdviceResponse.h"
#include "ISO-8583/MSG/NotificationAcknowledge.h"
#include "ISO-8583/MSG/InstructionAcknowledge.h"

#include "ISO-8583/MSG/Factory.h"
#include "ISO-8583/DFT/DefaultImplementation.h"

#include "ISO-8583/DFT/DefaultFactory.h"


using namespace std;
using namespace ISO_8583::MSG;

void pocoInitializeLibrary()
{
//	cout << "DefaultMessageLibrary initializing" << std::endl;
}
void pocoUninitializeLibrary()
{
//	cout << "DefaultMessageLibrary uninitializing" << std::endl;
}
POCO_BEGIN_NAMED_MANIFEST(Request, Request)
	POCO_EXPORT_INTERFACE(concat2(Prefix, AuthorizationRequest), Factory::AuthorizationRequestInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, FinancialRequest), Factory::FinancialRequestInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, FileActionRequest), Factory::FileActionRequestInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, ReversalRequest), Factory::ReversalRequestInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, ReconciliationRequest), Factory::ReconciliationRequestInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, AdministrativeRequest), Factory::AdministrativeRequestInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, NetworkRequest), Factory::NetworkRequestInterface)
POCO_END_MANIFEST

POCO_BEGIN_NAMED_MANIFEST(Advice, Advice)
	POCO_EXPORT_INTERFACE(concat2(Prefix, AuthorizationAdvice), Factory::AuthorizationAdviceInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, FinancialAdvice), Factory::FinancialAdviceInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, FileActionAdvice), Factory::FileActionAdviceInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, ReversalAdvice), Factory::ReversalAdviceInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, ReconciliationAdvice), Factory::ReconciliationAdviceInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, AdministrativeAdvice), Factory::AdministrativeAdviceInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, NetworkAdvice), Factory::NetworkAdviceInterface)
POCO_END_MANIFEST

POCO_BEGIN_NAMED_MANIFEST(Notification, Notification)
	POCO_EXPORT_INTERFACE(concat2(Prefix, AuthorizationNotification), Factory::AuthorizationNotificationInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, FinancialNotification), Factory::FinancialNotificationInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, FileActionNotification), Factory::FileActionNotificationInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, ReversalNotification), Factory::ReversalNotificationInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, ReconciliationNotification), Factory::ReconciliationNotificationInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, AdministrativeNotification), Factory::AdministrativeNotificationInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, NetworkNotification), Factory::NetworkNotificationInterface)
POCO_END_MANIFEST

POCO_BEGIN_NAMED_MANIFEST(Instruction, Instruction)
	POCO_EXPORT_INTERFACE(concat2(Prefix, AuthorizationInstruction), Factory::AuthorizationInstructionInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, FinancialInstruction), Factory::FinancialInstructionInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, FileActionInstruction), Factory::FileActionInstructionInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, ReversalInstruction), Factory::ReversalInstructionInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, ReconciliationInstruction), Factory::ReconciliationInstructionInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, AdministrativeInstruction), Factory::AdministrativeInstructionInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, NetworkInstruction), Factory::NetworkInstructionInterface)
POCO_END_MANIFEST

POCO_BEGIN_NAMED_MANIFEST(RequestResponse, RequestResponse)
	POCO_EXPORT_INTERFACE(concat2(Prefix, AuthorizationRequestResponse), Factory::AuthorizationRequestResponseInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, FinancialRequestResponse), Factory::FinancialRequestResponseInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, FileActionRequestResponse), Factory::FileActionRequestResponseInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, ReversalRequestResponse), Factory::ReversalRequestResponseInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, ReconciliationRequestResponse), Factory::ReconciliationRequestResponseInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, AdministrativeRequestResponse), Factory::AdministrativeRequestResponseInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, NetworkRequestResponse), Factory::NetworkRequestResponseInterface)
POCO_END_MANIFEST

POCO_BEGIN_NAMED_MANIFEST(AdviceResponse, AdviceResponse)
	POCO_EXPORT_INTERFACE(concat2(Prefix, AuthorizationAdviceResponse), Factory::AuthorizationAdviceResponseInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, FinancialAdviceResponse), Factory::FinancialAdviceResponseInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, FileActionAdviceResponse), Factory::FileActionAdviceResponseInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, ReversalAdviceResponse), Factory::ReversalAdviceResponseInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, ReconciliationAdviceResponse), Factory::ReconciliationAdviceResponseInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, AdministrativeAdviceResponse), Factory::AdministrativeAdviceResponseInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, NetworkAdviceResponse), Factory::NetworkAdviceResponseInterface)
POCO_END_MANIFEST

POCO_BEGIN_NAMED_MANIFEST(NotificationAcknowledge, NotificationAcknowledge)
	POCO_EXPORT_INTERFACE(concat2(Prefix, AuthorizationNotificationAcknowledge), Factory::AuthorizationNotificationAcknowledgeInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, FinancialNotificationAcknowledge), Factory::FinancialNotificationAcknowledgeInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, FileActionNotificationAcknowledge), Factory::FileActionNotificationAcknowledgeInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, ReversalNotificationAcknowledge), Factory::ReversalNotificationAcknowledgeInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, ReconciliationNotificationAcknowledge), Factory::ReconciliationNotificationAcknowledgeInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, AdministrativeNotificationAcknowledge), Factory::AdministrativeNotificationAcknowledgeInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, NetworkNotificationAcknowledge), Factory::NetworkNotificationAcknowledgeInterface)
POCO_END_MANIFEST

POCO_BEGIN_NAMED_MANIFEST(InstructionAcknowledge, InstructionAcknowledge)
	POCO_EXPORT_INTERFACE(concat2(Prefix, AuthorizationInstructionAcknowledge), Factory::AuthorizationInstructionAcknowledgeInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, FinancialInstructionAcknowledge), Factory::FinancialInstructionAcknowledgeInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, FileActionInstructionAcknowledge), Factory::FileActionInstructionAcknowledgeInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, ReversalInstructionAcknowledge), Factory::ReversalInstructionAcknowledgeInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, ReconciliationInstructionAcknowledge), Factory::ReconciliationInstructionAcknowledgeInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, AdministrativeInstructionAcknowledge), Factory::AdministrativeInstructionAcknowledgeInterface)
	POCO_EXPORT_INTERFACE(concat2(Prefix, NetworkInstructionAcknowledge), Factory::NetworkInstructionAcknowledgeInterface)
POCO_END_MANIFEST
namespace ISO_8583 {
	namespace MSG {

		DefaultFactory::DefaultFactory() {
		}
		DefaultFactory:: ~DefaultFactory() {
		}
	}
}
