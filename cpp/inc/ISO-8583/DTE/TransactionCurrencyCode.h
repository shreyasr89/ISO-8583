/*
 * TransactionCurrencyCode.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef TRANSACTIONCURRENCYCODE_H_
#define TRANSACTIONCURRENCYCODE_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(TransactionCurrencyCode, Numeric, 3, 49)

#elif STD_ISO_8583 == 1987 
#include "ISO-8583/DTT/AlphaNumeric.h"
NUMERICDATAELEMENT(TransactionCurrencyCode, AlphaNumeric, 3, 49)

#elif STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003 
#include "ISO-8583/DTT/AlphaNumeric.h"
NUMERICDATAELEMENT(TransactionCurrencyCode, AlphaNumeric, 3, 49)

#endif

/*
CB2A-150			49 Code monnaie de la transaction n 3
ISO-8583-1987		49 Transaction Currency Code a or n 3
*/

#endif
