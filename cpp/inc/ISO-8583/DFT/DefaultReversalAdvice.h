/*
 * DefaultReversalAdvice.h
 *
 *  Created on: 10 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTREVERSALADVICE_H_
#define DEFAULTREVERSALADVICE_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"
#include "ISO-8583/MSG/ReversalAdvice.h"

namespace ISO_8583 {
	namespace MSG {
		CLASS_DEFINITION_QUESTION(CB2A, Reversal, Advice, Response)
	}
}

#endif
