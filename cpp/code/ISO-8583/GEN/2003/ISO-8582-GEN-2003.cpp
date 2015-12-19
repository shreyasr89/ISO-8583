#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Class {
private:
	string name;
	string iso85832003type;
	string cb2a150type;

public:
	Class(){}
	~Class() {}

	void genDeclaration();
	void genDefinition();
};

int main(int argc, char** argv[])
{
	return 0;
}
