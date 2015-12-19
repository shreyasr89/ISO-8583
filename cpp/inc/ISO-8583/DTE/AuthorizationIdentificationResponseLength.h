/*
 * AuthorizationIdentificationResponseLength.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef AUTORISATIONIDENTIFICATIONRESPONSELENGTH_H_
#define AUTORISATIONIDENTIFICATIONRESPONSELENGTH_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150 || STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(AuthorizationIdentificationResponseLength, Numeric, 1, 27)

#endif

/*
CB2A				27 Longueur du numéro d’autorisation n 1
ISO-8583-1987		27 Autorisation identification response length n 1
*/

#endif
