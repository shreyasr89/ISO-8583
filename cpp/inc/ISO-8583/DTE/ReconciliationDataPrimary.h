/*
 * ReconciliationDataPrimary.h
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef RECONCILIATIONDATAPRIMARY_H_
#define RECONCILIATIONDATAPRIMARY_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#include "ISO-8583/DTT/AlphaNumeric.h"
ALPHADATAELEMENT(ReconciliationDataPrimary, AlphaNumeric, 12, 2)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/AlphaNumericSpace.h"
ALPHADATAELEMENT(ReconciliationDataPrimary, AlphaNumericSpace, 12, 2)

#endif

#endif
