/*
 * CardAcceptorTerminalIdentification.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef CARDACCEPTORTERMINALIDENTIFICATION_H_
#define CARDACCEPTORTERMINALIDENTIFICATION_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/AlphaNumericSpecial.h"
NUMERICDATAELEMENT(CardAcceptorTerminalIdentification, AlphaNumericSpecial, 8, 41)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993
#include "ISO-8583/DTT/AlphaNumericSpecial.h"
NUMERICDATAELEMENT(CardAcceptorTerminalIdentification, AlphaNumericSpecial, 8, 41)

#elif STD_ISO_8583 == 2003
#include "ISO-8583/DTT/AlphaNumericSpecial.h"
NUMERICDATAELEMENT(CardAcceptorTerminalIdentification, AlphaNumericSpecial, 16, 41)

#endif

/*
CB2A				41 Identification du système d'acceptation ans 8
ISO-8583-1987		41 Card acceptor terminal identification ans 8
ISO-8583-2003		41 Card acceptor terminal identification ans 16
*/

#endif
