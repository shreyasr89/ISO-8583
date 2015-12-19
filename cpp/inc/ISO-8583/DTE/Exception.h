/*
 * Exception.h
 *
 *  Created on: 22 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef DTE_EXCEPTION_H_
#define DTE_EXCEPTION_H_

#include <stdexcept>
#include "ISO-8583/DTE/ISO-8583-DTE.h"

namespace ISO_8583 {
namespace DTE {

class Exception  : public std::exception {
public:
	Exception() _NOEXCEPT {
	}
	~Exception() _NOEXCEPT {
	}
};

}
}

#endif
