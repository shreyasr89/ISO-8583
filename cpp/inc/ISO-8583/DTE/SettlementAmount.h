/*
 * SettlementAmount.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef SETTLEMENTAMOUNT_H_
#define SETTLEMENTAMOUNT_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(SettlementAmount, Numeric, 12, 5)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(SettlementAmount, Numeric, 12, 5)

#elif STD_ISO_8583 == 2003

#endif

/*
CB2A-150			5 Montant de la transaction n 12
ISO-8583-1987		5 X Amount transaction n 12
ISO-8583-2003		5 see AmountReconciliation
*/

#endif
