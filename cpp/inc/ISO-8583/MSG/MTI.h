/*
 * MTI.h
 *
 *  Created on: 18 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef MTI_H_
#define MTI_H_

#include <iostream>
using std::ostream;
using std::istream;

#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"
using ISO_8583::DTT::InputStream;
using ISO_8583::DTT::OutputStream;

#include "ISO-8583/MSG/ISO-8583-MSG.h"


namespace ISO_8583 {
	namespace MSG {

		enum class Version  : byte {
			ISO_8583_1_1987 = '0',
			ISO_8583_1_1993 = '1',
			ISO_8583_1_2003 = '2'
		};
		enum class Class : byte {
			Authorization = '1',
			Financial = '2',
			FileAction = '3',
			Reversal = '4',
			Reconciliation = '5',
			Administrative = '6',
			FeeCollection = '7',
			Network = '8',
			RESERVED = '9'
		};
		enum class Function : byte  {
			Request = '0',
			RequestResponse = '1',
			Advice = '2',
			AdviceResponse = '3',
			Notification = '4',
			NotificationAcknowledge = '5',
			Instruction = '6',
			InstructionAcknowledge = '7',
			RESPONSE_ACKNOWLEDGEMENT = '8',
			NEGATIVE_ACKNOWLEDGEMENT = '9'
		};

		enum class Origin  : byte {
			Acquirer = '0',
			AcquirerRepeat = '1',
			Issuer = '2',
			IssuerRepeat = '3',
			Chargeback = '2',
			ChargebackRepeat = '3',
			Other = '4',
			OtherRepeat = '5',
			Acceptor = '6',
			AcceptorRepeat = '7'
		};

		class MSG_API_SCOPE MTI {
		public:
#if STD_CB2A == 150
			typedef byte MTIType;

		private:
			MTIType b0;
			MTIType b1;

		public:
			MTI() : b0(0), b1(0)		{}
			MTI(Class klass, Function function, Origin origin) : b0(0), b1(0) {
#if STD_CB2A == 150
				b0 |= (byte(Version::ISO_8583_1_1987)  - '0') << 4;
#elif STD_ISO_8583 == 1993
				b0 |= (byte(Version::ISO_8583_1_1993)  - '0') << 4;
#elif STD_ISO_8583 == 2003
				b0 |= (byte(Version::ISO_8583_1_2003)  - '0') << 4;
#endif
				b0 |= (byte(klass) - '0') & 0x0F;
				b1 |= (byte(function) - '0') << 4;
				b1 |= (byte(origin)  - '0')& 0x0F;
			}
			virtual ~MTI() {}

			const Version version() const	{ return (Version)((b0 >> 4) + '0'); }
			const Class klass() const		{ return (Class)((b0 & 0x0F) + '0'); }
			const Function function() const	{ return (Function)((b1 >> 4) + '0'); }
			const Origin origin() const		{ return (Origin)((b1 & 0x0F) + '0'); }
			void  origin(Origin origin)		{ b1 &= 0xF0; b1 |= (byte(origin) - '0') & 0x0F; }
			const MTIType& first() const	{ return b0; }
			const MTIType& second() const	{ return b1; }

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
			typedef byte MTIType;

		private:
			Version mVersion;
			Class mClass;
			Function mFunction;
			Origin mOrigin;

		public:
			MTI() : 
#if   STD_ISO_8583 == 1987
				mVersion(Version::ISO_8583_1_1987),
#elif STD_ISO_8583 == 1993
				mVersion(Version::ISO_8583_1_1993),
#elif STD_ISO_8583 == 2003
				mVersion(Version::ISO_8583_1_2003),
#endif
				mClass(Class::Authorization),	 
				mFunction(Function::Request),	 
				mOrigin(Origin::Acquirer)	{}

			MTI(Class klass, Function function, Origin origin)  {
#if   STD_ISO_8583 == 1987
				mVersion = Version::ISO_8583_1_1987;
#elif STD_ISO_8583 == 1993
				mVersion = Version::ISO_8583_1_1993;
#elif STD_ISO_8583 == 2003
				mVersion = Version::ISO_8583_1_2003;
#endif
				mClass = klass;
				mFunction = function;
				mOrigin = origin;
			}
			virtual ~MTI() {}

			const Version version() const	{ return (Version)mVersion; }
			const Class klass() const		{ return (Class)mClass; }
			const Function function() const	{ return (Function)mFunction; }
			const Origin origin() const		{ return (Origin)mOrigin; }
			void  origin(Origin origin)		{ mOrigin = origin; }
#endif

			friend MSG_API_SCOPE InputStream& operator>>(InputStream& is, MTI& mti);
			friend MSG_API_SCOPE OutputStream& operator<<(OutputStream& os, const MTI& mti);
		};
	}
}
#endif
