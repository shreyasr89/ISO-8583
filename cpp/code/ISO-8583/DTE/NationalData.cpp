/*
 *  NationalData.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include <typeinfo>
#include <stdexcept>
using namespace std;

#include "ISO-8583/DTE/NationalData.h"
using namespace ISO_8583::DTE;
using namespace ISO_8583::DTE:: NationalDataNamespace;

#if STD_CB2A == 150
#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 2003
#endif 


namespace ISO_8583 {
	namespace DTE {

		 NationalData::NationalData() {
		}
		 NationalData::~ NationalData() {
			for (int no = 0; no < mFields.size(); no++) {
				Field* field = mFields.at(no);
				delete field;
			}
		}
		NationalData& NationalData::operator=(const char* value) {
			static_cast<DataType&>(*this) = value; return *this;
		}
		void  NationalData::decode(InputStream& is) {
			is >> static_cast<DataType&>(*this);
		}
		void  NationalData::encode(OutputStream& os) {
			os << static_cast<const DataType&>(*this);
		}
		string  NationalData::toString() const {
			string s(str());
			return s;
		}
		void  NationalData::add(Field* field) {
			byte fieldno = field->fieldno();
			if (mControls.get(fieldno)) {
				string message("field already added: ");
				message += typeid(*field).name();
				throw logic_error(message);
			} else {
				mFields.push_back(field);
				mControls.set(fieldno);
			}
		}
		void  NationalData::marshall() {
			const byte* beg = 0;
			byte* tlv = NULL;
			int offset = 0;
#if STD_CB2A == 150
			beg = tlv = static_cast< NationalData::DataType*>(this)->data();
			for (int no = 0; no < fields().size(); no++) {
				Field* field = fields().at(no);

				// ==================================================================================================
#define MAP(subfield) \
			if (typeid(*field) == typeid(subfield##Field)) { \
				offset = tlv - beg; \
				subfield##Field* typeField = (subfield##Field*)field; \
				subfield* source = static_cast<subfield*>(typeField); \
				subfield* sink = (subfield*)tlv; \
				if (offset > sizeof(DataType)) { \
					string message ("field "); \
					message += typeid(*sink).name(); \
					message += " at offset "; \
					message += to_string(offset); \
					message += " > sizeof( NationalData)"; \
					throw overflow_error(message); \
				} \
				*sink = *source; \
				sink->hostToNetwork(); \
				if (false) { \
					cout << "offset="; \
					cout.width(4); \
					cout << tlv - beg << " " << typeid(*sink).name() << endl; \
												} \
				tlv += sizeof(subfield); \
			} else 
// ==================================================================================================

				MAP(CodeFonction)
				MAP(RaisonDuMessage)
				MAP(AnneeTransaction)
				MAP(EnvironnementReglementaire)
				MAP(ITPAcceptation)
				MAP(NumeroContratAccepteur)
				MAP(NumeroSystemeAcceptation)
				MAP(NumeroPointAcceptation)
				MAP(CodePaysSystemAcceptation)
				MAP(MontantCumuleParPorteur)
				MAP(TASA)
				MAP(ITPPointAcceptation)
				MAP(CryptogrammeVisuel)
				MAP(TraitementCryptogrammeVisuel)
				MAP(IdentificationTransaction)
				MAP(CryptogrammeElectronique)
				MAP(TypeSecurisation)
				MAP(TraitementCryptogrammeElectronique)
				MAP(MethodeAuthentificationPorteur)
				MAP(MethodeCalculCryptogrammeElectronique)
				MAP(Resultat)
				MAP(ModeSecurisationTransactionModifiee)
				MAP(ComplementCommerceElectronique)
				MAP(DenominationPortefeuilleNumerique)
				MAP(IndicateurCommerceElectronique)
				MAP(ComplementPortefeuilleElectronique)
				MAP(IdentifiantWallet)
				MAP(AgentUniqueId)
				MAP(TypeFacture)
				MAP(ServicesOptionels)
				throw runtime_error(string("unknown subfield:"));
			}
#undef	MAP
#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#endif
			int l = tlv - beg;
			length(tlv - beg);
		}
		void  NationalData::unmarshall() {
#if STD_CB2A == 150
			byte* tlv = static_cast< NationalData::DataType*>(this)->data();
			byte* beg = tlv;
			int remain = length();
			while (remain > 0) {
				BinaryTLV* binaryTLV = (BinaryTLV*)tlv;
				binaryTLV->networkToHost();
// ==================================================================================================
#define UNMAP(subtype) \
				if (binaryTLV->tag() == subtype::type) { \
					if (false) \
						cout << "offset=" << tlv - beg << " tag=" << short_to_hex(binaryTLV->tag()) << " " << #subtype << endl; \
					subtype##Field* subtypeField; \
					subtypeField = new subtype##Field(*(subtype*)tlv); \
					add(subtypeField); \
					tlv += sizeof(subtype); \
					remain -= sizeof(subtype); \
				} else
// =================================================================================================

				UNMAP(CodeFonction)
				UNMAP(RaisonDuMessage)
				UNMAP(AnneeTransaction)
				UNMAP(EnvironnementReglementaire)
				UNMAP(ITPAcceptation)
				UNMAP(NumeroContratAccepteur)
				UNMAP(NumeroSystemeAcceptation)
				UNMAP(NumeroPointAcceptation)
				UNMAP(CodePaysSystemAcceptation)
				UNMAP(MontantCumuleParPorteur)
				UNMAP(TASA)
				UNMAP(ITPPointAcceptation)
				UNMAP(CryptogrammeVisuel)
				UNMAP(TraitementCryptogrammeVisuel)
				UNMAP(IdentificationTransaction)
				UNMAP(CryptogrammeElectronique)
				UNMAP(TypeSecurisation)
				UNMAP(TraitementCryptogrammeElectronique)
				UNMAP(MethodeAuthentificationPorteur)
				UNMAP(MethodeCalculCryptogrammeElectronique)
				UNMAP(Resultat)
				UNMAP(ModeSecurisationTransactionModifiee)
				UNMAP(ComplementCommerceElectronique)
				UNMAP(DenominationPortefeuilleNumerique)
				UNMAP(IndicateurCommerceElectronique)
				UNMAP(ComplementPortefeuilleElectronique)
				UNMAP(IdentifiantWallet)
				UNMAP(AgentUniqueId)
				UNMAP(TypeFacture)
				UNMAP(ServicesOptionels)
				{
					string message;
					message += "unknown tag: ";
					message += short_to_hex(binaryTLV->tag());
					message += " at offset ";
					message += to_string(tlv - beg);
					throw runtime_error(message);
				}
			}
#undef	UNMAP
#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
#endif
		}
		void NationalData::dump(ostream & os) {
			char buffer[1024];
			const string FORMAT = "\t%-45s:%s";

			string label;
			string value;
			for (int no = 0; no < mFields.size(); no++) {
				Field* field = mFields[no];
				switch (field->fieldno()) {
				case 1: 
					label = "CodeFonction"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 2: 
					label = "RaisonDuMessage"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 3: 
					label = "AnneeTransaction"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 4: 
					label = "EnvironnementReglementaire"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 5: 
					label = "ITPAcceptation"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 6: 
					label = "NumeroContratAccepteur"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 7: 
					label = "NumeroSystemeAcceptation"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 8: 
					label = "NumeroPointAcceptation"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 9: 
					label = "CodePaysSystemAcceptation"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 10: 
					label = "MontantCumuleParPorteur"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 11: 
					label = "TASA"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 12: 
					label = "ITPPointAcceptation"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 13: 
					label = "CryptogrammeVisuel"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 14: 
					label = "TraitementCryptogrammeVisuel"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 15: 
					label = "IdentificationTransaction"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 16: 
					label = "CryptogrammeElectronique"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 17: 
					label = "TypeSecurisation"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 18: 
					label = "TraitementCryptogrammeElectronique"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 19: 
					label = "MethodeAuthentificationPorteur"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 20: 
					label = "MethodeCalculCryptogrammeElectronique"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 21: 
					label = "Resultat"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 22: 
					label = "ModeSecurisationTransactionModifiee"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 23: 
					label = "ComplementCommerceElectronique"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 24: 
					label = "DenominationPortefeuilleNumerique"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 25: 
					label = "IndicateurCommerceElectronique"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 26: 
					label = "ComplementPortefeuilleElectronique"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 27: 
					label = "IdentifiantWallet"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 28: 
					label = "AgentUniqueId"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 29: 
					label = "TypeFacture"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				case 30:
					label = "ServicesOptionels"; value = field->str(); sprintf(buffer, FORMAT.c_str(), label.c_str(), value.c_str());
					os << buffer << endl; break;
				}
			}
		}
	}
}