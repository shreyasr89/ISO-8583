/*
 * AcquirerReferenceNumber.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef ACQUIRERREFERENCENUMBER_H_
#define ACQUIRERREFERENCENUMBER_H_

#include "DataElement.h"
#if VRM_CB2A == 150
#include "ISO-8583/DTT/SignedNumeric.h"
NUMERICDATAELEMENT(AcquirerReferenceNumber, SignedNumeric, 8, 31)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(AcquirerReferenceNumber, Numeric, 23, 31)
#endif

/*
CB2A		150		31 cf norme ISO 8583			x+n 8
ISO-8583	1987	31 Acquirer reference number	n 23
*/

#endif
