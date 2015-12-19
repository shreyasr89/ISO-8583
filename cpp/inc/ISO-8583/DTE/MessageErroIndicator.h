/*
 * MessageErroIndicator.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef  MESSAGEERROINDICATOR_H_
#define MESSAGEERROINDICATOR_H_

#include "ISO-8583/DTE/DataElement.h"

#if VRM_CB2A == 150
#include "ISO-8583/DTT/Numeric.h"
NUMERICDATAELEMENT(MessageErroIndicator, Numeric, 4, 18)

#elif VRM_ISO_8583 == 1987 || VRM_ISO_8583 == 2003
#include "ISO-8583/DTT/LLLBytes.h"
NUMERICDATAELEMENT(MessageErroIndicator, LLLBytes, 140, 18)

#endif
/*
CB2A	18 Code activité de l'accepteur n 4
ISO8583	18 X Message error indicator LLLVAR ansb..140
*/

#endif
