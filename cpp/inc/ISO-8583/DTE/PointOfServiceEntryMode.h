/*
 * PointOfServiceEntryMode.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef POINTOFSERVICEENTRYMODE_H_
#define POINTOFSERVICEENTRYMODE_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(PointOfServiceEntryMode, Numeric, 3, 22)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(PointOfServiceEntryMode, Numeric, 3, 22)

#endif
/*
CB2A				22 Mode de lecture du système d'acceptation n 3
ISO-8583-1987		22 Point of service entry mode n 3
*/

#endif
