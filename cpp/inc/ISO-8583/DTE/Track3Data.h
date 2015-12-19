/*
 * Track3Data.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef TRACK3DATA_H_
#define TRACK3DATA_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/LLLBytes.h"
ALPHADATAELEMENT(Track3Data, LLLBytes, 104, 36)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/LLLBytes.h"
ALPHADATAELEMENT(Track3Data, LLLBytes, 104, 36)

#endif

/*
CB2A				36 cf norme ISO 8583 LLLVAR z …104
ISO-8583-1987		36 Track 3 data LLLVAR z..104
ISO-8583-2003		36 Track 3 data LLLVAR z..104
*/

#endif
