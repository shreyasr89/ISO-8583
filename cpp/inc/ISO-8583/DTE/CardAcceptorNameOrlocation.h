/*
 * CardAcceptorNameOrlocation.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef CARDACCEPTORNAMEORLOCATION_H_
#define CARDACCEPTORNAMEORLOCATION_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/AlphaNumericSpecial.h"
NUMERICDATAELEMENT(CardAcceptorNameOrlocation, AlphaNumericSpecial, 40, 43)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/AlphaNumericSpecial.h"
NUMERICDATAELEMENT(CardAcceptorNameOrlocation, AlphaNumericSpecial, 40, 43)

#elif STD_ISO_8583 == 2003
#include "ISO-8583/DTE/LLLLAlphaNumericSpecial.h"
NUMERICDATAELEMENT(CardAcceptorNameOrlocation, LLLLAlphaNumericSpecial, 9999, 43)

#endif

/*
CB2A				43 Nom et adresse de l'accepteur de carte ans 40
ISO-8583-1987		43 X Card acceptor name/location ans 40
ISO-8583-2003		43 X Card acceptor name/location LLLLVAR ansb..9999
*/

#endif
