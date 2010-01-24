#ifndef CLIENT_TCP_SOURCE
#define CLIENT_TCP_SOURCE

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <sstream>

using namespace std;

const int buffer_size = 600;
const int debug = 1;


char* remote_calc(char* input, char* address = "127.0.0.1", int port = 9020) {
	char input_buf[buffer_size];

	if (debug) {cout << "filling client input buffer" << endl;}

	sprintf(input_buf, input);

	if (debug) {cout << "Initializing socket" << endl;}
    int s = socket(AF_INET, SOCK_STREAM, 0);
	if (s == -1) {
		perror("Error on initializing socket");
		exit(1);
	}

/*
    int p = fork();

    if (p < 0)

        fprintf(stderr, "Error with fork()");

    if (p == 0) execl(path, NULL);
*/
    //sleep(2);

    struct sockaddr_in a;

    a.sin_family = AF_INET;
    a.sin_addr.s_addr = inet_addr(address);
    a.sin_port = port;

    int as = sizeof(a);

    if (debug) {cout << "Connecting host " << address << " port " << port << endl;}
    int r = connect(s, (struct sockaddr*) &a, as);

    if (r == -1) {
        perror("Error with client.");
        return "0";
    } else {
        printf("Connected to server.\n");
    }

    if (debug) {cout << "Connecting established successfully" << endl;}

	//sleep(2);

	if (debug) {cout << "Writing into socket" << endl;}
	write(s, &input_buf, buffer_size);
	printf("Sending text: %s\n", input_buf);

	if (debug) {cout << "Reading from socket" << endl;}
	read(s, &input_buf, buffer_size);
	printf("Receiving text: %s\n", input_buf);

//        i++;
 //   }

	if (debug) {cout << "Closing socket" << endl;}
	close(s);

	if (debug) {cout << "Convert result" << endl;}

	ostringstream o;
    o << input_buf;

    if (debug) {cout << "Leaving client" << endl;}
    return (char*) o.str().c_str();
    //return 0;

}

//char* path = "../server/server";
/*
int main() {

	char* result = calc("3+4");

	cout << "Result: " << result << endl;
}
*/
/* CLIENT_TCP_SOURCE */
#endif
