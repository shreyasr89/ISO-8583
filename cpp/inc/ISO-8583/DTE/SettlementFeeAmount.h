/*
 * SettlementFeeAmount.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef SETTLEMENTFEEAMOUNT_H_
#define SETTLEMENTFEEAMOUNT_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150 || STD_ISO_8583 == 1987 
#include "ISO-8583/DTT/SignedNumeric.h"
NUMERICDATAELEMENT(SettlementFeeAmount, SignedNumeric, 8, 29)

#endif

/*
CB2A-150			29 Settlement Fee Amout  x+n 8
ISO-8583-1987		29 Settlement Fee Amout  x+n 8
*/

#endif
