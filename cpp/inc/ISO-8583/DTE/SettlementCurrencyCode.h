/*
 * SettlementCurrencyCode.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef SETTLEMENTCURRENCYCODE_H_
#define SETTLEMENTCURRENCYCODE_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/AlphaNumeric.h"
NUMERICDATAELEMENT(SettlementCurrencyCode, AlphaNumeric, 12, 102)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/LLAlphaNumericSpace.h"
NUMERICDATAELEMENT(SettlementCurrencyCode, LLAlphaNumericSpace, 28, 102)

#endif

/*
ISO8583		102 Account identification 1 LLVAR ans..28
*/

#endif
