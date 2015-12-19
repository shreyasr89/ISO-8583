/*
 * DateEffective.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef  DATEEFFECTIVE_H_
#define DATEEFFECTIVE_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(DateEffective, Numeric, 4, 13)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(DateEffective, Numeric, 6, 13)

#endif

/*
CB2A		13 Date locale de la transaction MMJJ n 4
ISO8583		13 Date effective CCYYMM n 6
*/
#endif
