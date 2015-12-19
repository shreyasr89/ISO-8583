/*
 * MerchantCategoryCode.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef MERCHANTCATEGORYCODE_H_
#define MERCHANTCATEGORYCODE_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150 || VRM_ISO_8583 == 1987
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(MerchantCategoryCode, Numeric, 2, 26)

#elif VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(MerchantCategoryCode, Numeric, 4, 26)

#endif

/*
CB2A		26 Longueur du code confidentiel n 2
ISO8583		26 Merchant category code n 4
*/
#endif
