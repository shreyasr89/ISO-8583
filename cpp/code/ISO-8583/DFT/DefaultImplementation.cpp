/*
 * Implementation.cpp
 *
 *  Created on: 12 août 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DFT/DefaultImplementation.h"


#define INDICATION(prefix, name, type, rettype) \
		type##rettype * concat3(prefix, name ,type)::indication(InputStream& is, OutputStream& os)

#define CONFIRMATION(prefix, name, type, rettype) \
		void concat4(prefix, name, type, rettype)::confirmation(InputStream& is, OutputStream& os)


namespace ISO_8583 {
	namespace MSG {
		INDICATION(Prefix, Administrative, Request, Response) { return NULL; }
		INDICATION(Prefix, Administrative, Advice, Response) { return NULL; }
		INDICATION(Prefix, Administrative, Notification, Acknowledge)  { return NULL; }
		INDICATION(Prefix, Administrative, Instruction, Acknowledge) { return NULL; }
		CONFIRMATION(Prefix, Administrative, Request, Response) {	}
		CONFIRMATION(Prefix, Administrative, Advice, Response) { }
		CONFIRMATION(Prefix, Administrative, Notification, Acknowledge) {	}
		CONFIRMATION(Prefix, Administrative, Instruction, Acknowledge) { }

//		INDICATION(Prefix, Authorization, Request, Response) { return NULL; }
		INDICATION(Prefix, Authorization, Advice, Response)  { return NULL; }
		INDICATION(Prefix, Authorization, Notification, Acknowledge) { return NULL; }
		INDICATION(Prefix, Authorization, Instruction, Acknowledge)  { return NULL; }
//		CONFIRMATION(Prefix, Authorization, Request, Response) { }
		CONFIRMATION(Prefix, Authorization, Advice, Response) { }
		CONFIRMATION(Prefix, Authorization, Notification, Acknowledge) { }
		CONFIRMATION(Prefix, Authorization, Instruction, Acknowledge) { }

		INDICATION(Prefix, FileAction, Request, Response) { return NULL; }
		INDICATION(Prefix, FileAction, Advice, Response) { return NULL; }
		INDICATION(Prefix, FileAction, Notification, Acknowledge) { return NULL; }
		INDICATION(Prefix, FileAction, Instruction, Acknowledge) { return NULL; }
		CONFIRMATION(Prefix, FileAction, Request, Response) { }
		CONFIRMATION(Prefix, FileAction, Advice, Response) { }
		CONFIRMATION(Prefix, FileAction, Notification, Acknowledge) { }
		CONFIRMATION(Prefix, FileAction, Instruction, Acknowledge) { }

		INDICATION(Prefix, Financial, Request, Response) { return NULL; }
		INDICATION(Prefix, Financial, Advice, Response) { return NULL; }
		INDICATION(Prefix, Financial, Notification, Acknowledge) { return NULL; }
		INDICATION(Prefix, Financial, Instruction, Acknowledge) { return NULL; }
		CONFIRMATION(Prefix, Financial, Request, Response) { }
		CONFIRMATION(Prefix, Financial, Advice, Response) { }
		CONFIRMATION(Prefix, Financial, Notification, Acknowledge) { }
		CONFIRMATION(Prefix, Financial, Instruction, Acknowledge) { }

		INDICATION(Prefix, Network, Request, Response) { return NULL; }
		INDICATION(Prefix, Network, Advice, Response) { return NULL; }
		INDICATION(Prefix, Network, Notification, Acknowledge) { return NULL; }
		INDICATION(Prefix, Network, Instruction, Acknowledge) { return NULL; }
		CONFIRMATION(Prefix, Network, Request, Response) { }
		CONFIRMATION(Prefix, Network, Advice, Response) { }
		CONFIRMATION(Prefix, Network, Notification, Acknowledge) { }
		CONFIRMATION(Prefix, Network, Instruction, Acknowledge) { }

		INDICATION(Prefix, Reconciliation, Request, Response) { return NULL; }
		INDICATION(Prefix, Reconciliation, Advice, Response) { return NULL; }
		INDICATION(Prefix, Reconciliation, Notification, Acknowledge) { return NULL; }
		INDICATION(Prefix, Reconciliation, Instruction, Acknowledge) { return NULL; }
		CONFIRMATION(Prefix, Reconciliation, Request, Response) { }
		CONFIRMATION(Prefix, Reconciliation, Advice, Response) { }
		CONFIRMATION(Prefix, Reconciliation, Notification, Acknowledge) { }
		CONFIRMATION(Prefix, Reconciliation, Instruction, Acknowledge) { }

		INDICATION(Prefix, Reversal, Request, Response)  { return NULL; }
		INDICATION(Prefix, Reversal, Advice, Response) { return NULL; }
		INDICATION(Prefix, Reversal, Notification, Acknowledge) { return NULL; }
		INDICATION(Prefix, Reversal, Instruction, Acknowledge) { return NULL; }
		CONFIRMATION(Prefix, Reversal, Request, Response) { }
		CONFIRMATION(Prefix, Reversal, Advice, Response) { }
		CONFIRMATION(Prefix, Reversal, Notification, Acknowledge) { }
		CONFIRMATION(Prefix, Reversal, Instruction, Acknowledge) { }
	}
}
