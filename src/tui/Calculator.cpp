#include <iostream>
#include "parser.cpp"
#include "client.cpp"
#include <stdio.h>
#include <stdlib.h>

string host;
string port;

void input() {
	string inputFormula;
	Parser* p = new Parser();
	cout << "Please input form: ";
	getline(cin, inputFormula);
	string outputFormula = p->validate(inputFormula);
	printf("\033[22;32mThis should be the formula you maybe wanted: ");
	cout << outputFormula << endl;
	printf("\033[22;30m");

	char* result = remote_calc(
		(char*) outputFormula.c_str(),
		(char*) host.c_str(),
		atoi(port.c_str())
	);

	cout << "Result: " << result << endl;
}

int main(int argc, char** argv) {
	string menuElect;

	bool cond = true;

	cout << "Please enter server ip [127.0.0.1]: ";
	getline(cin, host);
	if(host.empty()){
		host = "127.0.0.1";
	}
	cout << "Please enter port [9020]: ";
	getline(cin, port);
	while (cond) {
		if(port.empty()){
			cond = false;
			port = 9020;
		} else if (atoi((char*) port.c_str()) == 0) {
			printf("\033[22;31mA port can only contain digits.");
			printf("\033[22;30m\n");
			cout << "Please enter port(9020): ";
			getline(cin, port);
		} else {
			cond = false;
		}
	}
	input();

	cond = true;
	while (cond) {

		cout << "Try new formula [y/n]: ";
		getline(cin, menuElect);

		if (menuElect == "y") {
			input();
		} else {
			cond = false;
		}
	}
	return 0;
}
