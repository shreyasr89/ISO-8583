/*
 * POSDataCode.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef POSDATACODE_H_
#define POSDATACODE_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(POSDataCode, Numeric, 3, 22)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/Bytes.h"
ALPHADATAELEMENT(POSDataCode, Bytes, 16, 22)

#endif
/*
CB2A		22 Mode de lecture du système d'acceptation n 3
ISO8583		22 X POS data code b 16
*/

#endif
