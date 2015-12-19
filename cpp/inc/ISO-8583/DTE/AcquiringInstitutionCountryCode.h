/*
 * AcquiringInstitutionCountryCode.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef ACQUIRINGINSTITUTIONCOUNTRYCODE_H_
#define ACQUIRINGINSTITUTIONCOUNTRYCODE_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(AcquiringInstitutionCountryCode, Numeric, 3, 19)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(AcquiringInstitutionCountryCode, Numeric, 3, 19)

#endif
/*
CB2A	150		19 Code pays de l'organisme acquéreur n 3
ISO8583	1987	19 Country code acquiring institution n 3
ISO8583	1993	19 Country code acquiring institution n 3
ISO8583	2003	19 Country code acquiring institution n 3
*/

#endif
