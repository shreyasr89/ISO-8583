/*
 * AdditionalAmounts.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef ADDITIONALAMOUNTS_H_
#define ADDITIONALAMOUNTS_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/LLLAlphaNumeric.h"
NUMERICDATAELEMENT(AdditionalAmounts, LLLAlphaNumeric, 120, 54)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993
#include "ISO-8583/DTT/LLLAlphaNumericSpecial.h"
NUMERICDATAELEMENT(AdditionalAmounts, LLLAlphaNumericSpecial, 120, 54)

#elif STD_ISO_8583 == 2003 
#include "ISO-8583/DTT/LLLAlphaNumericSpecial.h"
NUMERICDATAELEMENT(AdditionalAmounts, LLLAlphaNumericSpecial, 126, 54)
#endif
/*
CB2A		150		54 Montants supplémentaires LLLVAR an …120
ISO-8583	1987	54 X Amounts additional LLLVAR ans..120
ISO-8583	1993	54 X Amounts additional LLLVAR ans..120
ISO-8583	2003	54 X Amounts additional LLLVAR ans..126
*/

#endif
