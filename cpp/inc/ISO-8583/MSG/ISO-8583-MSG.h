#ifndef ISO_8583_MSG_H_
#define ISO_8583_MSG_H_

#include "ISO-8583/DTE/ISO-8583-DTE.h"

#if defined(_MSC_VER)
	#ifdef ISO_8583_MSG_EXPORTS
	#define MSG_API_SCOPE __declspec(dllexport)
	#else
	#define MSG_API_SCOPE __declspec(dllimport)
	#endif

//
// Automatically link ISO-8583-MSG library.
//
	#if !defined(ISO_8583_NO_AUTOMATIC_LIBS) && !defined(ISO_8583_MSG_EXPORTS)
		#if STD_CB2A==150
			#pragma comment(lib, "CB2A-MSG-1_5_0" ISO_8583_LIB_SUFFIX)
		#elif STD_ISO_8583==1987
			#pragma comment(lib, "ISO-8583-MSG-1987" ISO_8583_LIB_SUFFIX)
		#else
			#error "missing define"
		#endif
	#endif
#endif

#ifndef MSG_API_SCOPE
#define MSG_API_SCOPE
#endif

#define MESSAGE_CLASS_DEFINITION(klass, function) \
		class MSG_API_SCOPE klass##function : public Message, public function { \
		private: \
			static const Bitmaps		mandatoryBits; \
			static const Bitmaps		optionalBits; \
		public: \
			klass##function() { \
			} \
			klass##function(Origin origin) : \
				Message(Class::klass, Function::function, origin){ \
			} \
			virtual ~klass##function() { \
			} \
			virtual const Bitmaps& mandatory() const; \
			virtual const Bitmaps& optional() const; \
			 \
			virtual BinaryInputStream& decode(BinaryInputStream& is); \
			virtual BinaryOutputStream& encode(BinaryOutputStream& os) const; \
			 \
			friend MSG_API_SCOPE BinaryInputStream& operator>>(BinaryInputStream& is, klass##function& rr); \
			friend MSG_API_SCOPE BinaryOutputStream& operator<<(BinaryOutputStream& os, const klass##function& rr); \
			 \
			virtual void dump(ostream& os); \
		};

#define MESSAGE_CLASS_BODY(klass, function) \
		const Bitmaps		klass##function::mandatoryBits(0); \
		const Bitmaps		klass##function::optionalBits(0); \
		 \
		const Bitmaps& klass##function::mandatory() const { \
			return mandatoryBits; \
		} \
		const Bitmaps& klass##function::optional() const { \
			return optionalBits; \
		} \
		BinaryInputStream& klass##function::decode(BinaryInputStream& is) { \
			is >> *this; \
			return is; \
		} \
		BinaryOutputStream& klass##function::encode(BinaryOutputStream& os) const { \
			os << *this; \
			return os; \
		} \
		MSG_API_SCOPE BinaryInputStream& operator>>(BinaryInputStream& is, klass##function& ar) { \
			is >> static_cast<Message&>(ar); \
			return is; \
		} \
		MSG_API_SCOPE BinaryOutputStream& operator<<(BinaryOutputStream& os, const klass##function& ar) { \
			os << static_cast<const Message&>(ar); \
			return os; \
		} \
		void klass##function::dump(ostream& os) { \
		}

#endif