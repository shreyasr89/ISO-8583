/*
 * AccountIdentification1.h
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef ACCOUNTIDENTIFICATION1_H_
#define ACCOUNTIDENTIFICATION1_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/AlphaNumeric.h"
NUMERICDATAELEMENT(AccountIdentification1, AlphaNumeric, 12, 102)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/LLAlphaNumericSpace.h"
NUMERICDATAELEMENT(AccountIdentification1, LLAlphaNumericSpace, 28, 102)

#endif

/*
CB2A	150		102 Account identification 1 an 12
ISO8583	1987	102 Account identification 1 LLVAR ans..28
ISO8583	1993	102 Account identification 1 LLVAR ans..28
ISO8583	2003	102 Account identification 1 LLVAR ans..28
*/

#endif
