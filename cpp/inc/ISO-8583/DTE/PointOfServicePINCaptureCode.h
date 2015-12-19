/*
 * PointOfServicePINCaptureCode.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef POINTOFSERVICEPINCAPTURECODE_H_
#define POINTOFSERVICEPINCAPTURECODE_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150 
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(PointOfServicePINCaptureCode, Numeric, 2, 25)

#elif STD_ISO_8583 == 1987 
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(PointOfServicePINCaptureCode, Numeric, 2, 25)

#endif

/*
ISO-8583-1987		25 Point of service PIN capture code n 2
*/
#endif
