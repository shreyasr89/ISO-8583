/*
 * Track2Data.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef TRACK2DATA_H_
#define TRACK2DATA_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/LLBytes.h"
ALPHADATAELEMENT(Track2Data, LLBytes, 37, 35)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/LLBytes.h"
ALPHADATAELEMENT(Track2Data, LLBytes, 37, 35)

#endif

/*
CB2A				35 Piste ISO 2 LLVAR z …37
ISO-8583-1987		35 Track 2 data LLVAR z..37
ISO-8583-2003		35 Track 2 data LLVAR z..37
*/

#endif
