/*
 * BinaryTLVs.h
 *
 *  Created on: 1 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef BINARYTLVS_H_
#define BINARYTLVS_H_
#include <iostream>
using  std::istream;
using  std::ostream;
#include <string>
using  std::string;
#include <vector>
using std::vector;

#include "ISO-8583/DTE/ISO-8583-DTE.h"
#include "ISO-8583/DTE/BinaryTLV.h"

namespace ISO_8583 {
	namespace DTE {

		class DTE_API_SCOPE BinaryTLVs : public vector < BinaryTLV* > {
		public:
			BinaryTLVs() {
			}
			~BinaryTLVs() {
				for (int no = 0; no < size(); no++) {
					delete this->at(no);
				}
			}
			friend DTE_API_SCOPE ostream& operator<<(ostream& os, const BinaryTLVs& btlvs);
			friend DTE_API_SCOPE istream& operator>>(istream& is, BinaryTLVs& btlvs);
		};
	}
}

#endif
