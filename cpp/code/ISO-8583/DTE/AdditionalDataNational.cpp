/*
 * AdditionalDataNational.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include <typeinfo>
#include <stdexcept>
using namespace std;

#include "ISO-8583/DTE/AdditionalDataNational.h"
using namespace ISO_8583::DTE;
using namespace ISO_8583::DTE::AdditionalDataNationalNamespace;



namespace ISO_8583 {
	namespace DTE {
		namespace AdditionalDataNationalNamespace {
#if STD_CB2A == 150
			DTE_API_SCOPE const char* CodeDonneesPointService::type =  "03";
			DTE_API_SCOPE const char* TypeSite::type =  "08";
			DTE_API_SCOPE const char* ConversionChamp::type =  "20";
			DTE_API_SCOPE const char* NumeroDossier::type =  "24";
			DTE_API_SCOPE const char* CapaciteAdditionnelleLectureCarte::type =  "30";
			DTE_API_SCOPE const char* PointAcceptation::type =  "31";
			DTE_API_SCOPE const char* Siret::type =  "96";
			DTE_API_SCOPE const char* IDPA::type =  "97";
			DTE_API_SCOPE const char* IDSA::type =  "A0";
#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 2003
#endif 
		}
		AdditionalDataNational::AdditionalDataNational() {
		}
		AdditionalDataNational::~AdditionalDataNational() {
			for (int no = 0; no < fields.size(); no++) {
				Field* field = fields.at(no);
				delete field;
			}
		}
		void AdditionalDataNational::decode(InputStream& is) {
			is >> static_cast<DataType&>(*this);
		}
		void AdditionalDataNational::encode(OutputStream& os) {
			os << static_cast<const DataType&>(*this);
		}
		string AdditionalDataNational::toString() const {
			string s(str());
			return s;
		}
		void AdditionalDataNational::add(Field* field) {
			byte fieldno = field->fieldno();
			if (controls.get(fieldno)) {
				string message("field already added: ");
				message += typeid(*field).name();
				throw logic_error(message);
			} else {
				fields.push_back(field);
				controls.set(fieldno);
			}
		}
		void AdditionalDataNational::marshall() {
			byte* beg = 0;
			byte* tlv = NULL;
#if STD_CB2A == 150
			beg = tlv = static_cast<AdditionalDataNational::DataType*>(this)->data();
			for (int no = 0; no < fields.size(); no++) {
				Field* field = fields.at(no);

#define MAP(type) \
			if (typeid(*field) == typeid(type##Field)) { \
				type##Field* typeField = (type##Field*)field; \
				type* source = static_cast<type*>(typeField); \
				type* sink = (type*)tlv; \
				*sink = *source; \
				tlv += sizeof(type); \
						} else

				MAP(CodeDonneesPointService)
					MAP(TypeSite)
					MAP(ConversionChamp)
					MAP(NumeroDossier)
					MAP(CapaciteAdditionnelleLectureCarte)
					MAP(PointAcceptation)
					MAP(Siret)
					MAP(IDPA)
					MAP(IDSA)
					throw runtime_error(string("unknown subfield:"));
			}
#undef	MAP
#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 2003
#endif
			length(tlv - beg);
		}
		void AdditionalDataNational::unmarshall() {
#if STD_CB2A == 150
			byte* tlv = NULL;
			tlv = static_cast<AdditionalDataNational::DataType*>(this)->data();
			int remain = length();
			while (remain > 0) {
#define UNMAP(subtype) \
			if (((TLV*)tlv)->tag() == subtype::type) { \
				subtype##Field* subtypeField; \
				subtypeField = new subtype##Field(*(subtype*)tlv); \
				add(subtypeField); \
				tlv += sizeof(subtype); \
				remain -= sizeof(subtype); \
						} else
				UNMAP(CodeDonneesPointService)
					UNMAP(TypeSite)
					UNMAP(ConversionChamp)
					UNMAP(NumeroDossier)
					UNMAP(CapaciteAdditionnelleLectureCarte)
					UNMAP(PointAcceptation)
					UNMAP(Siret)
					UNMAP(IDPA)
					UNMAP(IDSA)
					throw runtime_error(string("unknown subfield:"));
			}
#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 2003
#endif
		}
	}
}