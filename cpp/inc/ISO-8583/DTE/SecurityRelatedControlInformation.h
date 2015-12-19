/*
 * SecurityRelatedControlInformation.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef SECURITYRELATEDCONTROLINFORMATION_H_
#define SECURITYRELATEDCONTROLINFORMATION_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
ALPHADATAELEMENT(SecurityRelatedControlInformation, Numeric, 16, 53)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/LLBytes.h"
ALPHADATAELEMENT(SecurityRelatedControlInformation, LLBytes, 48, 53)

#endif

/*
CB2A		53 Informations liées à la sécurité n 16
ISO8583		53 Security related control information LLVAR b..48
*/
#endif
