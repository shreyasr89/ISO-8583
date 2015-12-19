/*
 * ServiceCode.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef SERVICECODE_H_
#define SERVICECODE_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#include "ISO-8583/DTT/AlphaNumeric.h"
ALPHADATAELEMENT(ServiceCode, AlphaNumeric, 3, 40)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(ServiceCode, Numeric, 3, 40)

#endif

/*
CB2A			40 cf norme ISO 8583 an 3
ISO-8583-		40 Service code n 3
*/
#endif
