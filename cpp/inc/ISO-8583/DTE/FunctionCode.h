/*
 * FunctionCode.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef FUNCTIONCODE_H_
#define FUNCTIONCODE_H_

#include "ISO-8583/DTE/DataElement.h"
#include "ISO-8583/DTT/Numeric.h"

/*
CB2A		24 cf norme ISO 8583 n 3
ISO8583		24 Function code n 3
*/
NUMERICDATAELEMENT(FunctionCode, Numeric, 3, 24)

#endif
