/*
 * MerchantType.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef MERCHANTTYPE_H_
#define MERCHANTTYPE_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(MerchantType, Numeric, 4, 18)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(MerchantType, Numeric, 4, 18)

#endif

/*
CB2A			18 Code activité de l'accepteur (Merchant’s type) n 4
ISO-8583-1987	18 Merchant’s type n 4
*/

#endif
