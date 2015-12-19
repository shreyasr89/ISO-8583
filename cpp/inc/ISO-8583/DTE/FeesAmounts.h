/*
 * AmountsFees.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef AMOUNTSFEES_H_
#define AMOUNTSFEES_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#include "ISO-8583/DTT/LLLAlphaNumericSpecial.h"
ALPHADATAELEMENT(AmountsFees, LLLAlphaNumericSpecial, 255, 46)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/LLLAlphaNumericSpecial.h"
ALPHADATAELEMENT(AmountsFees, LLLAlphaNumericSpecial, 216, 46)

#endif

/*
CB2A		46 cf norme ISO 8583 LLLVAR ans …255
ISO8583		46 X Amounts fees LLLVAR ans..216
*/

#endif
