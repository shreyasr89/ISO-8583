/*
 * VerificationData.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef VERIFICATIONDATA_H_
#define VERIFICATIONDATA_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(VerificationData, Numeric, 3, 49)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/LLLLAlphaNumericSpecial.h"
ALPHADATAELEMENT(VerificationData, LLLLAlphaNumericSpecial, 9999, 49)

#endif

/*
CB2A		49 Code monnaie de la transaction n 3
ISO8583		49 X Verification data LLLLVAR ans..9999
*/

#endif
