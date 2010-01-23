#include <iostream>
#include "parser.cpp"
#include "client.cpp"
//#include "client.h"
#include <stdio.h>
#include <stdlib.h>

void input() {
	{
		string inputFormula;
		Parser* p = new Parser();
		cout << "Please input form: ";
		getline(cin,inputFormula);
		string outputFormula = p->validate(inputFormula);
		printf("\033[22;32mThis should be the formula you maybe wanted: ");
		cout << outputFormula << endl;
		printf("\033[22;30m");

		char* result = calc((char*) outputFormula.c_str());
		// roebi, hier kannst du irgendwas mit result machen, du kanns auch
		// den kompletten aufruf verschieben
	}
}

int main(int argc, char** argv){
	string menuElect;
	string host, port;
	bool cond = true;


	cout << "Please enter servername or ip: ";
	getline(cin, host);
	cout << "Please enter port: ";
	getline(cin, port);
	while (cond) {
		if(atoi((char*) port.c_str()) == 0){
			printf("\033[22;31mA port can only contain digits.");
			printf("\033[22;30m\n");
			cout << "Please enter port: ";
			getline(cin, port);
		} else{
			cond = false;
		}
	}	
	input();

	cond = true;
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
