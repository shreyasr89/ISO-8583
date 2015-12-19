/*
 * AdditionalResponseData.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef ADDITIONALRESPONSEDATA_H_
#define ADDITIONALRESPONSEDATA_H_

#include "ISO-8583/DTE/DataElement.h"
#if STD_CB2A == 150
#include "ISO-8583/DTT/LLAlphaNumericSpecial.h"
NUMERICDATAELEMENT(AdditionalResponseData, LLAlphaNumericSpecial, 25, 44)

#elif STD_ISO_8583 == 1987 
#include "ISO-8583/DTT/LLAlphaNumericSpecial.h"
NUMERICDATAELEMENT(AdditionalResponseData, LLAlphaNumericSpecial, 25, 44)

#elif STD_ISO_8583 == 1993 
#include "ISO-8583/DTT/LLAlphaNumericSpecial.h"
NUMERICDATAELEMENT(AdditionalResponseData, LLAlphaNumericSpecial, 99, 44)

#elif  STD_ISO_8583 == 2003
#include "ISO-8583/DTT/LLLLAlphaNumericSpecial.h"
NUMERICDATAELEMENT(AdditionalResponseData, LLLLAlphaNumericSpecial, 9999, 44)

#endif


/*
CB2A		150		44 Données complémentaires réponse LLVAR ans …25
ISO-8583	1987	44 X Additional response data LLVAR ans …25
ISO-8583	1993	44 X Additional response data LLVAR ans …99
ISO-8583	2003	44 X Additional response data LLLLVAR ansb..9999
*/
#endif
