/*
 * NetworkInternationalIdentifier.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef NETWORKINTERNATIONALIDENTIFIER_H_
#define NETWORKINTERNATIONALIDENTIFIER_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(NetworkInternationalIdentifier, Numeric, 3, 24)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003 
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(NetworkInternationalIdentifier, Numeric, 3, 24)

#endif

/*
CB2A				24  n 3
ISO-8583-1987		24 Network International Identifer n 3
*/


#endif
