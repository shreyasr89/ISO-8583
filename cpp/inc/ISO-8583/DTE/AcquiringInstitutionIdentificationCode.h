/*
 * AcquiringInstitutionIdentificationCode.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef ACQUIRINGINSTITUTIONIDENTIFICATIONCODE_H_
#define ACQUIRINGINSTITUTIONIDENTIFICATIONCODE_H_

#include "ISO-8583/DTE/DataElement.h"
#include "ISO-8583/DTT/LLNumeric.h"

NUMERICDATAELEMENT(AcquiringInstitutionIdentificationCode, LLNumeric, 11, 32)

/*
CB2A		150			32 Identification organisme acquéreur LLVAR n …11
ISO-8583	1987		32 Acquiring institution identification code LLVAR n..11
ISO-8583	1993		32 Acquiring institution identification code LLVAR n..11
ISO-8583	2003		32 Acquiring institution identification code LLVAR n..11
*/

#endif
