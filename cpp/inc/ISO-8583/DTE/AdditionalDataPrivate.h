/*
 * AdditionalDataPrivate.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef ADDITIONALDATAPRIVATE_H_
#define ADDITIONALDATAPRIVATE_H_


#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/LLAlphaNumericSpecial.h"
NUMERICDATAELEMENT(AdditionalDataPrivate, LLAlphaNumericSpecial, 255, 48)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/LLLAlphaNumericSpecial.h"
NUMERICDATAELEMENT(AdditionalDataPrivate, LLLAlphaNumericSpecial, 999, 48)

#endif

/*
CB2A		150			48 cf norme ISO 8583 LLVAR ans …255
ISO-8583	1987		48 Additional data private LLLVAR ans..999
ISO-8583	1993		48 Additional data private LLLVAR ans..999
ISO-8583	2003		48 Additional data private LLLVAR ans..999
*/

#endif
