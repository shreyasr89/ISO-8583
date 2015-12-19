/*
 * AuthorizingAgentInstitutionIdentificationCode.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef AUTHORIZINGAGENTINSTITUTIONIDENTIFICATIONCODE_H_
#define AUTHORIZINGAGENTINSTITUTIONIDENTIFICATIONCODE_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#include "ISO-8583/DTT/LLLAlphaNumericSpecial.h"
ALPHADATAELEMENT(AuthorizingAgentInstitutionIdentificationCode, LLLAlphaNumericSpecial, 255, 58)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 1993 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/LLNumeric.h"
NUMERICDATAELEMENT(AuthorizingAgentInstitutionIdentificationCode, LLNumeric, 11, 58)

#endif

/*
CB2A		58 Identif. de la machine ayant répondu LLLVAR ans …255
ISO8583		58 Authorizing agent institution identification code LLVAR n..11
*/
#endif
