/*
 * Platform.h
 *
 *  Created on: 15 juil. 2015
 *      Author: FrancisANDRE
 */

#ifndef PLATFORM_H_
#define PLATFORM_H_



//
// Platform Identification
//
#define OS_FREE_BSD      0x0001
#define OS_AIX           0x0002
#define OS_HPUX          0x0003
#define OS_TRU64         0x0004
#define OS_LINUX         0x0005
#define OS_MAC_OS_X      0x0006
#define OS_NET_BSD       0x0007
#define OS_OPEN_BSD      0x0008
#define OS_IRIX          0x0009
#define OS_SOLARIS       0x000a
#define OS_QNX           0x000b
#define OS_VXWORKS       0x000c
#define OS_CYGWIN        0x000d
#define OS_UNKNOWN_UNIX  0x00ff
#define OS_WINDOWS_NT    0x1001
#define OS_WINDOWS_CE    0x1011
#define OS_VMS           0x2001


#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
	#define OS_FAMILY_UNIX 1
	#define OS_FAMILY_BSD 1
	#define OS OS_FREE_BSD
#elif defined(_AIX) || defined(__TOS_AIX__)
	#define OS_FAMILY_UNIX 1
	#define OS OS_AIX
#elif defined(hpux) || defined(_hpux) || defined(__hpux)
	#define OS_FAMILY_UNIX 1
	#define OS OS_HPUX
#elif defined(__digital__) || defined(__osf__)
	#define OS_FAMILY_UNIX 1
	#define OS OS_TRU64
#elif defined(linux) || defined(__linux) || defined(__linux__) || defined(__TOS_LINUX__) || defined(EMSCRIPTEN)
	#define OS_FAMILY_UNIX 1
	#define OS OS_LINUX
#elif defined(__APPLE__) || defined(__TOS_MACOS__)
	#define OS_FAMILY_UNIX 1
	#define OS_FAMILY_BSD 1
	#define OS OS_MAC_OS_X
#elif defined(__NetBSD__)
	#define OS_FAMILY_UNIX 1
	#define OS_FAMILY_BSD 1
	#define OS OS_NET_BSD
#elif defined(__OpenBSD__)
	#define OS_FAMILY_UNIX 1
	#define OS_FAMILY_BSD 1
	#define OS OS_OPEN_BSD
#elif defined(sgi) || defined(__sgi)
	#define OS_FAMILY_UNIX 1
	#define OS OS_IRIX
#elif defined(sun) || defined(__sun)
	#define OS_FAMILY_UNIX 1
	#define OS OS_SOLARIS
#elif defined(__QNX__)
	#define OS_FAMILY_UNIX 1
	#define OS OS_QNX
#elif defined(__CYGWIN__)
	#define OS_FAMILY_UNIX 1
	#define OS OS_CYGWIN
#elif defined(VXWORKS)
  #define OS_FAMILY_UNIX 1
  #define OS OS_VXWORKS
#elif defined(unix) || defined(__unix) || defined(__unix__)
	#define OS_FAMILY_UNIX 1
	#define OS OS_UNKNOWN_UNIX
#elif defined(_WIN32_WCE)
	#define OS_FAMILY_WINDOWS 1
	#define OS OS_WINDOWS_CE
#elif defined(_WIN32) || defined(_WIN64)
	#define OS_FAMILY_WINDOWS 1
	#define OS OS_WINDOWS_NT
#elif defined(__VMS)
	#define OS_FAMILY_VMS 1
	#define OS OS_VMS
#endif


#if !defined(OS)
	#error "Unknown Platform."
#endif


#ifndef OS_FAMILY_UNIX
	#define GCC_DIAG_OFF(x)
	#define GCC_DIAG_ON(x)
#endif

//
// Hardware Architecture and Byte Order
//
#define ARCH_ALPHA   0x01
#define ARCH_IA32    0x02
#define ARCH_IA64    0x03
#define ARCH_MIPS    0x04
#define ARCH_HPPA    0x05
#define ARCH_PPC     0x06
#define ARCH_POWER   0x07
#define ARCH_SPARC   0x08
#define ARCH_AMD64   0x09
#define ARCH_ARM     0x0a
#define ARCH_M68K    0x0b
#define ARCH_S390    0x0c
#define ARCH_SH      0x0d
#define ARCH_NIOS2   0x0e
#define ARCH_AARCH64 0x0f


#if defined(__ALPHA) || defined(__alpha) || defined(__alpha__) || defined(_M_ALPHA)
	#define ARCH ARCH_ALPHA
	#define ARCH_LITTLE_ENDIAN 1
#elif defined(i386) || defined(__i386) || defined(__i386__) || defined(_M_IX86) || defined(EMSCRIPTEN)
	#define ARCH ARCH_IA32
	#define ARCH_LITTLE_ENDIAN 1
#elif defined(_IA64) || defined(__IA64__) || defined(__ia64__) || defined(__ia64) || defined(_M_IA64)
	#define ARCH ARCH_IA64
	#if defined(hpux) || defined(_hpux)
		#define ARCH_BIG_ENDIAN 1
	#else
		#define ARCH_LITTLE_ENDIAN 1
	#endif
#elif defined(__x86_64__) || defined(_M_X64)
	#define ARCH ARCH_AMD64
	#define ARCH_LITTLE_ENDIAN 1
#elif defined(__mips__) || defined(__mips) || defined(__MIPS__) || defined(_M_MRX000)
	#define ARCH ARCH_MIPS
	#if defined(OS_FAMILY_WINDOWS)
		// Is this OK? Supports windows only little endian??
		#define ARCH_LITTLE_ENDIAN 1
	#elif defined(__MIPSEB__) || defined(_MIPSEB) || defined(__MIPSEB)
		#define ARCH_BIG_ENDIAN 1
	#elif defined(__MIPSEL__) || defined(_MIPSEL) || defined(__MIPSEL)
		#define ARCH_LITTLE_ENDIAN 1
	#else
		#error "MIPS but neither MIPSEL nor MIPSEB?"
	#endif

#elif defined(__hppa) || defined(__hppa__)
	#define ARCH ARCH_HPPA
	#define ARCH_BIG_ENDIAN 1
#elif defined(__PPC) || defined(__POWERPC__) || defined(__powerpc) || defined(__PPC__) || \
      defined(__powerpc__) || defined(__ppc__) || defined(__ppc) || defined(_ARCH_PPC) || defined(_M_PPC)
	#define ARCH ARCH_PPC
	#define ARCH_BIG_ENDIAN 1
#elif defined(_POWER) || defined(_ARCH_PWR) || defined(_ARCH_PWR2) || defined(_ARCH_PWR3) || \
      defined(_ARCH_PWR4) || defined(__THW_RS6000)
	#define ARCH ARCH_POWER
	#define ARCH_BIG_ENDIAN 1
#elif defined(__sparc__) || defined(__sparc) || defined(sparc)
	#define ARCH ARCH_SPARC
	#define ARCH_BIG_ENDIAN 1
#elif defined(__arm__) || defined(__arm) || defined(ARM) || defined(_ARM_) || defined(__ARM__) || defined(_M_ARM)
	#define ARCH ARCH_ARM
	#if defined(__ARMEB__)
		#define ARCH_BIG_ENDIAN 1
	#else
		#define ARCH_LITTLE_ENDIAN 1
	#endif
#elif defined(__arm64__) || defined(__arm64)
	#define ARCH ARCH_ARM64
	#if defined(__ARMEB__)
		#define ARCH_BIG_ENDIAN 1
	#elif defined(__BYTE_ORDER__) && defined(__ORDER_BIG_ENDIAN__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
		#define ARCH_BIG_ENDIAN 1
	#else
		#define ARCH_LITTLE_ENDIAN 1
	#endif
#elif defined(__m68k__)
	#define ARCH ARCH_M68K
	#define ARCH_BIG_ENDIAN 1
#elif defined(__s390__)
	#define ARCH ARCH_S390
	#define ARCH_BIG_ENDIAN 1
#elif defined(__sh__) || defined(__sh) || defined(SHx) || defined(_SHX_)
	#define ARCH ARCH_SH
	#if defined(__LITTLE_ENDIAN__) || (OS == OS_WINDOWS_CE)
		#define ARCH_LITTLE_ENDIAN 1
	#else
		#define ARCH_BIG_ENDIAN 1
	#endif
#elif defined (nios2) || defined(__nios2) || defined(__nios2__)
	#define ARCH ARCH_NIOS2
	#if defined(__nios2_little_endian) || defined(nios2_little_endian) || defined(__nios2_little_endian__)
		#define ARCH_LITTLE_ENDIAN 1
	#else
		#define ARCH_BIG_ENDIAN 1
	#endif
#elif defined(__AARCH64EL__)
	#define ARCH ARCH_AARCH64
	#define ARCH_LITTLE_ENDIAN 1
#elif defined(__AARCH64EB__)
	#define ARCH ARCH_AARCH64
	#define ARCH_BIG_ENDIAN 1
#endif


#if defined(_MSC_VER)
	#define COMPILER_MSVC
#elif defined(__clang__)
	#define COMPILER_CLANG
#elif defined (__GNUC__)
	#define COMPILER_GCC
#elif defined (__MINGW32__) || defined (__MINGW64__)
	#define COMPILER_MINGW
#elif defined (__INTEL_COMPILER) || defined(__ICC) || defined(__ECC) || defined(__ICL)
	#define COMPILER_INTEL
#elif defined (__SUNPRO_CC)
	#define COMPILER_SUN
#elif defined (__MWERKS__) || defined(__CWCC__)
	#define COMPILER_CODEWARRIOR
#elif defined (__sgi) || defined(sgi)
	#define COMPILER_SGI
#elif defined (__HP_aCC)
	#define COMPILER_HP_ACC
#elif defined (__BORLANDC__) || defined(__CODEGEARC__)
	#define COMPILER_CBUILDER
#elif defined (__DMC__)
	#define COMPILER_DMARS
#elif defined (__HP_aCC)
	#define COMPILER_HP_ACC
#elif (defined (__xlc__) || defined (__xlC__)) && defined(__IBMCPP__)
	#define COMPILER_IBM_XLC // IBM XL C++
#elif defined (__IBMCPP__) && defined(__COMPILER_VER__)
	#define COMPILER_IBM_XLC_ZOS // IBM z/OS C++
#endif


#if !defined(ARCH)
	#error "Unknown Hardware Architecture."
#endif


#if defined(OS_FAMILY_WINDOWS)
	#define DEFAULT_NEWLINE_CHARS "\r\n"
#else
	#define DEFAULT_NEWLINE_CHARS "\n"
#endif

enum class StreamByteOrder
{
	NATIVE_BYTE_ORDER        = 1,  /// the host's native byte-order
	BIG_ENDIAN_BYTE_ORDER    = 2,  /// big-endian (network) byte-order
	NETWORK_BYTE_ORDER       = 2,  /// big-endian (network) byte-order
	LITTLE_ENDIAN_BYTE_ORDER = 3,  /// little-endian byte-order
	UNSPECIFIED_BYTE_ORDER   = 4   /// unknown, byte-order will be determined by reading the byte-order mark
};


#endif
