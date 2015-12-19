/*
 * TransmissionDateAndTime.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/TransmissionDateAndTime.h"

namespace ISO_8583 {
	namespace DTE {
		// MMDDhhmmss
		TransmissionDateAndTime::TransmissionDateAndTime() {
			Numeric<2>*	MM = (Numeric<2>*)(static_cast<Numeric<10>*>(this));
			Numeric<2>*	DD = (Numeric<2>*)(MM + 1);
			Numeric<2>*	hh = (Numeric<2>*)(DD + 1);
			Numeric<2>*	mm = (Numeric<2>*)(hh + 1);
			Numeric<2>*	ss = (Numeric<2>*)(mm + 1);

			*MM = "05";
			*DD = "14";
			*hh = "08";
			*mm = "14";
			*ss = "45";
		}
		TransmissionDateAndTime::~TransmissionDateAndTime() {
		}
		SERIALIZE(TransmissionDateAndTime)
			string TransmissionDateAndTime::toString() const {
			string s(str());
			return s;
		}
	}
}