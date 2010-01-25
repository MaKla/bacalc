#ifndef SERVER_TCP_SOURCE
#define SERVER_TCP_SOURCE
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <tools.cpp>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

//#include <netinet/in.h>

const char* address = "127.0.0.1";
const int port = 9020;

using namespace std;


class BacalcServer {
public:
	char* bla(char* input) {
		ostringstream o;
		ostringstream r;

		double calc_result;

		o << input;

		calc_result = Value_Of_Expr(o.str());

		r << calc_result;

		cout << "--" << calc_result << "--" << endl;

		return (char*) r.str().c_str();
	}
/*
	void echo() {
		cout << "asdf" << endl;
	}
*/
};

int main() {

	//double calc_result;

	cout << "Initializing socket" << endl;
    int s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == -1) {
		perror("Error on initializing socket");
		exit(1);
	}

    int set = 1;


    //setsockopt(s, SOL_SOCKET, SOF_NOSIGPIPE, (void *)&set, sizeof(int));
    //setsockopt(s, SOL_SOCKET, SO_NOSIGPIPE, (void *)&set, sizeof(int));
    //setsockopt(s, SOL_SOCKET, MSG_NOSIGNAL, (void *)&set, sizeof(int));


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
	int check_listen = listen(s, 5000);
	if (check_listen == -1) {
		perror("Error while listening on socket");
		exit(1);
	}

    struct sockaddr_in cla;

    int clas = sizeof(cla);

    while (1) {
		cout << "Accepting" << endl;
		int cls = accept(s, (struct sockaddr*) &cla, (socklen_t*) &clas);
		if (cls == -1) {
			perror("Error while accepting");
		}

		char hello[300] = "Hello!";

		//ostringstream incoming_converter;
		//ostringstream outgoing_converter;

		BacalcServer* bacalc_s = new BacalcServer();

		//while (1) {

			if (read(cls, &strg, 300) == -1 ){
				perror("Error while reading");
			}
			cout << "Incoming request '" << strg << "'" << endl;


			//strcat(strg, bacalc_s->bla(strg));
			sprintf(strg, bacalc_s->bla(strg));


			cout << "Sending Result '" << strg << "'" << endl;
			//if (write(cls, &strg, 300) == -1){
			//if (send(cls, &strg, (size_t) 300, MSG_NOSIGNAL) == -1){
			if (send(cls, &strg, (size_t) 300, 0) == -1){
							perror("Error while writing");
			}

		//}

		close(cls);
    }
    close(s);
}

#endif
