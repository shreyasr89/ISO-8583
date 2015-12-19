/*
 * FileName.h
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef FILENAME_H_
#define FILENAME_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/AlphaNumeric.h"
NUMERICDATAELEMENT(FileName, AlphaNumeric, 12, 22)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/AlphaNumericSpace.h"
NUMERICDATAELEMENT(FileName, AlphaNumericSpace, 12, 22)

#endif


#endif
