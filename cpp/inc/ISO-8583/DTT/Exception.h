/*
 * Exception.h
 *
 *  Created on: 22 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef DTT_EXCEPTION_H_
#define DTT_EXCEPTION_H_

#include <stdexcept>
#include <string>
using  std::invalid_argument;
using  std::string;

#include "ISO-8583-DTT.h"

namespace ISO_8583 {
	namespace DTT {

		class Exception : public invalid_argument {
		private:
			typedef invalid_argument BaseType;

		protected:
			char invalidByte = 0;
			string invalidString;
			mutable string message;

		public:
			Exception(const char* message) _NOEXCEPT;
			Exception(const char* message, int line) _NOEXCEPT;
			Exception(const char* message, char b)_NOEXCEPT ;
			Exception(const char* message, char b, int line) _NOEXCEPT;
			~Exception() _NOEXCEPT;

			string offendingByte() const;
			char offendingChar() const;

			const char* what() const _NOEXCEPT;
		};

		class IsA {
		public:
			virtual bool operator()(byte c) = 0;
		};

		class NotA : public Exception {
		protected:
			NotA(const char* message) _NOEXCEPT : Exception(message) {}
		public:
			virtual ~NotA() _NOEXCEPT {}
			virtual void operator()(byte b) = 0;
			virtual void operator()(char b) = 0;
			virtual void operator()(char b, const char* value) = 0;
		};
	}
}

#endif
