/*
 * MACField.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef MACFIELD_H_
#define MACFIELD_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Bytes.h"
ALPHADATAELEMENT(MACField, Bytes, 8, 64)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/Bytes.h"
ALPHADATAELEMENT(MACField, Bytes, 4, 64)

#endif

/*
CB2A		64 cf norme ISO 8583 b 8
ISO8583		64 or 128 MAC field b 4
*/

#endif
