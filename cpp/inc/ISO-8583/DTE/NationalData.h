/*
 *  NationalData.h
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */
#ifndef NATIONALDATA_H_
#define NATIONALDATA_H_

#include <vector>
using std::vector;

#include "ISO-8583/DTE/Field.h"
#include "ISO-8583/DTT/Bitmaps.h"
#include "ISO-8583/DTT/AlphaNumeric.h"
#include "ISO-8583/DTT/AlphaNumericSpace.h"
#include "ISO-8583/DTT/Bytes.h"
#include "ISO-8583/DTT/LLBytes.h"
#include "ISO-8583/DTT/LLLBytes.h"
#include "ISO-8583/DTE/TLV.h"
#include "ISO-8583/DTE/BinaryTLV.h"
#include "ISO-8583/DTT/LLLAlphaNumericSpecial.h"
#include "ISO-8583/DTE/DataElement.h"

/*
CB2A		15à		59 Données nationales	LLLVAR b …255
ISO-8583	1987	59  National data		LLLVAR ans..999
*/
namespace ISO_8583 {
	namespace DTE {
		namespace  NationalDataNamespace {

			// ===========================================================================================
#define SUBCLASS(subfield, subtype, no, datatype, length, valuetype) \
	class subfield	: public BinaryTLV, public datatype<length> { \
	protected: \
		static const int field = no; \
\
	public: \
		typedef datatype<length> DataType; \
		static const int type =  subtype; \
\
	public: \
		subfield() : BinaryTLV(type, sizeof(DataType)) { \
			assert(sizeof(subfield) == sizeof(BinaryTLV) + sizeof(DataType)); \
		} \
\
		bool operator==(valuetype value) const { \
			return static_cast<const DataType&>(*this) == value; \
		} \
		subfield& operator=(valuetype value) { \
			static_cast<DataType&>(*this) = value; \
			return *this; \
		} \
	}; \
	class subfield##Field : public subfield, public Field  { \
	public: \
		subfield##Field() { } \
		subfield##Field(const subfield& type) : \
			subfield(type) { } \
		int fieldno() const { return field; } \
		string str() const { return static_cast<const DataType&>(*this).str(); } \
	};
// ===========================================================================================



			// ============================================================================
			// Données normalisées ISO 8583 V93
			// ============================================================================
			class CodeFonction : public BinaryTLV, public Numeric < 3 > {
			protected:
				static const int field = 1;

			public:
				typedef Numeric<3> DataType;

				static const int type = 0x0100;

				enum Value {
					AutorisationInitialMontantExact = 100,
					AutorisationInitialMontantEstime = 101,
					AutorisationSupplementaireMontantExact = 106,
					AutorisationSupplementaireMontantEstime = 107,
					DemandeDeRenseignement = 108,
					FactureComplementaire = 163,
					FactureNoShow = 164
				};

			public:
				CodeFonction() : BinaryTLV(type, sizeof(DataType)) {
					assert(sizeof(CodeFonction) == sizeof(BinaryTLV) + sizeof(DataType));
				}

				bool operator==(Value value) const {
					return static_cast<const DataType&>(*this) == static_cast<int>(value);
				}
				CodeFonction& operator=(Value value) {
					static_cast<DataType&>(*this) = value;
					return *this;
				}

			};
			class CodeFonctionField : public CodeFonction, public Field  {
			public:
				CodeFonctionField() {
				}
				CodeFonctionField(const CodeFonction& type) :
					CodeFonction(type) {
				}
				int fieldno() const { return field; }
				string str() const { return static_cast<const DataType&>(*this).str(); }
			};

			// ============================================================================
			class RaisonDuMessage : public BinaryTLV, public Numeric < 4 > {
			protected:
				static const int field = 2;

			public:
				typedef Numeric<4> DataType;

			public:
				static const int type = 0x0101;

				enum Value {
					// Les valeurs 1500 à 1999 indiquent la raison d’un mess. de demande (0100) 
					// plutôt que d’avis (0120)
					DeclenchementAleatoireParTerminal = 1503,	// Déclenchement aléatoire par terminal
					OnLineForceParAccepteur = 1506,	// 1506 « on-line » forcé par l’accepteur de carte
					OnLineForceParDispositifAcceptationPourMAJ = 1507,	// 1507 « on-line » forcé par le dispositif d’acceptation de carte pour MAJ
					OnLineForcaParTerminal = 1508,	// 1508 « on-line » forcé par le terminal
					OnLineForceParEmmeteur = 1509,	// 1509 « on-line » forcé par l’émetteur de carte (code service)
					DepassementSeuilAppel = 1510,	// 1510 Dépassement seuil d’appel
					SoupconCommercant = 1511,	// 1511 Soupçons du commerçant
					BinInterdit = 1512,	// 1512 BIN interdit
					CarteInterdite = 1513,	// 1513 Carte interdite
					CumulPorteurApplication = 1651,	// 1651 Cumul/porteur/application
					BinSurveille = 1652,	// 1652 BIN surveillé
					BinInconnu = 1653,	// 1653 BIN inconnu
					NumeroSurveille = 1654,	// 1654 N° surveillé
					DemandePreAutorisation = 1655,	// 1655 Demande de pré-autorisation
					ForceParEmetteur = 1656,	// 1656 Forcé par l’émetteur (contrôle de flux)
					MonnaieEtrangere = 1657,	// 1657 Monnaie étrangère
					CodeMonnaieOuDeviseInconnue = 1658,	// 1658 Code monnaie ou devise de la transaction inconnu
					CarteRefusee = 1659,	// 1659 Carte refusée
					AppelSuiteAARQCEmisParCarte = 1660,	// 1660 Appel suite à un ARQC émis par la carte
					BinRefuse = 1663,	// 1663 Bin refusé
					StrictementOnLine = 1664,	// 1664 Strictement on-line
					OffLineAvecCapacitesOnLine = 1665,	// 1665 Off-line avec des capacités on-line
					TransactionPuceSansContactAvceDonneesPiste = 1671,	// 1671 Transaction puce sans contact utilisant les données piste
					CarteEnModeSDA = 1672,	// 1672 Carte en mode SDA
				};

			public:
				explicit RaisonDuMessage() : BinaryTLV(type, sizeof(DataType)) {
					assert(sizeof(RaisonDuMessage) == sizeof(BinaryTLV) + sizeof(DataType));
				}

				RaisonDuMessage(const RaisonDuMessage& raisonDuMessage) : BinaryTLV(type, sizeof(DataType)) {
					assert(sizeof(RaisonDuMessage) == sizeof(BinaryTLV) + sizeof(DataType));
					*this = raisonDuMessage;
				}

				RaisonDuMessage& operator=(Value value) {
					static_cast<DataType&>(*this) = value;
					return *this;
				}
			};
			class RaisonDuMessageField : public RaisonDuMessage, public Field  {
			public:
				RaisonDuMessageField() {
				}
				RaisonDuMessageField(const RaisonDuMessage& type) :
					RaisonDuMessage(type) {
				}
				int fieldno() const { return field; } \
				string str() const { return static_cast<const DataType&>(*this).str(); }
			};
			// ============================================================================
			SUBCLASS(AnneeTransaction, 0x0102, 3, Numeric, 2, nat8)
			// ============================================================================

			// ============================================================================
			// Données spécifiques CB
			// ============================================================================
			SUBCLASS(EnvironnementReglementaire, 0x0200,  4, Bytes, 1, const char*)
			// ============================================================================
			SUBCLASS(ITPAcceptation, 0x0201,  5, Numeric, 12, nat8)
			// ============================================================================
			SUBCLASS(NumeroContratAccepteur, 0x0202,  6, Numeric, 7, nat8)
			// ============================================================================
			SUBCLASS(NumeroSystemeAcceptation, 0x0203,  7, Numeric, 3, nat8)
			// ============================================================================
			SUBCLASS(NumeroPointAcceptation, 0x0204,  8, Numeric, 3, nat8)
			// ============================================================================
			SUBCLASS(CodePaysSystemAcceptation, 0x0205,  9, Numeric, 3, nat8)
			// ============================================================================
			SUBCLASS(MontantCumuleParPorteur, 0x0207,  10, Numeric, 12, nat8)
			// ============================================================================
			SUBCLASS(TASA, 0x020B,  11, Bytes, 16, const char*)
			// ============================================================================
			SUBCLASS(ITPPointAcceptation, 0x0215,  12, Numeric, 12, nat8)

			// ============================================================================
			// Données liées aux aspects sécuritaires
			// ============================================================================
			SUBCLASS(CryptogrammeVisuel, 0x0300,  13, Numeric, 2, nat8)
			// ============================================================================
			SUBCLASS(TraitementCryptogrammeVisuel, 0x0301,  14, Numeric, 2, nat8)
			// ============================================================================

			// ============================================================================
			// Données liées au commerce électronique
			// ============================================================================
			SUBCLASS(IdentificationTransaction, 0x0400,  15, Bytes, 20, const char*)
			// ============================================================================
			SUBCLASS(CryptogrammeElectronique, 0x0401,  16, Bytes, 20, const char*)
			// ============================================================================
			SUBCLASS(TypeSecurisation, 0x0407,  17, Numeric, 2, nat8)
			// ============================================================================
			SUBCLASS(TraitementCryptogrammeElectronique, 0x0409,  18, AlphaNumericSpace, 1, const char*)
			// ============================================================================
			SUBCLASS(MethodeAuthentificationPorteur, 0x0410,  19, AlphaNumericSpecial, 2, const char*)
			// ============================================================================
			SUBCLASS(MethodeCalculCryptogrammeElectronique, 0x0411,  20, AlphaNumeric, 1, const char*)
			// ============================================================================
			SUBCLASS(Resultat, 0x0412,  21, Numeric, 2, nat8)
			// ============================================================================
			SUBCLASS(ModeSecurisationTransactionModifiee, 0x0413,  22, Bytes, 1, const char*)
			// ============================================================================
			SUBCLASS(ComplementCommerceElectronique, 0x0414,  23, Bytes, 40, const char*)
			// ============================================================================
			SUBCLASS(DenominationPortefeuilleNumerique, 0x0415,  24, AlphaNumeric, 2, nat8)
			// ============================================================================
			SUBCLASS(IndicateurCommerceElectronique, 0x0416,  25, AlphaNumeric, 2, nat8)
			// ============================================================================
			SUBCLASS(ComplementPortefeuilleElectronique, 0x0417,  26, AlphaNumeric, 24, nat8)
			// ============================================================================
			SUBCLASS(IdentifiantWallet, 0x0418,  27, Numeric, 6, nat8)
			// ============================================================================

			// ============================================================================
			// Données spécifiques VISA
			// ============================================================================
			SUBCLASS(AgentUniqueId, 0x0603,  28, AlphaNumeric, 5, const char*)
			// ============================================================================

			// ============================================================================
			// Données liées au paiement pour la location de biens et services
			// ============================================================================
			SUBCLASS(TypeFacture, 0x0800,  29, Numeric, 2, nat8)
			// ============================================================================

			// ============================================================================
			// Autres
			// ============================================================================
			SUBCLASS(ServicesOptionels, 0x0805,  30, Bytes, 2, const char*)
			// ============================================================================
#undef SUBCLASS

		}
		class DTE_API_SCOPE  NationalData :
#if STD_CB2A == 150
			public LLBytes<255>,
#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
			public LLLAlphaNumericSpecial<999>,
#endif
			public DataElement {
		public:
#if STD_CB2A == 150
			typedef	LLBytes<255>					DataType;
#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993 || STD_ISO_8583 == 2003
			typedef	LLLAlphaNumericSpecial<999>		DataType;
#endif

		private:
			typedef vector<Field*> FieldContainer;

			Bitmaps				mControls;
			FieldContainer		mFields;
		
		public:
			static const int  bitmapno = 59;

		public:
			NationalData();
			virtual ~ NationalData();

			NationalData& operator=(const char* value);
			const FieldContainer& fields() const { return mFields; }
			virtual int bitno() const { return bitmapno;  }
			virtual void decode(InputStream& is);
			virtual void encode(OutputStream& os);
			virtual string toString() const;

			virtual void marshall();
			virtual void unmarshall();

			void add(Field* field);
			void dump(ostream &);
		};
	}
}

#endif
