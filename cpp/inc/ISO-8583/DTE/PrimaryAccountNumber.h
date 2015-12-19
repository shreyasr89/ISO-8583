/*
 * PrimaryAccountNumber.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef PRIMARYACCOUNTNUMBER_H_
#define PRIMARYACCOUNTNUMBER_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/LLNumeric.h"
NUMERICDATAELEMENT(PrimaryAccountNumber, LLNumeric, 19, 2)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/LLNumeric.h"
NUMERICDATAELEMENT(PrimaryAccountNumber, LLNumeric, 19, 2)

#endif

/*
CB2A				2 Numéro de porteur LLVAR n …19
ISO-8583-1987		2 Primary account number (PAN) LLVAR n..19
ISO-8583-2003		2 Primary account number (PAN) LLVAR n..19
*/

#endif
