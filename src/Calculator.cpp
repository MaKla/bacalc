#include <iostream>
#include "Parser.h"

using namespace std;

int main(){
	std::string inputFormula;
	Parser p;
	cout << "Bitte Formel eingeben: ";
	getline(cin,inputFormula);
	string outputFormula = p.validate(inputFormula);
	printf("\033[22;32mThis should be the formula you maybe wanted: ");
	cout << outputFormula << std::endl;
	printf("\033[22;30m");
	return 0;
}
