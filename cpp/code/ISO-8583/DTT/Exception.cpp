/*
 * Exception.cpp
 *
 *  Created on: 22 juin 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTT/Exception.h"

namespace ISO_8583 {
	namespace DTT {
		Exception::Exception(const char* message) _NOEXCEPT : invalid_argument(message) {
		}
		Exception::Exception(const char* message, int line) _NOEXCEPT : invalid_argument(message) {
		}
		Exception::Exception(const char* message, char b) _NOEXCEPT : invalid_argument(message), invalidByte(b) {
		}
		Exception::Exception(const char* message, char b, int line) _NOEXCEPT : invalid_argument(message), invalidByte(b) {
		}
		Exception::~Exception() _NOEXCEPT {
		}

		string Exception::offendingByte() const { return "0x" + char_to_hex(invalidByte); }
		char Exception::offendingChar() const { return invalidByte; }

		const char* Exception::what() const _NOEXCEPT {
			if (message.empty()) {
				message = BaseType::what();
				message += ": ";
				message += offendingByte();
				if (invalidString.size() > 0) {
					message += ", value=";
					message += string_to_hex(invalidString);
				}
			}
			return message.c_str();
		}
	}
}
