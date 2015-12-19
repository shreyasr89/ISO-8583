/*
 * ICCSystemRelatedData.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef ICCSYSTEMRELATEDDATA_H_
#define ICCSYSTEMRELATEDDATA_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#include "ISO-8583/DTT/LLLBytes.h"
ALPHADATAELEMENT(ICCSystemRelatedData, LLLBytes, 255, 55)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/LLLLBytes.h"
ALPHADATAELEMENT(ICCSystemRelatedData, LLLLBytes, 9999, 55)

#endif

/*
CB2A		55 Données liées aux cartes à microcircuit LLLVAR b …255
ISO8583		55 X ICC system related data LLLLVAR b..9999
*/

#endif
