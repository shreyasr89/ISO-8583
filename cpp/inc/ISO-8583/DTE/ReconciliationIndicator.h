/*
 * ReconciliationIndicator.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef RECONCILIATIONINDICATOR_H_
#define RECONCILIATIONINDICATOR_H_

#include "DataElement.h"

#if VRM_CB2A == 150
#include "SignedPacked.h"
DATAELEMENT(ReconciliationIndicator, SignedPacked, 8, 29)

#elif VRM_ISO_8583 == 2003
#include "Numeric.h"
DATAELEMENT(ReconciliationIndicator, Numeric, 3, 29)

#endif

/*
CB2A		29 cf norme ISO 8583 x+n 8
ISO8582		29 Reconciliation indicator n 3
*/

#endif
