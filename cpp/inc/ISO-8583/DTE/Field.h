/*
 * Field.h
 *
 *  Created on: 1 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef FIELD_H_
#define FIELD_H_

#include <cassert>
#include "ISO-8583/DTE/ISO-8583-DTE.h"

namespace ISO_8583 {
	namespace DTE {

#pragma pack(push, 1) // exact fit - no padding
		class DTE_API_SCOPE Field {
		public:
			Field() {
				//		assert(sizeof(Field) == 1);	// per C++ standard... 
			}
			virtual ~Field() {
			}
			virtual int fieldno() const = 0;
			virtual string str() const = 0;
		};
#pragma pack(pop) //back to whatever the previous packing mode was 
	}
}

#endif
