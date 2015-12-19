/*
 * AuthorizationLifeCycleCode.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef AUTHORIZATIONLIFECYCLECODE_H_
#define AUTHORIZATIONLIFECYCLECODE_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#include "ISO-8583/DTT/LLLAlphaNumericSpecial.h"
ALPHADATAELEMENT(AuthorizationLifeCycleCode, LLLAlphaNumericSpecial, 255, 57)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 1993 | VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(AuthorizationLifeCycleCode, Numeric, 3, 57)

#endif

/*
CB2A		57 cf norme ISO 8583 LLLVAR ans …255
ISO8583		57 Authorization life cycle code n 3
*/
#endif
