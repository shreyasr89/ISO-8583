/*
 * PINData.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef PINDATA_H_
#define PINDATA_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Bytes.h"
ALPHADATAELEMENT(PINData, Bytes, 8, 52)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/Bytes.h"
ALPHADATAELEMENT(PINData, Bytes, 8, 52)

#endif

/*
CB2A-150			52 cf norme ISO 8583 b 8
ISO-8583-1987		52 PIN data b 8
ISO-8583-2003		52 PIN data b 8
*/

#endif
