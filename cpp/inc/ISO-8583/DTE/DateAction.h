/*
 * DateAction.h
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef DATEACTION_H_
#define DATEACTION_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#include "AISO-8583/DTT/lphaNumeric.h"
ALPHADATAELEMENT(DateAction, AlphaNumeric, 12, 22)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/AlphaNumericSpace.h"
ALPHADATAELEMENT(DateAction, AlphaNumericSpace, 12, 22)

#endif


#endif
