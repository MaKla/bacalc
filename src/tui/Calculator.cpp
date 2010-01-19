#include <iostream>
#include "Parser.cpp"
#include <../client/client.h>
#include <QObject>
#include <QApplication>



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



                QString address = "127.0.0.1";
                Client *client = new Client();
                client->start(address, 8888);
                client->startTransfer();


	}
}

int main(int argc, char** argv){
        QApplication app(argc, argv);

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
