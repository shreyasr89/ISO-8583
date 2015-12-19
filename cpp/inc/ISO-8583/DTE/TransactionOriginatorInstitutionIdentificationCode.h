/*
 * TransactionOriginatorInstitutionIdentificationCode.h
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef TRANSACTIONORIGINATORINSTITUTIONIDENTIFICATIONCODE_H_
#define TRANSACTIONORIGINATORINSTITUTIONIDENTIFICATIONCODE_H_

#include "DataElement.h"

#if VRM_CB2A == 150
#include "AlphaNumeric.h"
DATAELEMENT(TransactionOriginatorInstitutionIdentificationCode, AlphaNumeric, 12, 22)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 2003
#include "AlphaNumericSpace.h"
DATAELEMENT(TransactionOriginatorInstitutionIdentificationCode, AlphaNumericSpace, 12, 22)

#endif

#endif
