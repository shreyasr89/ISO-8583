/*
 * ForwardingInstitutionIdentificationCode.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef FORWARDINGINSTITUTIONIDENTIFICATIONCODE_H_
#define FORWARDINGINSTITUTIONIDENTIFICATIONCODE_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/LLNumeric.h"
NUMERICDATAELEMENT(ForwardingInstitutionIdentificationCode, LLNumeric, 11, 33)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/LLNumeric.h"
NUMERICDATAELEMENT(ForwardingInstitutionIdentificationCode, LLNumeric, 11, 33)

#endif
/*
CB2A				33 Ident. de l'organisme transmetteur LLVAR n …11
ISO-8583-1987		33 Forwarding institution identification code LLVAR n..11
ISO-8583-2003		33 Forwarding institution identification code LLVAR n..11
*/
#endif
