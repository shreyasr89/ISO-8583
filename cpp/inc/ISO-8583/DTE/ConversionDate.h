/*
 * ConversionDate.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef CONVERSIONDATE_H_
#define CONVERSIONDATE_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(ConversionDate, Numeric, 4, 16)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(ConversionDate, Numeric, 4, 16)

#endif
/*
CB2A				16 cf norme ISO 8583 n 4
ISO-8583-1987		16 Date conversion MMDD n 4
ISO-8583-2003		16 Date conversion MMDD n 4
*/
#endif
