/*
 * ForwardingInstitutionCountryCode.h
 *
 *  Created on: 17 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef COUNTRYCODEFORWARDINGINSTITUTION_H_
#define COUNTRYCODEFORWARDINGINSTITUTION_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(ForwardingInstitutionCountryCode, Numeric, 3, 21)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(ForwardingInstitutionCountryCode, Numeric, 3, 21)

#endif
/*
CB2A				21 cf norme ISO 8583 n 3
ISO-8583-1987		21 Country Code Forwarding institution n 3
ISO-8583-2003		21 Country Code Forwarding institution n 3
*/

#endif
