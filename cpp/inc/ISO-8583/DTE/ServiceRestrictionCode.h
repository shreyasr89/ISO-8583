/*
 * ServiceRestrictionCode.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef SERVICERESTRICTIONCODE_H_
#define SERVICERESTRICTIONCODE_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/AlphaNumeric.h"
NUMERICDATAELEMENT(ServiceRestrictionCode, AlphaNumeric, 3, 40)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/AlphaNumeric.h"
NUMERICDATAELEMENT(ServiceRestrictionCode, AlphaNumeric, 3, 40)

#endif

/*
CB2A				40 cf norme ISO 8583 an 3
ISO-8583-1987		40 Service Restriction code an 3
*/

#endif
