/*
 * MTI.cpp
 *
 *  Created on: 18 mai 2015
 *      Author: FrancisANDRE
 */


#include "ISO-8583/MSG/MTI.h"

namespace ISO_8583 {
	namespace MSG {
#if STD_CB2A == 150
		MSG_API_SCOPE InputStream& operator>>(InputStream& is, MTI& mti) {
			is >>  mti.b0;
			is >>  mti.b1;
			return is;
		}
		MSG_API_SCOPE OutputStream& operator<<(OutputStream& os, const MTI& mti) {
			os << mti.b0;
			os << mti.b1;
			return os;
		}
#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
		MSG_API_SCOPE InputStream& operator>>(InputStream& is, MTI& mti) {
			byte b;
			is >> b; mti.mVersion = (Version)b;
			is >> b;mti.mClass = (Class)b;
			is >> b;mti.mFunction = (Function)b;
			is >> b;mti.mOrigin = (Origin)b;
			return is;
		}
		MSG_API_SCOPE OutputStream& operator<<(OutputStream& os, const MTI& mti) {
			os << (byte)mti.mVersion;
			os << (byte)mti.mClass;
			os << (byte)mti.mFunction;
			os << (byte)mti.mOrigin;
			return os;
		}
#endif
	}
}
