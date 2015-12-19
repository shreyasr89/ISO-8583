#include <cassert>
#include <memory>
#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "ISO-8583/DTT/Bytes.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"

namespace ISO_8583 {
	namespace DTT {
		bool IsAByte::operator()(byte b) { return true; }

		void NotAByte::operator()(byte b) { throw invalid_argument("not a Byte"); }
		void NotAByte::operator()(char b) { throw invalid_argument("not a Byte"); }
		void NotAByte::operator()(char b, const char* value) { throw invalid_argument("not a Byte"); }


		IsAByte isAByte;
		NotAByte notAByte;

		template<int sizeb, byte init, Justification justified, Encoding encoding>
		int	Bytes<sizeb, init, justified, encoding>::fill(nat8 value) {
			return fill(to_string(value).c_str());
		}

		template<int sizeb, byte init, Justification justified, Encoding encoding>
		int	Bytes<sizeb, init, justified, encoding>::fill(const string& value) {
			return fill(value.c_str());
		}
		template<int sizeb, byte init, Justification justified, Encoding encoding>
		int	Bytes<sizeb, init, justified, encoding>::fill(const char* value) {
			clear();
			size_t length = 0;
			if (value) {
				if (strlen(value) > sizeof(bytes))
					throw overflow_error(string("Bytes: overflow: ") + value);

				length = min(sizeof(bytes), strlen(value));
				size_t no, len;
				if (justified == Justification::left) {
					for (no = 1, len = 1; no <= sizeof(bytes) && len <= length; no++, len++) {
						bytes[no - 1] = value[len - 1];
					}
					//				memcpy((char*)bytes, value, len);
				}
				else
					if (justified == Justification::right) {
					for (no = sizeof(bytes), len = length; no >= 1 && len >= 1; no--, len--) {
						bytes[no - 1] = value[len - 1];
					}
					}
			}
			return length;
		}

		template<int sizeb, byte init, Justification justified, Encoding encoding>
		int	Bytes<sizeb, init, justified, encoding>::fill(IsA* isa, NotA* nota, nat8 value) {
			stringstream ss; ss.width(sizeb); ss.fill('0');
			ss << value;
			return fill(isa, nota, ss.str());
		}

		template<int sizeb, byte init, Justification justified, Encoding encoding>
		int	Bytes<sizeb, init, justified, encoding>::fill(IsA* isa, NotA* nota, const string& value) {
			return fill(isa, nota, value.c_str());
		}

		template<int sizeb, byte init, Justification justified, Encoding encoding>
		int	Bytes<sizeb, init, justified, encoding>::fill(IsA* isa, NotA* nota, const char* value) {
			clear();
			size_t length = 0;
			if (value) {
				if (strlen(value) > sizeof(bytes))
					throw overflow_error(string("Bytes: overflow: ") + value);

				length = min(sizeof(bytes), strlen(value));
				size_t no, len;
				if (justified == Justification::left) {
					for (no = 1, len = 1; no <= sizeof(bytes) && len <= length; no++, len++) {
						const char c = value[len - 1];
						if ((*isa)(c))
							bytes[no - 1] = c;
						else
							(*nota)(c, value);
					}
				}
				else
					if (justified == Justification::right) {
					for (no = sizeof(bytes), len = length; no >= 1 && len >= 1; no--, len--) {
						bytes[no - 1] = value[len - 1];
					}
					}
			}
			return length;
		}

		template<int sizeb, byte init, Justification justified, Encoding encoding>
		InputStream& Bytes<sizeb, init, justified, encoding>::fill(IsA* isa, NotA* nota, InputStream& is, size_t length) {
			if (length > sizeof(bytes))
				throw overflow_error(string("Bytes: overflow: ") + to_string(length));

			char buffer[sizeof(bytes) + 1];
			size_t no;
			for (no = 0; no < length; no++) {
				is >> buffer[no];
			}
			buffer[no] = 0;
			fill(isa, nota, buffer);
			return is;
		}

		template<int sizeb, byte init, Justification justified, Encoding encoding>
		bool Bytes<sizeb, init, justified, encoding>::operator==(const char* value) const {
			if (value) {
				size_t len = min(sizeof(bytes), strlen(value));
				if (justified == Justification::left)
					return strncmp((const char*)bytes, value, len) == 0;
				else
					if (justified == Justification::right) {
					assert(false);
					//FIXME TODO
					}
			}
			return false;
		}

		template<int sizeb, byte init, Justification justified, Encoding encoding>
		bool Bytes<sizeb, init, justified, encoding>::operator==(const string& value) const {
			if (!value.empty()) {
				size_t len = min(sizeof(bytes), value.size());
				if (justified == Justification::left)
					return strncmp((const char*)bytes, value.data(), len) == 0;
				else
					if (justified == Justification::right) {
					assert(false);
					//FIXME TODO
					}
			}
			return false;
		}

		template<int sizeb, byte init, Justification justified, Encoding encoding>
		bool Bytes<sizeb, init, justified, encoding>::operator==(const Bytes& value) const {
			return memcmp(bytes, value.bytes, sizeb) == 0;
		}

		template<int sizeb, byte init, Justification justified, Encoding encoding>
		string Bytes<sizeb, init, justified, encoding>::str() const {
			string value;
			value = string((const char*)bytes, sizeof(bytes));
			return value;
		}

		template<int sizeb, byte init, Justification justified, Encoding encoding>
		const byte&	Bytes<sizeb, init, justified, encoding>::operator[](int no) const	{
			if (0 <= no && no < sizeb)
				return bytes[no];
			else
				throw out_of_range(to_string(no) + " out of 0.." + to_string(sizeb));
		}

		template<int size>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, Bytes<size, ' ', Justification::left, Encoding::ASCII>& bs) {
			if (false) {
				bs.fill((nat8)0);
				bs.fill((const char*)NULL);
				bs.fill(string(""));
				bs.fill(NULL, NULL, (nat8)0);
				bs.fill(NULL, NULL, string(""));
				bs.fill(NULL, NULL, (const char*)NULL);
				bs.fill(NULL, NULL, is);
			}
			bs.clear();
			for (int no = 0; no < sizeof(bs.bytes); no++) {
				is >> bs.bytes[no];
			}
			return is;
		}
		template<int size>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Bytes<size, ' ', Justification::left, Encoding::ASCII>& bs) {
			for (int no = 0; no < sizeof(bs.bytes); no++) {
				os << bs.bytes[no];
			}
			return os;
		}
		template<int size>
		DTT_API_SCOPE InputStream& operator>>(InputStream& is, Bytes<size, '0', Justification::right, Encoding::ASCII>& bs) {
			if (false) {
				bs.fill((nat8)0);
				bs.fill((const char*)NULL);
				bs.fill(string(""));
				bs.fill(NULL, NULL, (nat8)0);
				bs.fill(NULL, NULL, string(""));
				bs.fill(NULL, NULL, (const char*)NULL);
				bs.fill(NULL, NULL, is);
			}
			bs.clear();
			for (int no = 0; no < sizeof(bs.bytes); no++) {
				is >> bs.bytes[no];
			}
			return is;
		}
		template<int size>
		DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Bytes<size, '0', Justification::right, Encoding::ASCII>& bs) {
			for (int no = 0; no < sizeof(bs.bytes); no++) {
				os << bs.bytes[no];
			}
			return os;
		}



#define NUMREADER(type, stream, size)	template DTT_API_SCOPE stream& operator>> <size>(stream& is, type<size, '0', Justification::right, Encoding::ASCII >& a);
#define NUMWRITER(type, stream, size)	template DTT_API_SCOPE stream& operator<< <size>(stream& os, const type<size, '0', Justification::right, Encoding::ASCII >& a);
#define NUMINOUT(type, size)  NUMREADER(type, InputStream, size); NUMWRITER(type, OutputStream, size)

		NUMINOUT(Bytes, 1);
		NUMINOUT(Bytes, 2);
		NUMINOUT(Bytes, 3);
		NUMINOUT(Bytes, 4);
		NUMINOUT(Bytes, 5);
		NUMINOUT(Bytes, 6);
		NUMINOUT(Bytes, 7);
		NUMINOUT(Bytes, 8);
		NUMINOUT(Bytes, 9);
		NUMINOUT(Bytes, 10);
		NUMINOUT(Bytes, 11);
		NUMINOUT(Bytes, 12);
		NUMINOUT(Bytes, 13);
		NUMINOUT(Bytes, 14);
		NUMINOUT(Bytes, 15);
		NUMINOUT(Bytes, 16);
		NUMINOUT(Bytes, 17);
		NUMINOUT(Bytes, 18);
		NUMINOUT(Bytes, 19);
		NUMINOUT(Bytes, 23);
		NUMINOUT(Bytes, 28);
		NUMINOUT(Bytes, 32);
		NUMINOUT(Bytes, 41);

		INOUT(Bytes, 1);
		INOUT(Bytes, 2);
		INOUT(Bytes, 3);
		INOUT(Bytes, 4);
		INOUT(Bytes, 5);
		INOUT(Bytes, 6);
		INOUT(Bytes, 7);
		INOUT(Bytes, 8);
		INOUT(Bytes, 9);
		INOUT(Bytes, 10);
		INOUT(Bytes, 11);
		INOUT(Bytes, 12);
		INOUT(Bytes, 13);
		INOUT(Bytes, 14);
		INOUT(Bytes, 15);
		INOUT(Bytes, 16);
		INOUT(Bytes, 17);
		INOUT(Bytes, 18);
		INOUT(Bytes, 19);

		INOUT(Bytes, 20);
		INOUT(Bytes, 22);
		INOUT(Bytes, 23);
		INOUT(Bytes, 24);
		INOUT(Bytes, 25);
		INOUT(Bytes, 27);
		INOUT(Bytes, 28);

		INOUT(Bytes, 32);
		INOUT(Bytes, 35);
		INOUT(Bytes, 37);

		INOUT(Bytes, 40);
		INOUT(Bytes, 41);
		INOUT(Bytes, 48);

		INOUT(Bytes, 76);
		INOUT(Bytes, 99);

		INOUT(Bytes, 104);
		INOUT(Bytes, 120);
		INOUT(Bytes, 124);
		INOUT(Bytes, 126);
		INOUT(Bytes, 140);

		INOUT(Bytes, 216);
		INOUT(Bytes, 255);
		INOUT(Bytes, 256);
		INOUT(Bytes, 999);
		INOUT(Bytes, 9999);

		template class Bytes < 1 > ;
		template class Bytes < 2 > ;
		template class Bytes < 3 > ;
		template class Bytes < 4 > ;
		template class Bytes < 5 > ;
		template class Bytes < 6 > ;
		template class Bytes < 7 > ;
		template class Bytes < 8 > ;
		template class Bytes < 9 > ;

		template class Bytes < 10 > ;
		template class Bytes < 11 > ;
		template class Bytes < 12 > ;
		template class Bytes < 13 > ;
		template class Bytes < 14 > ;
		template class Bytes < 15 > ;
		template class Bytes < 16 > ;
		template class Bytes < 17 > ;
		template class Bytes < 18 > ;
		template class Bytes < 19 > ;

		template class Bytes < 20 > ;
		template class Bytes < 22 > ;
		template class Bytes < 23 > ;
		template class Bytes < 24 > ;
		template class Bytes < 25 > ;
		template class Bytes < 27 > ;
		template class Bytes < 28 > ;

		template class Bytes < 32 > ;
		template class Bytes < 35 > ;
		template class Bytes < 37 > ;

		template class Bytes < 40 > ;
		template class Bytes < 41 > ;
		template class Bytes < 48 > ;

		template class Bytes < 76 > ;
		template class Bytes < 99 > ;

		template class Bytes < 104 > ;
		template class Bytes < 120 > ;
		template class Bytes < 124 > ;
		template class Bytes < 126 > ;
		template class Bytes < 140 > ;

		template class Bytes < 216 > ;
		template class Bytes < 255 > ;
		template class Bytes < 256 > ;
		template class Bytes < 999 > ;
		template class Bytes < 9999 > ;

		template class Bytes < 1, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 2, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 3, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 4, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 5, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 6, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 7, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 8, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 9, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 10, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 11, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 12, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 13, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 14, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 15, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 16, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 17, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 18, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 19, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 23, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 28, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 32, '0', Justification::right, Encoding::ASCII > ;
		template class Bytes < 41, '0', Justification::right, Encoding::ASCII > ;

	}
}

