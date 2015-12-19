#ifndef ISO8583DTT_H_
#define ISO8583DTT_H_

#include <cstddef>
#include <cstdint>
#include <string>
using std::string;


#if defined(_WIN32) && defined(_DLL)
	#if !defined(ISO_8583_DLL) && !defined(ISO_8583_STATIC)
		#define ISO_8583_DLL
	#endif
#endif

#if defined(_MSC_VER)
	#if defined(ISO_8583_DLL)
		#if defined(_DEBUG)
			#define ISO_8583_LIB_SUFFIX "d.lib"
		#else
			#define ISO_8583_LIB_SUFFIX ".lib"
		#endif
	#elif defined(_DLL)
		#if defined(_DEBUG)
			#define ISO_8583_LIB_SUFFIX "mdd.lib"
		#else
			#define ISO_8583_LIB_SUFFIX "md.lib"
		#endif
	#else
		#if defined(_DEBUG)
			#define ISO_8583_LIB_SUFFIX "mtd.lib"
		#else
			#define ISO_8583_LIB_SUFFIX "mt.lib"
		#endif
	#endif
#endif

#if (defined(_WIN32) || defined(_WIN32_WCE)) && defined(ISO_8583_DLL)
	#if defined(ISO_8583_DTT_EXPORTS)
		#define DTT_API_SCOPE __declspec(dllexport)
	#else
		#define DTT_API_SCOPE __declspec(dllimport)
	#endif
#endif


#if !defined(DTT_API_SCOPE)
	#if !defined(NO_GCC_API_ATTRIBUTE) && defined (__GNUC__) && (__GNUC__ >= 4)
		#define DTT_API_SCOPE __attribute__ ((visibility ("default")))
	#else
		#define DTT_API_SCOPE
	#endif
#endif

//
// Automatically link ISO-8583-DTT library.
//
#if defined(_MSC_VER)
	#if !defined(ISO_8583_NO_AUTOMATIC_LIBS) && !defined(ISO_8583_DTT_EXPORTS)
		#if	defined(STD_CB2A)
			#pragma comment(lib, "CB2A-DTT" ISO_8583_LIB_SUFFIX)
		#elif defined(STD_ISO_8583)
			#pragma comment(lib, "ISO-8583-DTT" ISO_8583_LIB_SUFFIX)
		#else
			#error "missing define"
		#endif
	#endif
#endif

#if defined(_MSC_VER)
#pragma warning(disable : 4251)
#endif


//
// Include platform-specific definitions
//
#include "Poco/Platform.h"
#if defined(_WIN32)
	#include "Poco/Platform_WIN32.h"
#elif defined(__VMS)
	#include "Poco/Platform_VMS.h"
#elif defined(POCO_VXWORKS)
	#include "Poco/Platform_VX.h"
#elif defined(POCO_OS_FAMILY_UNIX)
	#include "Poco/Platform_POSIX.h"
#endif

//
// Cleanup inconsistencies
//
#ifdef POCO_OS_FAMILY_WINDOWS
	#if defined(POCO_WIN32_UTF8) && defined(POCO_NO_WSTRING)
		#error POCO_WIN32_UTF8 and POCO_NO_WSTRING are mutually exclusive.
	#endif
#else
	#ifndef __cdecl
		#define __cdecl	
	#endif
	#ifdef POCO_WIN32_UTF8
		#undef POCO_WIN32_UTF8
	#endif
#endif

#ifndef _NOEXCEPT
	#define _NOEXCEPT noexcept
#endif


typedef unsigned char byte;
typedef bool		boolean;


#ifdef POCO_COMPILER_MSVC
	typedef int8_t		int1;
	typedef int16_t		int2;
	typedef int32_t		int4;
	typedef int64_t		int8;

	typedef uint8_t		nat1;
	typedef uint16_t	nat2;
	typedef uint32_t	nat4;
	typedef uint64_t	nat8;

	#if defined(_WIN64)
		#define PTR_IS_64_BIT 1
		typedef signed __int64     intptr;
		typedef unsigned __int64   uintptr;
	#else
		typedef signed long        intptr;
		typedef unsigned long      uintptr;
	#endif
	#define HAVE_INT64 1
#elif defined(__GNUC__) || defined(__clang__)
	//
	// Unix/GCC/Clang
	//
	typedef int8_t		int1;
	typedef int16_t		int2;
	typedef int32_t		int4;

	typedef uint8_t		nat1;
	typedef uint16_t	nat2;
	typedef uint32_t	nat4;
	#if defined(_WIN64)
		#define PTR_IS_64_BIT 1
		typedef signed long long   intptr;
		typedef unsigned long long natptr;
		typedef signed long long   int8;
		typedef unsigned long long nat8;
	#else
		typedef signed long        intptr;
		typedef unsigned long      natptr;
		#if defined(__LP64__)
			#define PTR_IS_64_BIT 1
			#define LONG_IS_64_BIT 1
			typedef signed long        int8;
			typedef unsigned long      nat8;
		#else
			typedef signed long long   int8;
			typedef unsigned long long nat8;
		#endif
	#endif
	#define HAVE_INT64 1
#elif defined(__DECCXX)
	//
	// Compaq C++
	//
	typedef int8_t		int1;
	typedef int16_t		int2;
	typedef int32_t		int4;
	typedef int64_t		int8;

	typedef uint8_t		nat1;
	typedef uint16_t	nat2;
	typedef uint32_t	nat4;
	typedef uint64_t	nat8;
	#if defined(__VMS)
		#if defined(__32BITS)
			typedef signed long    intptr;
			typedef unsigned long  natptr;
		#else
			typedef int8          intptr;
			typedef nat8         natptr;
			#define PTR_IS_64_BIT 1
		#endif
	#else
		typedef signed long        intptr;
		typedef unsigned long      natptr;
		#define PTR_IS_64_BIT 1
		#define LONG_IS_64_BIT 1
	#endif
	#define HAVE_INT64 1
#elif defined(POCO_COMPILER_HP_ACC)
	//
	// HP Ansi C++
	//
	typedef int8_t		int1;
	typedef int16_t		int2;
	typedef int32_t		int4;

	typedef uint8_t		nat1;
	typedef uint16_t	nat2;
	typedef uint32_t	nat4;
	typedef signed long            intptr;
	typedef unsigned long          natptr;
	#if defined(__LP64__)
		#define PTR_IS_64_BIT 1
		#define LONG_IS_64_BIT 1
		typedef signed long        int8;
		typedef unsigned long      nat8;
	#else
		typedef signed long long   int8;
		typedef unsigned long long nat8;
	#endif
	#define HAVE_INT64 1
#elif defined(POCO_COMPILER_SUN)
	//
	// SUN Forte C++
	//
	typedef signed char            Int8;
	typedef unsigned char          UInt8;
	typedef signed short           Int16;
	typedef unsigned short         UInt16;
	typedef signed int             Int32;
	typedef unsigned int           UInt32;
	typedef signed long            intptr;
	typedef unsigned long          natptr;
	#if defined(__sparcv9)
		#define PTR_IS_64_BIT 1
		#define LONG_IS_64_BIT 1
		typedef signed long        int8;
		typedef unsigned long      nat8;
	#else
		typedef signed long long   int8;
		typedef unsigned long long nat8;
	#endif
	#define HAVE_INT64 1
#elif defined(POCO_COMPILER_IBM_XLC) 
	//
	// IBM XL C++
	//
	typedef int8_t		int1;
	typedef int16_t		int2;
	typedef int32_t		int4;

	typedef uint8_t		nat1;
	typedef uint16_t	nat2;
	typedef uint32_t	nat4;
	typedef signed long            intptr;
	typedef unsigned long          natptr;
	#if defined(__64BIT__)
		#define PTR_IS_64_BIT 1
		#define LONG_IS_64_BIT 1
		typedef signed long        int8;
		typedef unsigned long      nat8;
	#else
		typedef signed long long   int8;
		typedef unsigned long long nat8;
	#endif
	#define HAVE_INT64 1
#elif defined(POCO_COMPILER_SGI) 
	//
	// MIPSpro C++
	//
	typedef int8_t		int1;
	typedef int16_t		int2;
	typedef int32_t		int4;

	typedef uint8_t		nat1;
	typedef uint16_t	nat2;
	typedef uint32_t	nat4;
	typedef signed long            intptr;
	typedef unsigned long          natptr;
	#if _MIPS_SZLONG == 64
		#define PTR_IS_64_BIT 1
		#define LONG_IS_64_BIT 1
		typedef signed long        int8;
		typedef unsigned long      nat8;
	#else
		typedef signed long long   int8;
		typedef unsigned long long nat8;
	#endif
	#define HAVE_INT64 1
#elif defined(_DIAB_TOOL)
	typedef int8_t		int1;
	typedef int16_t		int2;
	typedef int32_t		int4;
	typedef int64_t		int8;

	typedef uint8_t		nat1;
	typedef uint16_t	nat2;
	typedef uint32_t	nat4;
	typedef uint64_t	nat8;
	typedef signed long        intptr;
	typedef unsigned long      natptr;
	typedef signed long long   int8;
	typedef unsigned long long nat8;
	#define HAVE_INT64 1
#else
	#error "no compiler defined"
#endif

class Functor {
public:
	virtual void  operator()(const std::string& s) = 0;
};


namespace ISO_8583 {
	namespace DTT {
		class InputStream;
		class OutputStream;
	}
}

DTT_API_SCOPE string char_to_hex(char input);
DTT_API_SCOPE string char_to_hex(unsigned char input);
DTT_API_SCOPE string short_to_hex(short input);
DTT_API_SCOPE string short_to_hex(unsigned short input);
DTT_API_SCOPE string string_to_hex(const string& input);
DTT_API_SCOPE string hex_to_string(const string& input);
DTT_API_SCOPE const string at(const char* file, int line);

#include "ISO-8583/DTT/endian.h"

#if __BYTE_ORDER == __BIG_ENDIAN
// No translation needed for big endian system
#define				hton(val) val
#define				ntoh(val) val
#else
DTT_API_SCOPE int2		hton(int2 val);
DTT_API_SCOPE int4		hton(int4 val);
DTT_API_SCOPE int8		hton(int8 val);
DTT_API_SCOPE nat2		hton(nat2 val);
DTT_API_SCOPE nat4		hton(nat4 val);
DTT_API_SCOPE nat8		hton(nat8 val);

DTT_API_SCOPE int2		ntoh(int2 val);
DTT_API_SCOPE int4		ntoh(int4 val);
DTT_API_SCOPE int8		ntoh(int8 val);
DTT_API_SCOPE nat2		ntoh(nat2 val);
DTT_API_SCOPE nat4		ntoh(nat4 val);
DTT_API_SCOPE nat8		ntoh(nat8 val);
#endif

#define READER(type, stream, size)	template DTT_API_SCOPE stream& operator>> <size>(stream& is, type<size>& a);
#define WRITER(type, stream, size)	template DTT_API_SCOPE stream& operator<< <size>(stream& os, const type<size>& a);
#define INOUT(type, size)  READER(type, InputStream, size); WRITER(type, OutputStream, size)


#endif // !_ISO85831DTT_H_
