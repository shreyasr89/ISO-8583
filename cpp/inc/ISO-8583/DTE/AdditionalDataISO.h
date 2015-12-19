/*
 * AdditionalDataISO.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef ADDITIONALDATAISO_H_
#define ADDITIONALDATAISO_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/LLAlphaNumericSpecial.h"
NUMERICDATAELEMENT(AdditionalDataISO, LLAlphaNumericSpecial, 255, 46)

#elif STD_ISO_8583 == 1987 
#include "ISO-8583/DTT/LLLAlphaNumericSpecial.h"
NUMERICDATAELEMENT(AdditionalDataISO, LLLAlphaNumericSpecial, 999, 46)

#else
#error "invalid data element"
#endif

/*
CB2A		150			46 cf norme ISO 8583 LLVAR ans …255
ISO-8583	1987		46 Track 1 data LLLVAR ans..999
*/

#endif
