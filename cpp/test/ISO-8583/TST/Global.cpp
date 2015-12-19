// Global.cpp : définit le point d'entrée pour l'application console.
//

#include <iostream>
#include <set>
using namespace std;

#include "Poco/Glob.h"
#include "Poco/Path.h"
#include "Poco/File.h"
#include "Poco/Exception.h"
#include "Poco/DirectoryIterator.h"
#include "Poco/UTF8Encoding.h"
#include "Poco/Unicode.h"
using Poco::Glob;
using Poco::Path;
using Poco::File;
using Poco::DirectoryIterator;

string toString(const set<string>& strings) {
string result;
for (set<string>::const_iterator it = strings.begin(); it != strings.end(); ++it)
{
	result += *it;
	result += ",";
}
return result;
}

int main(int argc, char** argv)
{
	set<string> files;
#if POCO_OS == POCO_OS_WINDOWS_NT
	string pathPattern("Z:/git/pocozos/stage/docbuild/*/include/Poco/*.h");
#else
//	string pathPattern("/cygdrive/Z/git/pocozos/stage/docbuild/*/include/Poco/*.h");
	string pathPattern("/cygdrive/c/Cygwin/usr/local/*/Poco/PDF/*.h");
//	string pathPattern("/usr/local/*/Poco/PDF/*.h");
//	string pathPattern("/cygdrive/Z/git/pocozos/PDF/include/Poco/PDF/*.h");
#endif
	cout << "pathPattern=" << pathPattern << endl;
	Path path(Path::expand(pathPattern), Path::PATH_GUESS);
	cout << "path=" << path.toString() << endl;

	Path pattern(pathPattern);
	pattern.makeDirectory(); // to simplify pattern handling later on
	Path base(pattern);
	Path absBase(base);
	absBase.makeAbsolute();
	// In case of UNC paths we must not pop the topmost directory
	// (which must not contain wildcards), otherwise collect() will fail
	// as one cannot create a DirectoryIterator with only a node name ("\\srv\").
	int minDepth = base.getNode().empty() ? 0 : 1;
	while (base.depth() > minDepth && base[base.depth() - 1] != "..")
	{
		base.popDirectory();
		absBase.popDirectory();
	}
	cout << "base=" << base.toString() << endl;
	cout << "absBase=" << absBase.toString() << endl;


	Glob::glob(pathPattern, files);
	cout << toString(files) << endl;
	return 0;
}

#if 0
Application: [Debug] file=/cygdrive/Z/git/pocozos/stage/docbuild/*/include/Poco/*.h
Application: [Debug] file=/cygdrive/Z/git/pocozos/stage/docbuild/*/include/Poco/*/*.h
Application: [Debug] file=/cygdrive/Z/git/pocozos/stage/docbuild/*/include/Poco/*/*/*.h
Application: [Debug] file=/cygdrive/Z/git/pocozos/stage/docbuild/*/include/Poco/*/*.h
Application: [Debug] file=/cygdrive/Z/git/pocozos/stage/docbuild/*/*/include/Poco/*/*/*.h
#endif