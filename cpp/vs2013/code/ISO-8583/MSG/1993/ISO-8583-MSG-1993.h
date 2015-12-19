// Le bloc ifdef suivant est la façon standard de créer des macros qui facilitent l'exportation 
// à partir d'une DLL. Tous les fichiers contenus dans cette DLL sont compilés avec le symbole ISO8583MSG1993_EXPORTS
// défini sur la ligne de commande. Ce symbole ne doit pas être défini pour un projet
// qui utilisent cette DLL. De cette manière, les autres projets dont les fichiers sources comprennent ce fichier considèrent les fonctions 
// ISO8583MSG1993_API comme étant importées à partir d'une DLL, tandis que cette DLL considère les symboles
// définis avec cette macro comme étant exportés.
#ifdef ISO8583MSG1993_EXPORTS
#define ISO8583MSG1993_API __declspec(dllexport)
#else
#define ISO8583MSG1993_API __declspec(dllimport)
#endif

// Cette classe est exportée de ISO-8583-MSG-1993.dll
class ISO8583MSG1993_API CISO8583MSG1993 {
public:
	CISO8583MSG1993(void);
	// TODO: ajoutez ici vos méthodes.
};

extern ISO8583MSG1993_API int nISO8583MSG1993;

ISO8583MSG1993_API int fnISO8583MSG1993(void);
