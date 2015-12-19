/*
 * DataElement.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef DATAELEMENT_H_
#define DATAELEMENT_H_

#include <string>
using std::string;

#include "ISO-8583/DTE/ISO-8583-DTE.h"

#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"
using ISO_8583::DTT::InputStream;
using ISO_8583::DTT::OutputStream;

namespace ISO_8583 {
	namespace DTE {
		class DTE_API_SCOPE	DataElement {
		public:
			virtual ~DataElement() {}
			virtual int bitno() const = 0;
			virtual void decode(InputStream& is) = 0;
			virtual void encode(OutputStream& os) = 0;
			virtual string toString() const = 0;
		};
	}
}
#endif
