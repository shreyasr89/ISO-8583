/*
 * SettlementConversionRate.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef SETTLEMENTCONVERSIONRATE_H_
#define SETTLEMENTCONVERSIONRATE_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(SettlementConversionRate, Numeric, 8, 9)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(SettlementConversionRate, Numeric, 8, 9)

#endif

/*
CB2A-150			9 cf norme ISO 8583 n 8
ISO-8583-1987		9 Conversion rate reconciliation n 8
*/
#endif
