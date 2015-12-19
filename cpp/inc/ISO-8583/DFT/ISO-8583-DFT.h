#ifndef ISO_8583_DFT_H_
#define ISO_8583_DFT_H_

#include "ISO-8583/DTT/ISO-8583-DTT.h"

#if defined(_MSC_VER)
	#ifdef ISO_8583_DFT_EXPORTS
	#define ISO_8583_DFT_API __declspec(dllexport)
	#else
	#define ISO_8583_DFT_API __declspec(dllimport)
	#endif

	//
	// Automatically link ISO-8583-DFT library.
	//
	#if !defined(ISO_8583_NO_AUTOMATIC_LIBS) && !defined(ISO_8583_DFT_EXPORTS)
		#if STD_CB2A==150
			#pragma comment(lib, "CB2A-DFT-1_5_0" ISO_8583_LIB_SUFFIX)
		#elif STD_ISO_8583==1987
			#pragma comment(lib, "ISO-8583-DFT-1987" ISO_8583_LIB_SUFFIX)
		#else
			#error "missing define"
		#endif
	#endif
#endif

#ifndef ISO_8583_DFT_API
#define ISO_8583_DFT_API
#endif

// concat
//
// The following piece of macro magic joins the two
// arguments together, even when one of the arguments is
// itself a macro (see 16.3.1 in C++ standard).  The key
// is that macro expansion of macro arguments does not
// occur in concat_join but does in concat_do_join.
//
#define concat2(x, y)					concat_join2(x, y)
#define concat_join2(x, y)				concat_do_join2(x, y)
#define concat_do_join2(x, y)			x##y

#define concat3(x, y, z)				concat_join3(x, y, z)
#define concat_join3(x, y, z)			concat_do_join3(x, y, z)
#define concat_do_join3(x, y, z)		x##y##z

#define concat4(x, y, z, w)				concat_join4(x, y, z, w)
#define concat_join4(x, y, z, w)		concat_do_join4(x, y, z, w)
#define concat_do_join4(x, y, z, w)		x##y##z##w


#if	  defined(STD_CB2A)
#define Prefix CB2A
#elif defined(STD_ISO_8583)
#define Prefix ISO8583
#endif

#define CLASS_DEFINITION_QUESTION(prefix, name, type, rettype) \
		class concat3(prefix, name, type) : public name##type { \
		public: \
			concat3(prefix, name, type)() { \
			} \
			concat3(prefix, name, type)(Origin origin) : name##type(origin) { \
			} \
			virtual ~concat3(prefix, name, type)() { \
			} \
			\
			virtual type##rettype * indication(InputStream& is, OutputStream& os); \
			virtual bool exception() { return false; }; \
			virtual bool exception(const std::exception& exception) { return false; }; \
			virtual bool exception(const Poco::Exception& exception) { return false; }; \
		};

#define CLASS_DEFINITION_RESPONSE(prefix, name, type, rettype) \
		class concat4(prefix, name, type, rettype) : public name##type##rettype { \
		public: \
			concat4(prefix, name, type, rettype)() { \
			} \
			concat4(prefix, name, type, rettype)(Origin origin)  : name##type##rettype(origin) { \
			} \
			virtual ~concat4(prefix, name, type, rettype)() { \
			} \
			\
			virtual void confirmation(InputStream& is, OutputStream& os); \
			virtual bool exception() { return false; }; \
			virtual bool exception(const std::exception& exception) { return false; }; \
			virtual bool exception(const Poco::Exception& exception) { return false; }; \
		};

#endif
