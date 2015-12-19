/*
 * CardHolderBillingCurrencyCode.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef CARDHOLDERBILLINGCURRENCYCODE_H_
#define CARDHOLDERBILLINGCURRENCYCODE_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(CardHolderBillingCurrencyCode, Numeric, 3, 19)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(CardHolderBillingCurrencyCode, Numeric, 3, 19)

#endif
/*
*/

#endif
