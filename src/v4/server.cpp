#include <iostream>
#include <arpa/inet.h>
#include <string.h>
#include <sstream>
#include <unistd.h>
#include <tools.cpp>

using namespace std;

const char* address = "127.0.0.1";
const int port = 9765;


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

    string request_string;
    string result_string;
    //double result;

    while (1) {
    	read(cls, &strg, 300);
    	write(cls, &strg, 300);
    	/*
        cout << "Incoming request " << strg << endl;
        //strcat(strg, hello);
        // do some calculations here

        ostringstream o;
        ostringstream r;
        o << strg;
        //cout << strg;

        request_string = o.str();



        cout << Value_Of_Expr(request_string);


        //result_string = r.str();

//        r << result;



        //sprintf(strg, (char*) r.str().c_str());

        //cout << "Result: " << strg;


        //write(cls, &strg, 300);
        */
    }

    close(cls);
    close(s);
}
