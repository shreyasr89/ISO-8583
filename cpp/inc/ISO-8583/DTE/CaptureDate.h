/*
 * CaptureDate.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef CAPTUREDATE_H_
#define CAPTUREDATE_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(CaptureDate, Numeric, 4, 17)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(CaptureDate, Numeric, 4, 17)

#endif
/*
CB2A				17 cf norme ISO 8583 n 4
ISO-8583-1987		17 Date capture MMDD n 4
ISO-8583-2003		17 Date capture MMDD n 4
*/
#endif
