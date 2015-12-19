/*
 * Constructed.h
 *
 *  Created on: 3 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef CONSTRUCTED_H_
#define CONSTRUCTED_H_

#include "ISO-8583/DTE/ISO-8583-DTE.h"

namespace ISO_8583 {
	namespace DTE {

		class DTE_API_SCOPE Constructed {
		public:
			virtual ~Constructed() {}
			virtual void marshall() = 0;
			virtual void unmarshall() = 0;
		};
	}
}

#endif
