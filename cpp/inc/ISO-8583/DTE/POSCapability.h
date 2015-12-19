/*
 * POSCapability.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef POSCAPABILITY_H_
#define POSCAPABILITY_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(POSCapability, Numeric, 1, 27)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/AlphaNumericBinary.h"
ALPHADATAELEMENT(POSCapability, AlphaNumericBinary, 27, 27)

#endif

/*
CB2A		27 Longueur du n° d’autorisation n 1
ISO8583		27 X POS capability anb 27
*/

#endif
