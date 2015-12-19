/*
 * CardholderBillingConversionRate.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef CARDHOLDERBILLINGCONVERSIONRATE_H_
#define CARDHOLDERBILLINGCONVERSIONRATE_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(CardHolderBillingConversionRate, Numeric, 8, 10)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(CardHolderBillingConversionRate, Numeric, 8, 10)

#endif

/*
CB2A-150			10 cf norme ISO 8583 n 8
ISO-8583-1987		10 Conversion rate cardholder billing n 8
ISO-8583-2003		10 Conversion rate cardholder billing n 8
*/

#endif
