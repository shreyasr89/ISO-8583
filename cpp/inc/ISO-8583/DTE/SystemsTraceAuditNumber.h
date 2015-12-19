/*
 * SystemsTraceAuditNumber.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef SYSTEMSTRACEAUDITNUMBER_H_
#define SYSTEMSTRACEAUDITNUMBER_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(SystemsTraceAuditNumber, Numeric, 6, 11)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(SystemsTraceAuditNumber, Numeric, 6, 11)

#elif STD_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(SystemsTraceAuditNumber, Numeric, 12, 11)

#endif

/*
CB2A				11 Numéro d'audit				n 6
ISO-8583-1987		11 Systems trace audit number	n 6
ISO-8583-2003		11 Systems trace audit number	n 12
*/

#endif
