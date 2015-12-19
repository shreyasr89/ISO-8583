/*
 * Instruction.h
 *
 *  Created on: 23 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef Instruction_H_
#define Instruction_H_

#include "ISO-8583/MSG/ISO-8583-MSG.h"
#include "ISO-8583/MSG/Exception.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"
using ISO_8583::DTT::InputStream;
using ISO_8583::DTT::OutputStream;

namespace ISO_8583 {
	namespace MSG {
		class InstructionAcknowledge;

		class MSG_API_SCOPE Instruction : public virtual Exception {
		public:
			Instruction() {
			}
			virtual ~Instruction() {
			}
			virtual InstructionAcknowledge* indication(InputStream& is, OutputStream& os) = 0;
			virtual void dump(ostream& os) = 0;
		};
	}
}

#endif
