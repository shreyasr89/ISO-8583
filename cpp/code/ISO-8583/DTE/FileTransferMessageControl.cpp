/*
 * FileTransferMessageControl.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/FileTransferMessageControl.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(FileTransferMessageControl)
			string FileTransferMessageControl::toString() const {
			string s(str());
			return s;
		}
	}
}
