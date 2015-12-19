/*
 * Track1Data.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef TRACK1DATA_H_
#define TRACK1DATA_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/AlphaNumericSpecial.h"
NUMERICDATAELEMENT(Track1Data, AlphaNumericSpecial, 76, 45)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/AlphaNumericSpecial.h"
NUMERICDATAELEMENT(Track1Data, AlphaNumericSpecial, 76, 45)

#endif

/*
CB2A				45 cf norme ISO 8583 LLVAR ans …76
ISO-8583-1987		45 Track 1 data LLVAR ans..76
ISO-8583-2003		45 Track 1 data LLVAR ans..76
*/
#endif
