/*
 * AuthorizationIdentificationResponse.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef AUTHORIZATIONIDENTIFICATIONRESPONSE_H_
#define AUTHORIZATIONIDENTIFICATIONRESPONSE_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/AlphaNumeric.h"
NUMERICDATAELEMENT(AuthorizationIdentificationResponse, AlphaNumeric, 6, 38)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003 
#include "ISO-8583/DTT/AlphaNumeric.h"
NUMERICDATAELEMENT(AuthorizationIdentificationResponse, AlphaNumeric, 6, 38)

#endif

/*
CB2A				38 Longueur du numéro d’autorisation an 6
ISO-8583-1987		38 Autorisation identification response length an 6
*/

#endif
