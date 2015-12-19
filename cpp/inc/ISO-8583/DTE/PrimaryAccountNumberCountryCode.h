/*
 * PrimaryAccountNumberCountryCode.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef COUNTRYCODEPRIMARYACCOUNTNUMBER_H_
#define COUNTRYCODEPRIMARYACCOUNTNUMBER_H_

#include "ISO-8583/DTE/DataElement.h"

#if STD_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(PrimaryAccountNumberCountryCode, Numeric, 3, 20)

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(PrimaryAccountNumberCountryCode, Numeric, 3, 20)

#endif
/*
CB2A				20 cf norme ISO 8583 n 3
ISO-8583-1987		20 Country code primary account number (PAN) n 3
ISO-8583-2003		20 Country code primary account number (PAN) n 3
*/

#endif
