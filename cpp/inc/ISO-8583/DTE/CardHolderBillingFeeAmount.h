/*
 * CardHolderBillingFeeAmount.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef CARDHOLDERBILLINGFEEAMOUNT_H_
#define CARDHOLDERBILLINGFEEAMOUNT_H_

#include "ISO-8583/DTE/DataElement.h"
#include "ISO-8583/DTT/Numeric.h"

#if STD_CB2A == 150
NUMERICDATAELEMENT(CardHolderBillingFeeAmount, Numeric, 8, 8)
#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993
NUMERICDATAELEMENT(CardHolderBillingFeeAmount, Numeric, 8, 8)
#elif STD_ISO_8583 == 2003
NUMERICDATAELEMENT(CardHolderBillingFeeAmount, Numeric, 12, 8)
#endif

/*
CB2A-150			8 cf norme ISO 8583 n 8
ISO-8583-1987		8 X Amount cardholder billing fee n 8
ISO-8583-2003		8 X Amount cardholder billing fee n 12
*/

#endif
