/*
 * DefaultImplementation.h
 *
 *  Created on: 12 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTIMPLEMENTATION_H_
#define DEFAULTIMPLEMENTATION_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"

#include "ISO-8583/MSG/AdministrativeAdvice.h"
#include "ISO-8583/MSG/AdministrativeInstruction.h"
#include "ISO-8583/MSG/AdministrativeNotification.h"
#include "ISO-8583/MSG/AdministrativeRequest.h"
#include "ISO-8583/MSG/AdministrativeAdviceResponse.h"
#include "ISO-8583/MSG/AdministrativeInstructionAcknowledge.h"
#include "ISO-8583/MSG/AdministrativeNotificationAcknowledge.h"
#include "ISO-8583/MSG/AdministrativeRequestResponse.h"

#include "ISO-8583/MSG/AuthorizationAdvice.h"
#include "ISO-8583/MSG/AuthorizationInstruction.h"
#include "ISO-8583/MSG/AuthorizationNotification.h"
#include "ISO-8583/MSG/AuthorizationRequest.h"
#include "ISO-8583/MSG/AuthorizationAdviceResponse.h"
#include "ISO-8583/MSG/AuthorizationInstructionAcknowledge.h"
#include "ISO-8583/MSG/AuthorizationNotificationAcknowledge.h"
#include "ISO-8583/MSG/AuthorizationRequestResponse.h"

#include "ISO-8583/MSG/FileActionAdvice.h"
#include "ISO-8583/MSG/FileActionInstruction.h"
#include "ISO-8583/MSG/FileActionNotification.h"
#include "ISO-8583/MSG/FileActionRequest.h"
#include "ISO-8583/MSG/FileActionAdviceResponse.h"
#include "ISO-8583/MSG/FileActionInstructionAcknowledge.h"
#include "ISO-8583/MSG/FileActionNotificationAcknowledge.h"
#include "ISO-8583/MSG/FileActionRequestResponse.h"

#include "ISO-8583/MSG/FinancialAdvice.h"
#include "ISO-8583/MSG/FinancialInstruction.h"
#include "ISO-8583/MSG/FinancialNotification.h"
#include "ISO-8583/MSG/FinancialRequest.h"
#include "ISO-8583/MSG/FinancialAdviceResponse.h"
#include "ISO-8583/MSG/FinancialInstructionAcknowledge.h"
#include "ISO-8583/MSG/FinancialNotificationAcknowledge.h"
#include "ISO-8583/MSG/FinancialRequestResponse.h"

#include "ISO-8583/MSG/NetworkAdvice.h"
#include "ISO-8583/MSG/NetworkInstruction.h"
#include "ISO-8583/MSG/NetworkNotification.h"
#include "ISO-8583/MSG/NetworkRequest.h"
#include "ISO-8583/MSG/NetworkAdviceResponse.h"
#include "ISO-8583/MSG/NetworkInstructionAcknowledge.h"
#include "ISO-8583/MSG/NetworkNotificationAcknowledge.h"
#include "ISO-8583/MSG/NetworkRequestResponse.h"

#include "ISO-8583/MSG/ReconciliationAdvice.h"
#include "ISO-8583/MSG/ReconciliationInstruction.h"
#include "ISO-8583/MSG/ReconciliationNotification.h"
#include "ISO-8583/MSG/ReconciliationRequest.h"
#include "ISO-8583/MSG/ReconciliationAdviceResponse.h"
#include "ISO-8583/MSG/ReconciliationInstructionAcknowledge.h"
#include "ISO-8583/MSG/ReconciliationNotificationAcknowledge.h"
#include "ISO-8583/MSG/ReconciliationRequestResponse.h"

#include "ISO-8583/MSG/ReversalAdvice.h"
#include "ISO-8583/MSG/ReversalInstruction.h"
#include "ISO-8583/MSG/ReversalNotification.h"
#include "ISO-8583/MSG/ReversalRequest.h"
#include "ISO-8583/MSG/ReversalAdviceResponse.h"
#include "ISO-8583/MSG/ReversalInstructionAcknowledge.h"
#include "ISO-8583/MSG/ReversalNotificationAcknowledge.h"
#include "ISO-8583/MSG/ReversalRequestResponse.h"


namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_QUESTION(Prefix, Administrative, Advice, Response)
		CLASS_DEFINITION_QUESTION(Prefix, Administrative, Instruction, Acknowledge)
		CLASS_DEFINITION_QUESTION(Prefix, Administrative, Notification, Acknowledge)
		CLASS_DEFINITION_QUESTION(Prefix, Administrative, Request, Response)
		CLASS_DEFINITION_RESPONSE(Prefix, Administrative, Advice, Response)
		CLASS_DEFINITION_RESPONSE(Prefix, Administrative, Instruction, Acknowledge)
		CLASS_DEFINITION_RESPONSE(Prefix, Administrative, Notification, Acknowledge)
		CLASS_DEFINITION_RESPONSE(Prefix, Administrative, Request, Response)

		CLASS_DEFINITION_QUESTION(Prefix, Authorization, Advice, Response)
		CLASS_DEFINITION_QUESTION(Prefix, Authorization, Instruction, Acknowledge)
		CLASS_DEFINITION_QUESTION(Prefix, Authorization, Notification, Acknowledge)
		CLASS_DEFINITION_QUESTION(Prefix, Authorization, Request, Response)
		CLASS_DEFINITION_RESPONSE(Prefix, Authorization, Advice, Response)
		CLASS_DEFINITION_RESPONSE(Prefix, Authorization, Instruction, Acknowledge)
		CLASS_DEFINITION_RESPONSE(Prefix, Authorization, Notification, Acknowledge)
		CLASS_DEFINITION_RESPONSE(Prefix, Authorization, Request, Response)

		CLASS_DEFINITION_QUESTION(Prefix, FileAction, Advice, Response)
		CLASS_DEFINITION_QUESTION(Prefix, FileAction, Instruction, Acknowledge)
		CLASS_DEFINITION_QUESTION(Prefix, FileAction, Notification, Acknowledge)
		CLASS_DEFINITION_QUESTION(Prefix, FileAction, Request, Response)
		CLASS_DEFINITION_RESPONSE(Prefix, FileAction, Advice, Response)
		CLASS_DEFINITION_RESPONSE(Prefix, FileAction, Instruction, Acknowledge)
		CLASS_DEFINITION_RESPONSE(Prefix, FileAction, Notification, Acknowledge)
		CLASS_DEFINITION_RESPONSE(Prefix, FileAction, Request, Response)

		CLASS_DEFINITION_QUESTION(Prefix, Financial, Advice, Response)
		CLASS_DEFINITION_QUESTION(Prefix, Financial, Instruction, Acknowledge)
		CLASS_DEFINITION_QUESTION(Prefix, Financial, Notification, Acknowledge)
		CLASS_DEFINITION_QUESTION(Prefix, Financial, Request, Response)
		CLASS_DEFINITION_RESPONSE(Prefix, Financial, Advice, Response)
		CLASS_DEFINITION_RESPONSE(Prefix, Financial, Instruction, Acknowledge)
		CLASS_DEFINITION_RESPONSE(Prefix, Financial, Notification, Acknowledge)
		CLASS_DEFINITION_RESPONSE(Prefix, Financial, Request, Response)

		CLASS_DEFINITION_QUESTION(Prefix, Network, Advice, Response)
		CLASS_DEFINITION_QUESTION(Prefix, Network, Instruction, Acknowledge)
		CLASS_DEFINITION_QUESTION(Prefix, Network, Notification, Acknowledge)
		CLASS_DEFINITION_QUESTION(Prefix, Network, Request, Response)
		CLASS_DEFINITION_RESPONSE(Prefix, Network, Advice, Response)
		CLASS_DEFINITION_RESPONSE(Prefix, Network, Instruction, Acknowledge)
		CLASS_DEFINITION_RESPONSE(Prefix, Network, Notification, Acknowledge)
		CLASS_DEFINITION_RESPONSE(Prefix, Network, Request, Response)

		CLASS_DEFINITION_QUESTION(Prefix, Reconciliation, Advice, Response)
		CLASS_DEFINITION_QUESTION(Prefix, Reconciliation, Instruction, Acknowledge)
		CLASS_DEFINITION_QUESTION(Prefix, Reconciliation, Notification, Acknowledge)
		CLASS_DEFINITION_QUESTION(Prefix, Reconciliation, Request, Response)
		CLASS_DEFINITION_RESPONSE(Prefix, Reconciliation, Advice, Response)
		CLASS_DEFINITION_RESPONSE(Prefix, Reconciliation, Instruction, Acknowledge)
		CLASS_DEFINITION_RESPONSE(Prefix, Reconciliation, Notification, Acknowledge)
		CLASS_DEFINITION_RESPONSE(Prefix, Reconciliation, Request, Response)

		CLASS_DEFINITION_QUESTION(Prefix, Reversal, Advice, Response)
		CLASS_DEFINITION_QUESTION(Prefix, Reversal, Instruction, Acknowledge)
		CLASS_DEFINITION_QUESTION(Prefix, Reversal, Notification, Acknowledge)
		CLASS_DEFINITION_QUESTION(Prefix, Reversal, Request, Response)
		CLASS_DEFINITION_RESPONSE(Prefix, Reversal, Advice, Response)
		CLASS_DEFINITION_RESPONSE(Prefix, Reversal, Instruction, Acknowledge)
		CLASS_DEFINITION_RESPONSE(Prefix, Reversal, Notification, Acknowledge)
		CLASS_DEFINITION_RESPONSE(Prefix, Reversal, Request, Response)
	}
}

#endif
