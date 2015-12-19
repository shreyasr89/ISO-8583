/*
 * TransactionAmount.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef TRANSACTIONAMOUNT_H_
#define TRANSACTIONAMOUNT_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(TransactionAmount, Numeric, 12, 4)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(TransactionAmount, Numeric, 12, 4)

#elif STD_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(TransactionAmount, Numeric, 16, 4)

#endif

/*
CB2A-150			4 Montant de la transaction n 12
ISO-8583-1987		4 X Amount transaction n 12
ISO-8583-2003		4 X Amount transaction n 16
*/
#endif
