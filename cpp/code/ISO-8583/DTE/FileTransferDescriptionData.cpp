/*
 * FileTransferDescriptionData.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/FileTransferDescriptionData.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(FileTransferDescriptionData)
			string FileTransferDescriptionData::toString() const {
			string s(str());
			return s;
		}
	}
}
