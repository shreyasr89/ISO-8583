/*
 * ReconciliationFeeAmountsCredit.h
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef RECONCILIATIONFEEAMOUNTSCREDIT_H_
#define RECONCILIATIONFEEAMOUNTSCREDIT_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#include "ISO-8583/DTT/AlphaNumeric.h"
ALPHADATAELEMENT(ReconciliationFeeAmountsCredit, AlphaNumeric, 12, 22)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/AlphaNumericSpace.h"
ALPHADATAELEMENT(ReconciliationFeeAmountsCredit, AlphaNumericSpace, 12, 22)

#endif

#endif
