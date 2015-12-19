/*
 * TransactionProcessingFeeAmout.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef TRANSACTIONPROCESSINGFEEAMOUT_H_
#define TRANSACTIONPROCESSINGFEEAMOUT_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150 || STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/SignedNumeric.h"
NUMERICDATAELEMENT(TransactionProcessingFeeAmout, SignedNumeric, 8, 30)
                   
#endif

/*
CB2A-150			30 Transaction Processing Fee Amout  x+n 8
ISO-8583-1987		30 Transaction Processing Fee Amout  x+n 8
*/

#endif
