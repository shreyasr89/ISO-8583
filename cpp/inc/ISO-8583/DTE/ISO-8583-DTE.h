#ifndef ISO_8583_DTE_H_
#define ISO_8583_DTE_H_

#include "ISO-8583/DTT/ISO-8583-DTT.h"

#if defined(_MSC_VER)
	//
	// Automatically link ISO-8583-DTE library.
	//
	#if !defined(ISO_8583_NO_AUTOMATIC_LIBS) && !defined(ISO_8583_DTE_EXPORTS)
		#if STD_CB2A==150
			#pragma comment(lib, "CB2A-DTE-1_5_0" ISO_8583_LIB_SUFFIX)
		#elif STD_ISO_8583==1987
			#pragma comment(lib, "ISO-8583-DTE-1987" ISO_8583_LIB_SUFFIX)
		#elif STD_ISO_8583==1993
			#pragma comment(lib, "ISO-8583-DTE-1993" ISO_8583_LIB_SUFFIX)
		#elif STD_ISO_8583==2003
			#pragma comment(lib, "ISO-8583-DTE-2003" ISO_8583_LIB_SUFFIX)
		#else
			#error "missing define"
		#endif
	#endif
#endif

#if (defined(_WIN32) || defined(_WIN32_WCE)) && defined(ISO_8583_DLL)
	#ifdef ISO_8583_DTE_EXPORTS
		#define DTE_API_SCOPE __declspec(dllexport)
	#else
		#define DTE_API_SCOPE __declspec(dllimport)
	#endif
#endif

#if !defined(DTE_API_SCOPE)
	#if !defined(_NO_GCC_API_ATTRIBUTE) && defined (__GNUC__) && (__GNUC__ >= 4)
		#define DTE_API_SCOPE __attribute__ ((visibility ("default")))
	#else
		#define DTE_API_SCOPE
	#endif
#endif

using namespace ISO_8583::DTT;


// ==========================================================================================
#define ALPHADATAELEMENT(dataelement, base, length, no) \
namespace ISO_8583 { \
	namespace DTE { \
		class DTE_API_SCOPE dataelement : \
			public base<length>, \
			public DataElement { \
		public: \
			typedef base<length> BaseType; \
			static const int  bitmapno = no; \
			 \
		public: \
			dataelement() {} \
			virtual ~dataelement() {} \
 \
			dataelement& operator=(const string& value) { \
				static_cast<BaseType&>(*this) = value; return *this; \
			} \
			dataelement& operator=(const char* value) { \
				static_cast<BaseType&>(*this) = value; return *this; \
			} \
			virtual int bitno() const { return bitmapno; } \
			virtual void decode(InputStream& is); \
			virtual void encode(OutputStream& os); \
			virtual string toString() const; \
		}; \
	} \
}
// ==========================================================================================

// ==========================================================================================
#define NUMERICDATAELEMENT(dataelement, base, length, no) \
namespace ISO_8583 { \
	namespace DTE { \
		class DTE_API_SCOPE dataelement : \
			public base<length>, \
			public DataElement { \
		public: \
			typedef base<length> BaseType; \
			static const int  bitmapno = no; \
			 \
		public: \
			dataelement() {} \
			virtual ~dataelement() {} \
 \
			dataelement& operator=(const string& value) { \
				static_cast<BaseType&>(*this) = value; return *this; \
			} \
			dataelement& operator=(const char* value) { \
				static_cast<BaseType&>(*this) = value; return *this; \
			} \
			dataelement& operator=(nat8 value) { \
				static_cast<BaseType&>(*this) = value; return *this; \
			} \
			virtual int bitno() const { return bitmapno; } \
			virtual void decode(InputStream& is); \
			virtual void encode(OutputStream& os); \
			virtual string toString() const; \
		}; \
	} \
}
// ==========================================================================================

// ==========================================================================================
#define NUMERICDATAELEMENTNOOP(dataelement, base, length, no) \
namespace ISO_8583 { \
	namespace DTE { \
		class DTE_API_SCOPE dataelement : \
			public base<length>, \
			public DataElement { \
		public: \
			typedef base<length> BaseType; \
			static const int  bitmapno = no; \
			 \
		public: \
			dataelement() {} \
			virtual ~dataelement() {} \
 \
			dataelement& operator=(const string& value); \
			dataelement& operator=(const char* value); \
			dataelement& operator=(nat8 value) ; \
			virtual int bitno() const { return bitmapno; } \
			virtual void decode(InputStream& is); \
			virtual void encode(OutputStream& os); \
			virtual string toString() const; \
		}; \
	} \
}
// ==========================================================================================

// ==========================================================================================
#define SERIALIZE(type) \
	void type::encode(OutputStream& os) {	os << *this; } \
	void type::decode(InputStream& is) { is >> *this; }
// ==========================================================================================

#endif
