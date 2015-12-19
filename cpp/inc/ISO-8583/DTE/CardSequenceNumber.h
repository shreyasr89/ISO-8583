/*
 * CardSequenceNumber.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef CARDSEQUENCENUMBER_H_
#define CARDSEQUENCENUMBER_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(CardSequenceNumber, Numeric, 3, 23)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(CardSequenceNumber, Numeric, 3, 23)

#endif

/*
CB2A				23 Numéro séquentiel de la carte n 3
ISO-8583-1987		23 Card sequence number n 3
ISO-8583-2003		23 Card sequence number n 3
*/

#endif
