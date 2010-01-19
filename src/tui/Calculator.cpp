#include <iostream>
#include "Parser.cpp"


void input(){
	{
		string inputFormula;
		Parser* p = new Parser();
		cout << "Please input form: ";
		getline(cin,inputFormula);
		string outputFormula = p->validate(inputFormula);
		printf("\033[22;32mThis should be the formula you maybe wanted: ");
		cout << outputFormula << endl;
		printf("\033[22;30m");
	}
}

int main(){
	string menuElect;
	
	input();
	
	bool cond = true;
	while (cond) {
		cout << "Try new formula [y/n]: ";
		getline(cin, menuElect);
		if(menuElect == "y"){
			input();
		} else {
			cond = false;
		}
	}
	return 0;
}