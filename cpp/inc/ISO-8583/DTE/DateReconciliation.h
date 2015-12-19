/*
 * DateReconciliation.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef DATERECONCILIATION_H_
#define DATERECONCILIATION_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#include "ISO-8583/DTT/SignedNumeric.h"
NUMERICDATAELEMENT(DateReconciliation, SignedPacked, 8, 28)

#elif  VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 1993 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(DateReconciliation, Numeric, 8, 28)

#endif

/*
CB2A		28 cf norme ISO 8583 x+n 8
ISO8583		28 Date reconciliation CCYYMMDD n 8
*/
#endif
