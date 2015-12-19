/*
 * AdditionalDataNational.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#ifndef ADDITIONALDATANATIONAL_H_
#define ADDITIONALDATANATIONAL_H_

#include <string>
using std::to_string;
#include <vector>
using std::vector;

#include "ISO-8583/DTT/Bitmaps.h"
#include "ISO-8583/DTE/Field.h"
#include "ISO-8583/DTE/Constructed.h"
#include "ISO-8583/DTT/LLLAlphaNumericSpecial.h"
#include "ISO-8583/DTT/AlphaNumeric.h"
#include "ISO-8583/DTT/AlphaNumericSpace.h"
#include "ISO-8583/DTT/Numeric.h"
#include "ISO-8583/DTT/LLBytes.h"
#include "ISO-8583/DTT/LLLBytes.h"
#include "ISO-8583/DTE/TLV.h"
#include "ISO-8583/DTE/DataElement.h"

/*
CB2A		150		47 Données complémentaires nationales LLLVAR ans …255
ISO-8583	1987	47 Additional data national LLLVAR ans..999
ISO-8583	1993	47 Additional data national LLLVAR ans..999
ISO-8583	2003	47 Additional data national LLLVAR ans..999
*/
using ISO_8583::DTE::TLV;

namespace ISO_8583 {
	namespace DTE {

#define SUBCLASS(subfield, subtype, no, datatype, length, valuetype) \
	class subfield	: public TLV, public datatype<length> { \
	protected: \
		static const int field = no; \
\
public: \
	typedef datatype<length> DataType; \
	DTE_API_SCOPE static const char* type; \
\
public: \
	subfield() : TLV(type, sizeof(DataType)) { \
		assert(sizeof(subfield) == sizeof(TLV) + sizeof(DataType)); \
	} \
\
	subfield& operator=(valuetype value) { \
		static_cast<DataType&>(*this) = value; \
		return *this; \
	} \
}; \
class subfield##Field : public subfield, public Field  { \
public: \
	subfield##Field() {} \
	subfield##Field(const subfield& sub) : \
		subfield(sub) { \
	} \
	int fieldno() const { return field; } \
	string str() const { return static_cast<const DataType&>(*this).str(); } \
};

		namespace AdditionalDataNationalNamespace {

			// ============================================================================
			//
			// ============================================================================
			class CodeDonneesPointService : public TLV, public AlphaNumericSpecial < 12 > {
			protected:
				static const int field = 1;

			public:
				typedef AlphaNumericSpecial<12> DataType;

				DTE_API_SCOPE static const char* type;	// "03"

				enum Value {
					Inconnue = 0,
					Manuel = 1,
					LecteurPisteMagnetique = 2,
					LecteurMicroCircuitSansContactEMV = 3,
					LecteurMicroCircuitSansContactmagentique = 4,
					LecteurMicroCircuit = 5,
					SaisieClavier = 6
				};


			public:
				explicit CodeDonneesPointService() : TLV(type, sizeof(DataType)) {
					assert(sizeof(CodeDonneesPointService) == sizeof(TLV) + sizeof(DataType));
				}

				CodeDonneesPointService(const CodeDonneesPointService& codeDonneesPointService) : TLV(type, sizeof(DataType)) {
					assert(sizeof(CodeDonneesPointService) == sizeof(TLV) + sizeof(DataType));
					*this = codeDonneesPointService;
				}

				CodeDonneesPointService& operator=(Value value) {
					string asstring(to_string(value));
					static_cast<DataType&>(*this) = asstring.c_str();
					return *this;
				}
			};
			class CodeDonneesPointServiceField : public CodeDonneesPointService, public Field  {
			public:
				CodeDonneesPointServiceField() {
				}
				CodeDonneesPointServiceField(const CodeDonneesPointService& type) :
					CodeDonneesPointService(type) {
				}
				int fieldno() const { return field; }
				string str() const { return static_cast<const DataType&>(*this).str(); }
			};


			// ============================================================================
			// Données spécifiques CB
			// ============================================================================
			SUBCLASS(TypeSite, "08", 2, AlphaNumericSpecial, 8, const char*)
			// ============================================================================
			SUBCLASS(ConversionChamp, "20", 3, AlphaNumericSpecial, 8, const char*)
			// ============================================================================
			SUBCLASS(NumeroDossier, "24", 4, AlphaNumericSpecial, 12, const char*)
			// ============================================================================
			SUBCLASS(CapaciteAdditionnelleLectureCarte, "30", 5, Numeric, 1, nat8)
			// ============================================================================
			SUBCLASS(PointAcceptation, "31", 6, Numeric, 1, nat8)
			// ============================================================================
			SUBCLASS(Siret, "96", 7, Numeric, 14, nat8)
			// ============================================================================
			SUBCLASS(IDPA, "97", 8, AlphaNumericSpace, 8, const char*)
			// ============================================================================
			SUBCLASS(IDSA, "A0", 9, AlphaNumericSpace, 8, const char*)
			// ============================================================================
#undef SUBCLASS
		}

		class DTE_API_SCOPE AdditionalDataNational :
#if STD_CB2A == 150
/*
			public LLLAlphaNumericSpecial<255>,

  bug spec CB2A Autorisation:
  AdditionalDataNational contient des TLVs dont la longeur est un byte en binaire
  qui est forcement en contradiction avec le type AlphaNumericSpecial
*/
			public LLBytes<255>, 
#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
			public LLLAlphaNumericSpecial<999>,
#endif
			public DataElement,
			public Constructed {
		private:
			Bitmaps		controls;

		public:
#if STD_CB2A == 150
			typedef LLBytes<255> DataType;
#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
			typedef LLLAlphaNumericSpecial<999> DataType;
#endif

			static const int  bitmapno = 47;
			vector<Field*>		fields;

		public:
			AdditionalDataNational();
			virtual ~AdditionalDataNational();

			AdditionalDataNational& operator=(const char* value) {
				static_cast<DataType&>(*this) = value; return *this;
			}

			virtual int bitno() const { return bitmapno;  }
			virtual void decode(InputStream& is);
			virtual void encode(OutputStream& os);
			virtual string toString() const;

			virtual void marshall();
			virtual void unmarshall();

			void add(Field* field);
		};
	}
}

#endif
