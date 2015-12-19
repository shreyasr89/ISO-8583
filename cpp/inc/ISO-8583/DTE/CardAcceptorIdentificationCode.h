/*
 * CardAcceptorIdentificationCode.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef CARDACCEPTORIDENTIFICATIONCODE_H_
#define CARDACCEPTORIDENTIFICATIONCODE_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/AlphaNumericSpecial.h"
NUMERICDATAELEMENT(CardAcceptorIdentificationCode, AlphaNumericSpecial, 15, 42)

#elif STD_ISO_8583 == 1987  || STD_ISO_8583 == 1993
#include "ISO-8583/DTT/AlphaNumericSpecial.h"
NUMERICDATAELEMENT(CardAcceptorIdentificationCode, AlphaNumericSpecial, 15, 42)

#elif STD_ISO_8583 == 2003
#include "ISO-8583/DTT/LLAlphaNumericSpecial.h"
NUMERICDATAELEMENT(CardAcceptorIdentificationCode, LLAlphaNumericSpecial, 35, 42)

#endif

/*
CB2A				42 Identification de l'accepteur de carte ans 15
ISO-8583-1987		42 Card acceptor identification code ans 15
ISO-8583-2003		42 Card acceptor identification code LLVAR ans..35
*/
#endif
