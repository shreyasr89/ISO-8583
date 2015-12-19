/*
 * Message.h
 *
 *  Created on: 18 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_
#include <vector>
using std::vector;
#include <iostream>
using std::istream;
using std::ostream;
#include <sstream>
using std::istringstream;
using std::ostringstream;


#include "ISO-8583/MSG/ISO-8583-MSG.h"

#include "ISO-8583/DTT/Bitmaps.h"
#include "ISO-8583/DTT/BinaryInputStream.h"
#include "ISO-8583/DTT/BinaryOutputStream.h"
#include "ISO-8583/DTE/Bitmap.h"
#include "ISO-8583/DTE/DataElement.h"
#include "ISO-8583/MSG/MTI.h"

using ISO_8583::DTT::BinaryInputStream;
using ISO_8583::DTT::BinaryOutputStream;
using ISO_8583::DTE::Bitmap;
using ISO_8583::DTE::DataElement;
using ISO_8583::MSG::MTI;
using ISO_8583::MSG::Version;
using ISO_8583::MSG::Function;
using ISO_8583::MSG::Origin;
using ISO_8583::MSG::Class;

namespace ISO_8583 {
	namespace MSG {
		class Factory;

		class MSG_API_SCOPE Message : public MTI {
		private:
			Bitmaps		controls;

		protected:
			Bitmaps		bitmaps;

		public: //FIXME 
			vector<DataElement*>	fields;

		protected:
			Message();
			Message(Class klass, Function function, Origin starter);
		public:
			virtual ~Message();


		private:
			void set(DataElement& element);

		public:
			void add(DataElement& element);
			void addAndSet(DataElement* element);

			virtual const Bitmaps& mandatory() const = 0;
			virtual const Bitmaps& optional() const = 0;

			virtual BinaryInputStream& decode(BinaryInputStream& is) = 0;
			virtual BinaryOutputStream& encode(BinaryOutputStream& os) const = 0;

			friend MSG_API_SCOPE BinaryInputStream& operator>>(BinaryInputStream& is, Message& m);
			friend MSG_API_SCOPE BinaryOutputStream& operator<<(BinaryOutputStream& os, const Message& m);

			virtual void dump(ostream& os) = 0;

			static DataElement* newDataElement(Bitmap bitno);


		};
	}
}

#endif
