/*
 * AmountsOriginalFees.h
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef AMOUNTSORIGINALFEES_H_
#define AMOUNTSORIGINALFEES_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#include "ISO-8583/DTT/AlphaNumeric.h"
ALPHADATAELEMENT(AmountsOriginalFees, AlphaNumeric,12, 66)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 1993 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/AlphaNumericSpace.h"
ALPHADATAELEMENT(AmountsOriginalFees, AlphaNumericSpace, 216, 66)

#endif

#endif
