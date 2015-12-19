/*
 * MessageReasonCode.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef MESSAGEREASONCODE_H_
#define MESSAGEREASONCODE_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150 || VRM_ISO_8583 == 1987
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(MessageReasonCode, Numeric, 2, 25)

#elif VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(MessageReasonCode, Numeric, 4, 25)

#endif

/*
CB2A		25 Conditions de la transaction n 2
ISO8583		25 Message reason code n 4
*/

#endif
