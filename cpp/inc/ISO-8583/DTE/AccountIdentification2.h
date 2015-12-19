/*
 * AccountIdentification2.h
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef ACCOUNTIDENTIFICATION2_H_
#define ACCOUNTIDENTIFICATION2_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/AlphaNumeric.h"
NUMERICDATAELEMENT(AccountIdentification2, AlphaNumeric, 12, 103)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/LLAlphaNumericSpace.h"
NUMERICDATAELEMENT(AccountIdentification2, LLAlphaNumericSpace, 28, 103)

#endif

/*
CB2A	150		103 Account identification 2 an 12
ISO8583	1987	103 Account identification 2 LLVAR ans..28
ISO8583	1993	103 Account identification 2 LLVAR ans..28
ISO8583	2003	103 Account identification  LLVAR ans..28
*/

#endif
