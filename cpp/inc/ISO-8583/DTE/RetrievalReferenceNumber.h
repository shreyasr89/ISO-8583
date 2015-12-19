/*
 * RetrievalReferenceNumber.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef RETRIEVALREFERENCENUMBER_H_
#define RETRIEVALREFERENCENUMBER_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/AlphaNumeric.h"
NUMERICDATAELEMENT(RetrievalReferenceNumber, AlphaNumeric, 12, 37)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993
#include "ISO-8583/DTT/AlphaNumeric.h"
NUMERICDATAELEMENT(RetrievalReferenceNumber, AlphaNumeric, 12, 37)

#elif STD_ISO_8583 == 2003
#include "ISO-8583/DTT/AlphaNumericSpace.h"
NUMERICDATAELEMENT(RetrievalReferenceNumber, AlphaNumericSpace, 12, 37)
#endif

/*
CB2A				37 Numéro de référence d'archivage an 12
ISO-8583-1987		37 Retrieval reference number an 12
ISO-8583-2003		37 Retrieval reference number anp 12
*/
#endif
