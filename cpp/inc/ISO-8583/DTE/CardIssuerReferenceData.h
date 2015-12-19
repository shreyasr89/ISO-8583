/*
 * CardIssuerReferenceData.h
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef CARDISSUERREFERENCEDATA_H_
#define CARDISSUERREFERENCEDATA_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/AlphaNumeric.h"
NUMERICDATAELEMENT(CardIssuerReferenceData, AlphaNumeric, 12, 95)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/LLAlphaNumericSpecial.h"
NUMERICDATAELEMENT(CardIssuerReferenceData, LLAlphaNumericSpecial, 99, 95)

#endif

/*
95		Card issuer reference data LLVAR ans..99
*/
#endif
