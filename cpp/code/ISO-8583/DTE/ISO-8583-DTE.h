#ifndef ISO_8583_DTE_H_
#define ISO_8583_DTE_H_

#include "ISO-8583/DTT/ISO-8583-DTT.h"

#ifdef _Win32_
#define DTE_API_SCOPE __declspec(dllexport)
#else
#define DTE_API_SCOPE __declspec(dllimport)
#endif
#endif

#ifndef DTE_API_SCOPE
#define DTE_API_SCOPE
#endif

using namespace ISO_8583::DTT;

#include "ISO-8583/DTT/Numeric.h"
#include "ISO-8583/DTT/LLNumeric.h"

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
			virtual void serialize(ostream& os); \
			virtual void serialize(istream& is); \
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
			virtual void encode(ostream& os); \
			virtual void decode(istream& is); \
			virtual string toString() const; \
		}; \
	} \
}
// ==========================================================================================

// ==========================================================================================
#define SERIALIZE(type) \
	void type::encode(ostream& os) { \
		os << *this; \
	} \
	void type::decode(istream& is) { \
		is >> *this; \
	}
// ==========================================================================================

#endif
