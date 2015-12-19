// ISO-8583-1.cpp : définit les fonctions exportées pour l'application DLL.
//

#include <string>
using namespace std;

#include "ISO-8583/DTT/ISO-8583-DTT.h"

const string at(const char* file, int line) {
	return string("at ") + string(file) + string(", line ") + std::to_string(line); 
}

static const char* const lut = "0123456789ABCDEF";

DTT_API_SCOPE string char_to_hex(char input) {
    string output;
    output.push_back(lut[input >> 4]);
    output.push_back(lut[input & 0x0F]);
	return output;
}
DTT_API_SCOPE string char_to_hex(unsigned char input) {
    string output;
    output.push_back(lut[input >> 4]);
    output.push_back(lut[input & 0x0F]);
	return output;
}
DTT_API_SCOPE string short_to_hex(short input) {
    string output;
	union {
		short	bigendian;
		char	bytes[sizeof(short)];
	};
	bigendian = hton(input);
    output.push_back(lut[bytes[0] >> 4]);
    output.push_back(lut[bytes[0] & 0x0F]);
    output.push_back(lut[bytes[1] >> 4]);
    output.push_back(lut[bytes[1] & 0x0F]);
	return output;
}
DTT_API_SCOPE string short_to_hex(unsigned short input) {
    string output;
	union {
		unsigned short	bigendian;
		char			bytes[sizeof(short)];
	};
 	bigendian = hton(input);
    output.push_back(lut[bytes[0] >> 4]);
    output.push_back(lut[bytes[0] & 0x0F]);
    output.push_back(lut[bytes[1] >> 4]);
    output.push_back(lut[bytes[1] & 0x0F]);
	return output;
}
DTT_API_SCOPE string string_to_hex(const string& input)
{
    size_t len = input.length();

    string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 0x0F]);
    }
    return output;
}
#include <algorithm>
#include <stdexcept>

DTT_API_SCOPE string hex_to_string(const string& input)
{
    size_t len = input.length();
    if (len & 1) throw invalid_argument("odd length");

    string output;
    output.reserve(len / 2);
    for (size_t i = 0; i < len; i += 2)
    {
        char a = input[i];
        const char* p = lower_bound(lut, lut + 16, a);
        if (*p != a) throw invalid_argument("not a hex digit");

        char b = input[i + 1];
        const char* q = lower_bound(lut, lut + 16, b);
        if (*q != b) throw invalid_argument("not a hex digit");

        output.push_back(((p - lut) << 4) | (q - lut));
    }
    return output;
}
#if __BYTE_ORDER == __BIG_ENDIAN
// No translation needed for big endian system
#else
// Swap 2 byte, 16 bit values:
DTT_API_SCOPE int2 hton(int2 val) {
	return (((val) >> 8) & 0x00FF) | (((val) << 8) & 0xFF00);
}

// Swap 4 byte, 32 bit values:
DTT_API_SCOPE int4 hton(int4 val) {
	return
		(((val) >> 24) & 0x000000FF) |
		(((val) >> 8) & 0x0000FF00)  |
		(((val) << 8) & 0x00FF0000)  |
		(((val) << 24) & 0xFF000000);
}


// Swap 8 byte, 64 bit values:
DTT_API_SCOPE int8 hton(int8 val) {
	return
		(((val) >> 56) & 0x00000000000000FF) | (((val) >> 40) & 0x000000000000FF00) |
		(((val) >> 24) & 0x0000000000FF0000) | (((val) >> 8 ) & 0x00000000FF000000) |
		(((val) << 8 ) & 0x000000FF00000000) | (((val) << 24) & 0x0000FF0000000000) |
		(((val) << 40) & 0x00FF000000000000) | (((val) << 56) & 0xFF00000000000000);
}


DTT_API_SCOPE int2 ntoh(int2 val) {
	return ((((val) >> 8) & 0x00FF) | (((val) << 8) & 0xFF00));
}

// Swap 4 byte, 32 bit values:
DTT_API_SCOPE int4 ntoh(int4 val)  {
	return 
		(((val) >> 24)  & 0x000000FF) | (((val) >> 8)  & 0x0000FF00) | \
		(((val) << 8)   & 0x00FF0000) | (((val) << 24) & 0xFF000000);
}
// Swap 8 byte, 64 bit values:
DTT_API_SCOPE int8 ntoh(int8 val) {
	return 
		(((val) >> 56) & 0x00000000000000FF) | (((val) >> 40) & 0x000000000000FF00) | \
		(((val) >> 24) & 0x0000000000FF0000) | (((val) >> 8)  & 0x00000000FF000000) | \
		(((val) << 8)  & 0x000000FF00000000) | (((val) << 24) & 0x0000FF0000000000) | \
		(((val) << 40) & 0x00FF000000000000) | (((val) << 56) & 0xFF00000000000000);
}

DTT_API_SCOPE nat2		hton(nat2 val)	{ return hton((int2)val); }
DTT_API_SCOPE nat4		hton(nat4 val)	{ return hton((int4)val); }
DTT_API_SCOPE nat8		hton(nat8 val)	{ return hton((int8)val); }

DTT_API_SCOPE nat2		ntoh(nat2 val)	{ return hton((nat2)val); }
DTT_API_SCOPE nat4		ntoh(nat4 val)	{ return hton((nat4)val); }
DTT_API_SCOPE nat8		ntoh(nat8 val)	{ return hton((nat8)val); }

#endif
