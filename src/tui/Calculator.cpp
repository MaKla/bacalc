#include <iostream>
#include "Parser.cpp"
#include <../client/client.h>
#include <QObject>
#include <QApplication>
#include <QTcpSocket>
#include <QHostAddress>

void input(int argc, char** argv) {
	{
		string inputFormula;
		Parser* p = new Parser();
		cout << "Please input form: ";
		getline(cin,inputFormula);
		string outputFormula = p->validate(inputFormula);
		printf("\033[22;32mThis should be the formula you maybe wanted: ");
		cout << outputFormula << endl;
		printf("\033[22;30m");

                cout << 1 << endl;

                QApplication app(argc, argv);

                cout << 2 << endl;
                QString address = "127.0.0.1";
                int port = 8888;

                cout << 3 << endl;
                Client client;
                cout << 4 << endl;
                client.start(address, 8888);
                cout << 5 << endl;
                client.data = (char*)outputFormula.c_str();
                cout << 6 << endl;

                cout << 7 << endl;
//                Client *client = new Client();
//                client->start(address, 8888);
                //client->startTransfer();
                app.exec();


	}
}

int main(int argc, char** argv){


	string menuElect;
	
        input(argc, argv);

	bool cond = true;
	while (cond) {
		cout << "Try new formula [y/n]: ";
		getline(cin, menuElect);
		if(menuElect == "y"){
                        input(argc, argv);

		} else {
			cond = false;
		}
	}
	return 0;
}
