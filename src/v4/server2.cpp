#ifndef SERVER_TCP_SOURCE
#define SERVER_TCP_SOURCE
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

const char* address = "127.0.0.1";
const int port = 9735;

using namespace std;

int main() {

	cout << "Initializing socket" << endl;
    int s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == -1) {
		perror("Error on initializing socket");
		exit(1);
	}

    struct sockaddr_in sa;

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(address);
    sa.sin_port = port;

    int sas = sizeof(sa);


    cout << "Binding on ip " << address << " port " << port << endl;
	int check_bind = bind(s, (struct sockaddr*) &sa, sas);
	if (check_bind == -1) {
		perror("Error while binding socket");
		exit(1);
	}

	//bind(s, (struct sockaddr*) &sa, sas);

    char strg[300];

    cout << "Listening" << endl;
	int check_listen = listen(s, 5);
	if (check_listen == -1) {
		perror("Error while listening on socket");
		exit(1);
	}

    struct sockaddr_in cla;

    int clas = sizeof(cla);

    cout << "Accepting" << endl;
	int cls = accept(s, (struct sockaddr*) &cla, (socklen_t*) &clas);
	if (cls == -1) {
		perror("Error while accepting");
	}

    char hello[300] = "Hello!";

    while (1) {

        read(cls, &strg, 300);
        strcat(strg, hello);
        write(cls, &strg, 300);
    }

    close(cls);
    close(s);
}

#endif
