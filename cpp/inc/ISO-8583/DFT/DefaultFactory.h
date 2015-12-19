/*
 * DefaultFactory.h
 *
 *  Created on: 4 août 2015
 *      Author: FrancisANDRE
 */

#ifndef DEFAULTFACTORY_H_
#define DEFAULTFACTORY_H_

#include "ISO-8583/DFT/ISO-8583-DFT.h"

namespace ISO_8583 {
	namespace MSG {

		class ISO_8583_DFT_API DefaultFactory {
		public:
			DefaultFactory();
			virtual ~DefaultFactory();
		};
	}
}

#endif
