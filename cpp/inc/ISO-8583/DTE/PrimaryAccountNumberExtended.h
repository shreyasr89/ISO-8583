/*
 * PrimaryAccountNumberExtended.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef PRIMARYACCOUNTNUMBEREXTENDED_H_
#define PRIMARYACCOUNTNUMBEREXTENDED_H_


#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150 || STD_ISO_8583 == 1987 
#include "ISO-8583/DTT/LLNumericSpecial.h"
NUMERICDATAELEMENT(PrimaryAccountNumberExtended, LLNumericSpecial, 28, 34)

#endif

/*
CB2A				34 Primary account number (PAN) LLVAR ns..28
ISO-8583-1987		34 Primary account number (PAN) LLVAR ns..28
*/

#endif
