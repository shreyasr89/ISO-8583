/*
 * SettlementDate.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef SETTLEMENTDATE_H_
#define SETTLEMENTDATE_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(SettlementDate, Numeric, 4, 15)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(SettlementDate, Numeric, 8, 15)

#endif

/*
CB2A				15 cf norme ISO 8583 n 4
ISO-8583-1987		15 Date settlement MMDD n 4
*/
#endif
