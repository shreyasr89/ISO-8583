/*
 * BinaryTLV.cpp
 *
 *  Created on: 18 mai 2015
 *      Author: FrancisANDRE
 */

#include <iterator>
using namespace std;

#include "ISO-8583/DTE/BinaryTLV.h"

template<class T>
struct serialize
{
	serialize(const T & i_value) : value(i_value) {}
	T value;
};

template<class T>
ostream& operator <<(ostream &os, const serialize<T> & obj)
{
	os.write((char*)&obj.value, sizeof(T));
	return os;
}

namespace ISO_8583 {
	namespace DTE {
		DTE_API_SCOPE ostream& operator<<(ostream& os, const BinaryTLV& o) {
#if 0
#ifdef KEEP_THIS
			//		ostream_iterator<serialize<byte> > it(os);
			//		copy(o.begin(), o.end(), it); 
#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 2003
#endif // KEEP_THIS
			short bigendian = hton(o.T);
			os.write((char*)&bigendian, sizeof(bigendian));
			os.write((char*)&o.L, sizeof(o.L));
			for (int no = 0; no < o.L; no++) {
				os.write((char*)&o.V[no], sizeof(char));
			}
#endif
			return os;
		}
		DTE_API_SCOPE istream& operator>>(istream& is, BinaryTLV& o) {
			return is;
		}
	}
}