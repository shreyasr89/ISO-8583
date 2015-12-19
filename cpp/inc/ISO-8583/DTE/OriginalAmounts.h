/*
 * AmountsOriginal.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef AMOUNTSORIGINAL_H_
#define AMOUNTSORIGINAL_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#include "ISO-8583/DTT/SignedPacked.h"
NUMERICDATAELEMENT(AmountsOriginal, SignedPacked, 8, 30)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 1993 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(AmountsOriginal, Numeric, 32, 30)

#endif

/*
CB2A		30 cf norme ISO 8583 x+n 8
ISO8583		30 X Amounts original n 32
*/

#endif
