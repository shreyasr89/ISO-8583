/*
 * ApprovalCode.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef APPROVALCODE_H_
#define APPROVALCODE_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 1993 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/AlphaNumeric.h"
ALPHADATAELEMENT(ApprovalCode, AlphaNumeric, 6, 38)

#endif
/*
CB2A		38 Autorisation, réponse d'identification an 6
ISO8583		38 Approval code anp 6
*/

#endif
