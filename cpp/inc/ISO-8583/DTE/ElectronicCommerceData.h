/*
 * ElectronicCommerceData.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef ELECTRONICCOMMERCEDATA_H_
#define ELECTRONICCOMMERCEDATA_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#include "ISO-8583/DTT/LLPackedSpecial.h"
ALPHADATAELEMENT(ElectronicCommerceData, LLPackedSpecial, 28, 34)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/LLLLBytes.h"
ALPHADATAELEMENT(ElectronicCommerceData, LLLLBytes, 9999, 34)

#endif

/*
CB2A		34 cf norme ISO 8583 LLVAR ns …28
ISO8583		34 X Electronic commerce data LLLLVAR b..9999
*/

#endif
