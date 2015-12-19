/*
 * DataRecord.h
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef DATARECORD_H_
#define DATARECORD_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#include "ISO-8583/DTT/AlphaNumeric.h"
ALPHADATAELEMENT(DataRecord, AlphaNumeric, 12, 72)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 1993 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/LLLLBytes.h"
ALPHADATAELEMENT(DataRecord, LLLLBytes, 9999, 72)

#endif

/*
ISO8583		72 Data record LLLLVAR ansb..9999
*/

#endif
