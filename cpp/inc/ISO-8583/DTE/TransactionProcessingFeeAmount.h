/*
 * TransactionProcessingFeeAmount.h
 *
 *  Created on: 18 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef TRANSACTIONPROCESSINGFEEAMOUNT_H_
#define TRANSACTIONPROCESSINGFEEAMOUNT_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/AlphaNumeric.h"
NUMERICDATAELEMENT(TransactionProcessingFeeAmount, AlphaNumeric, 12, 102)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/LLAlphaNumericSpace.h"
NUMERICDATAELEMENT(TransactionProcessingFeeAmount, LLAlphaNumericSpace, 28, 102)

#endif

#endif
