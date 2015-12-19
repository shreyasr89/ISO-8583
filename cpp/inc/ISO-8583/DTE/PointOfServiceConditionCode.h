/*
 * PointOfServiceConditionCode.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef POINTOFSERVICECONDITIONCODE_H_
#define POINTOFSERVICECONDITIONCODE_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(PointOfServiceConditionCode, Numeric, 2, 25)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003 
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(PointOfServiceConditionCode, Numeric, 2, 25)

#endif

/*
CB2A				25 Conditions de la transaction au point de service n 2
ISO-8583-1987		25 Point of service condition code n 2
*/
#endif
