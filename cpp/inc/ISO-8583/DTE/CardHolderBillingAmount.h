/*
 * CardHolderBillingAmount.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef CARDHOLDERBILLINGAMOUNT_H_
#define CARDHOLDERBILLINGAMOUNT_H_

#include "ISO-8583/DTE/DataElement.h"
#include "ISO-8583/DTT/Numeric.h"

#if STD_CB2A == 150
NUMERICDATAELEMENT(CardHolderBillingAmount, Numeric, 12, 6)
#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
NUMERICDATAELEMENT(CardHolderBillingAmount, Numeric, 16, 6)
#endif

/*
CB2A-150			6 cf norme ISO 8583 n 12
ISO-8583-1987		6 X Amount cardholder billing n 16
ISO-8583-2003		6 X Amount cardholder billing n 16
*/

#endif
