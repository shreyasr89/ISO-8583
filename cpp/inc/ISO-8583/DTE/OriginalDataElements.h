/*
 * OriginalDataElements.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef ORIGINALDATAELEMENTS_H_
#define ORIGINALDATAELEMENTS_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(OriginalDataElements, Numeric, 2, 56)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/LLNumeric.h"
NUMERICDATAELEMENT(OriginalDataElements, LLNumeric, 41, 56)

#endif

/*
CB2A-150			56 cf norme ISO 8583 n 2
ISO-8583-1987		56 X Original data elements LLVAR n..41
ISO-8583-2003		56 X Original data elements LLVAR n..41
*/
#endif
