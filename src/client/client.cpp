#ifndef CLIENT_TCP_SOURCE
#define CLIENT_TCP_SOURCE
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <sstream>

using namespace std;

char* calc(char* input) {
	char input_buf[((int) sizeof input) + 1];

	sprintf(input_buf, input);


    cout << "Initializing socket" << endl;
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
    sleep(2);

    struct sockaddr_in a;

    a.sin_family = AF_INET;
    a.sin_addr.s_addr = inet_addr("127.0.0.1");
    a.sin_port = 9735;

    int as = sizeof(a);

    int r = connect(s, (struct sockaddr*) &a, as);

    if (r == -1) {

        perror("Error with client.");
        exit(1);

    } else {

        printf("Connected to server.\n");
    }

   // int i = 0;

    //while (i < 10) {

        sleep(2);

        write(s, &input_buf, 300);
        printf("Sending text: %s\n", input_buf);

        read(s, &input_buf, 300);
        printf("Receiving text: %s\n", input_buf);

//        i++;
 //   }

    close(s);

    ostringstream o;
    o << input_buf;

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
