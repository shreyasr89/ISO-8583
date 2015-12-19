/*
 * TransactionFeeAmount.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef TRANSACTIONFEEAMOUNT_H_
#define TRANSACTIONFEEAMOUNT_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150 || STD_ISO_8583 == 1987 
#include "ISO-8583/DTT/SignedNumeric.h"
NUMERICDATAELEMENT(TransactionFeeAmount, SignedNumeric, 8, 28)

#endif

/*
CB2A-150			28 Transaction Fee Amout  x+n 8
ISO-8583-1987		28 Transaction Fee Amout  x+n 8
*/

#endif
