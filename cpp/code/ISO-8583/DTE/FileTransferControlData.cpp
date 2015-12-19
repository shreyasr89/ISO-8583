/*
 * FileTransferControlData.cpp
 *
 *  Created on: 28 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/FileTransferControlData.h"

namespace ISO_8583 {
	namespace DTE {
		SERIALIZE(FileTransferControlData)
			string FileTransferControlData::toString() const {
			string s(str());
			return s;
		}
	}
}
