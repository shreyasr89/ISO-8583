/*
 * ReconciliationFeeAmountsDebit.h
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef RECONCILIATIONFEEAMOUNTSDEBIT_H_
#define RECONCILIATIONFEEAMOUNTSDEBIT_H_

#include "DataElement.h"

#if VRM_CB2A == 150
#include "AlphaNumeric.h"
DATAELEMENT(ReconciliationFeeAmountsDebit, AlphaNumeric, 12, 22)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 2003
#include "AlphaNumericSpace.h"
DATAELEMENT(ReconciliationFeeAmountsDebit, AlphaNumericSpace, 12, 22)

#endif

#endif
