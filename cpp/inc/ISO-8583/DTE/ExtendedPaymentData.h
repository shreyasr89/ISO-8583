/*
 * ExtendedPaymentData.h
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef EXTENDEDPAYMENTDATA_H_
#define EXTENDEDPAYMENTDATA_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#include "ISO-8583/DTT/AlphaNumeric.h"
ALPHADATAELEMENT(ExtendedPaymentData, AlphaNumeric, 12, 22)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/AlphaNumericSpace.h"
ALPHADATAELEMENT(ExtendedPaymentData, AlphaNumericSpace, 12, 22)

#endif

/*
CB2A		1-5-0	22 Mode de lecture du système d'acceptation n 3
ISO8583
*/
#endif
