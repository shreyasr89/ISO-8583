/*
 * Factory.h
 *
 *  Created on: 2 août 2015
 *      Author: FrancisANDRE
 */

#ifndef FACTORY_H_
#define FACTORY_H_

#include "Poco/ClassLoader.h"
#include "Poco/Manifest.h"
using Poco::ClassLoader;
using Poco::Manifest;

#include "ISO-8583/MSG/ISO-8583-MSG.h"
#include "ISO-8583/MSG/MTI.h"
#include "ISO-8583/MSG/Request.h"
#include "ISO-8583/MSG/Advice.h"
#include "ISO-8583/MSG/Notification.h"
#include "ISO-8583/MSG/Instruction.h"
#include "ISO-8583/MSG/RequestResponse.h"
#include "ISO-8583/MSG/AdviceResponse.h"
#include "ISO-8583/MSG/NotificationAcknowledge.h"
#include "ISO-8583/MSG/InstructionAcknowledge.h"
using ISO_8583::MSG::Origin;
using ISO_8583::MSG::Request;
using ISO_8583::MSG::Notification;
using ISO_8583::MSG::Advice;
using ISO_8583::MSG::Instruction;

#include "ISO-8583/DTT/BinaryInputStream.h"
using ISO_8583::DTT::BinaryInputStream;


namespace ISO_8583 {
	namespace MSG {
		class Message;
		class AuthorizationRequest;
		class ReversalRequest;
		class NetworkRequest;
		class RequestResponse;
		class AuthorizationRequestResponse;
		class ReversalRequestResponse;
		class NetworkRequestResponse;

		class MSG_API_SCOPE Factory {
		public:
			typedef ClassLoader<Request>				RequestLoader;
			typedef ClassLoader<Notification>			NotificationLoader;
			typedef ClassLoader<Advice>					AdviceLoader;
			typedef ClassLoader<Instruction>			InstructionLoader;

			typedef ClassLoader<RequestResponse>		RequestResponseLoader;
			typedef ClassLoader<AdviceResponse>			AdviceResponseLoader;
			typedef ClassLoader<NotificationAcknowledge>NotificationAcknowledgeLoader;
			typedef ClassLoader<InstructionAcknowledge>	InstructionAcknowledgeLoader;

			typedef Manifest<Request>					RequestManifest;
			typedef Manifest<Notification>				NotificationManifest;
			typedef Manifest<Advice>					AdviceManifest;
			typedef Manifest<Instruction>				InstructionManifest;

			typedef Manifest<RequestResponse>			RequestResponseManifest;
			typedef Manifest<AdviceResponse>			AdviceResponseManifest;
			typedef Manifest<NotificationAcknowledge>	NotificationAcknowledgeManifest;
			typedef Manifest<InstructionAcknowledge>	InstructionAcknowledgeManifest;

		protected:
			RequestLoader					requestLoader;
			NotificationLoader				notificationLoader;
			AdviceLoader					adviceLoader;
			InstructionLoader				instructionLoader;

			RequestResponseLoader			requestResponseLoader;
			AdviceResponseLoader			adviceResponseLoader;
			NotificationAcknowledgeLoader	notificationAcknowledgeLoader;
			InstructionAcknowledgeLoader	instructionAcknowledgeLoader;

			RequestManifest					requestManifest;
			NotificationManifest			notificationManifest;
			AdviceManifest					adviceManifest;
			InstructionManifest				instructionManifest;

			RequestResponseManifest			requestResponseManifest;
			AdviceResponseManifest			adviceResponseManifest;
			NotificationAcknowledgeManifest	notificationAcknowledgeManifest;
			InstructionAcknowledgeManifest	instructionAcknowledgeManifest;


			string library;

		public:
			static const char* RequestInterface;
			static const char* NotificationInterface;
			static const char* AdviceInterface;
			static const char* InstructionInterface;

			static const char* RequestResponseInterface;
			static const char* AdviceResponseInterface;
			static const char* NotificationAcknowledgeInterface;
			static const char* InstructionAcknowledgeInterface;

			static const char* AuthorizationRequestInterface;
			static const char* FinancialRequestInterface;
			static const char* FileActionRequestInterface;
			static const char* ReversalRequestInterface;
			static const char* ReconciliationRequestInterface;
			static const char* AdministrativeRequestInterface;
			static const char* NetworkRequestInterface;

			static const char* AuthorizationRequestResponseInterface;
			static const char* FinancialRequestResponseInterface;
			static const char* FileActionRequestResponseInterface;
			static const char* ReversalRequestResponseInterface;
			static const char* ReconciliationRequestResponseInterface;
			static const char* AdministrativeRequestResponseInterface;
			static const char* NetworkRequestResponseInterface;

			static const char* AuthorizationAdviceInterface;
			static const char* FinancialAdviceInterface;
			static const char* FileActionAdviceInterface;
			static const char* ReversalAdviceInterface;
			static const char* ReconciliationAdviceInterface;
			static const char* AdministrativeAdviceInterface;
			static const char* NetworkAdviceInterface;

			static const char* AuthorizationAdviceResponseInterface;
			static const char* FinancialAdviceResponseInterface;
			static const char* FileActionAdviceResponseInterface;
			static const char* ReversalAdviceResponseInterface;
			static const char* ReconciliationAdviceResponseInterface;
			static const char* AdministrativeAdviceResponseInterface;
			static const char* NetworkAdviceResponseInterface;

			static const char* AuthorizationNotificationInterface;
			static const char* FinancialNotificationInterface;
			static const char* FileActionNotificationInterface;
			static const char* ReversalNotificationInterface;
			static const char* ReconciliationNotificationInterface;
			static const char* AdministrativeNotificationInterface;
			static const char* NetworkNotificationInterface;

			static const char* AuthorizationNotificationAcknowledgeInterface;
			static const char* FinancialNotificationAcknowledgeInterface;
			static const char* FileActionNotificationAcknowledgeInterface;
			static const char* ReversalNotificationAcknowledgeInterface;
			static const char* ReconciliationNotificationAcknowledgeInterface;
			static const char* AdministrativeNotificationAcknowledgeInterface;
			static const char* NetworkNotificationAcknowledgeInterface;

			static const char* AuthorizationInstructionInterface;
			static const char* FinancialInstructionInterface;
			static const char* FileActionInstructionInterface;
			static const char* ReversalInstructionInterface;
			static const char* ReconciliationInstructionInterface;
			static const char* AdministrativeInstructionInterface;
			static const char* NetworkInstructionInterface;

			static const char* AuthorizationInstructionAcknowledgeInterface;
			static const char* FinancialInstructionAcknowledgeInterface;
			static const char* FileActionInstructionAcknowledgeInterface;
			static const char* ReversalInstructionAcknowledgeInterface;
			static const char* ReconciliationInstructionAcknowledgeInterface;
			static const char* AdministrativeInstructionAcknowledgeInterface;
			static const char* NetworkInstructionAcknowledgeInterface;


		public:
			Factory(const string& library);
			virtual ~Factory();

			MSG::Request*					newAuthorizationRequest(Origin origin) const;
			MSG::Request*					newFinancialRequest(Origin origin) const;
			MSG::Request*					newFileActionRequest(Origin origin) const;
			MSG::Request*					newReversalRequest(Origin origin) const;
			MSG::Request*					newReconciliationRequest(Origin origin) const;
			MSG::Request*					newAdministrativeRequest(Origin origin) const;
			MSG::Request*					newNetworkRequest(Origin origin) const;

			MSG::RequestResponse*			newAuthorizationRequestResponse(Origin origin) const;
			MSG::RequestResponse*			newFinancialRequestResponse(Origin origin) const;
			MSG::RequestResponse*			newFileActionRequestResponse(Origin origin) const;
			MSG::RequestResponse*			newReversalRequestResponse(Origin origin) const;
			MSG::RequestResponse*			newReconciliationRequestResponse(Origin origin) const;
			MSG::RequestResponse*			newAdministrativeRequestResponse(Origin origin) const;
			MSG::RequestResponse*			newNetworkRequestResponse(Origin origin) const;

			MSG::Advice*					newAuthorizationAdvice(Origin origin) const;
			MSG::Advice*					newFinancialAdvice(Origin origin) const;
			MSG::Advice*					newFileActionAdvice(Origin origin) const;
			MSG::Advice*					newReversalAdvice(Origin origin) const;
			MSG::Advice*					newReconciliationAdvice(Origin origin) const;
			MSG::Advice*					newAdministrativeAdvice(Origin origin) const;
			MSG::Advice*					newNetworkAdvice(Origin origin) const;

			MSG::AdviceResponse*			newAuthorizationAdviceResponse(Origin origin) const;
			MSG::AdviceResponse*			newFinancialAdviceResponse(Origin origin) const;
			MSG::AdviceResponse*			newFileActionAdviceResponse(Origin origin) const;
			MSG::AdviceResponse*			newReversalAdviceResponse(Origin origin) const;
			MSG::AdviceResponse*			newReconciliationAdviceResponse(Origin origin) const;
			MSG::AdviceResponse*			newAdministrativeAdviceResponse(Origin origin) const;
			MSG::AdviceResponse*			newNetworkAdviceResponse(Origin origin) const;

			MSG::Notification*				newAuthorizationNotification(Origin origin) const;
			MSG::Notification*				newFinancialNotification(Origin origin) const;
			MSG::Notification*				newFileActionNotification(Origin origin) const;
			MSG::Notification*				newReversalNotification(Origin origin) const;
			MSG::Notification*				newReconciliationNotification(Origin origin) const;
			MSG::Notification*				newAdministrativeNotification(Origin origin) const;
			MSG::Notification*				newNetworkNotification(Origin origin) const;

			MSG::NotificationAcknowledge*	newAuthorizationNotificationAcknowledge(Origin origin) const;
			MSG::NotificationAcknowledge*	newFinancialNotificationAcknowledge(Origin origin) const;
			MSG::NotificationAcknowledge*	newFileActionNotificationAcknowledge(Origin origin) const;
			MSG::NotificationAcknowledge*	newReversalNotificationAcknowledge(Origin origin) const;
			MSG::NotificationAcknowledge*	newReconciliationNotificationAcknowledge(Origin origin) const;
			MSG::NotificationAcknowledge*	newAdministrativeNotificationAcknowledge(Origin origin) const;
			MSG::NotificationAcknowledge*	newNetworkNotificationAcknowledge(Origin origin) const;

			MSG::Instruction*				newAuthorizationInstruction(Origin origin) const;
			MSG::Instruction*				newFinancialInstruction(Origin origin) const;
			MSG::Instruction*				newFileActionInstruction(Origin origin) const;
			MSG::Instruction*				newReversalInstruction(Origin origin) const;
			MSG::Instruction*				newReconciliationInstruction(Origin origin) const;
			MSG::Instruction*				newAdministrativeInstruction(Origin origin) const;
			MSG::Instruction*				newNetworkInstruction(Origin origin) const;

			MSG::InstructionAcknowledge*	newAuthorizationInstructionAcknowledge(Origin origin) const;
			MSG::InstructionAcknowledge*	newFinancialInstructionAcknowledge(Origin origin) const;
			MSG::InstructionAcknowledge*	newFileActionInstructionAcknowledge(Origin origin) const;
			MSG::InstructionAcknowledge*	newReversalInstructionAcknowledge(Origin origin) const;
			MSG::InstructionAcknowledge*	newReconciliationInstructionAcknowledge(Origin origin) const;
			MSG::InstructionAcknowledge*	newAdministrativeInstructionAcknowledge(Origin origin) const;
			MSG::InstructionAcknowledge*	newNetworkInstructionAcknowledge(Origin origin) const;

			Message*						newMessage(BinaryInputStream& is) const;
		};
	}
}

#endif
