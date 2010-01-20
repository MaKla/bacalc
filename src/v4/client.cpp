#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <unistd.h>
#include <string.h>
#include "client.h"
#include <iostream>

using namespace std;

char* process(char* request, char* address, int port) {

	cout << "Initializing socket" << endl;
    int s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == -1) {
		perror("Error on initializing socket");
		exit(1);
	}


	sleep(2);

	char t[(int) sizeof request];
	strcat(t, request);

	struct sockaddr_in a;

	a.sin_family = AF_INET;
	a.sin_addr.s_addr = inet_addr(address);
	a.sin_port = port;

	int as = sizeof(a);

	cout << "Connecting host " << address << " port " << port << endl;
	int r = connect(s, (struct sockaddr*) &a, as);
	if (r == -1) {
		perror("Error while connecting");
		exit(1);
	} else {
		printf("Connected to server.\n");
	}

	//char req_buf[sizeof request];

	//sprintf(req_buf, request);
	//strcat(req_buf, request);

	//cout << req_buf[0];
	//req_buf << request;



	sleep(2);

	write(s, &t, 300);

	read(s, &t, 300);

	//cout << t << endl;

	sleep(2);
/*
	ostringstream o;
	o << t;

	return (char*) o.str().c_str();
	*/
}
