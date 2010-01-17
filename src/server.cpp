
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>


using namespace std;

const int port = 2000;
const char *host = "127.0.0.1";

const char max_amount_of_connections = 1;

int main() {

	struct sockaddr_in my_addr;
	struct sockaddr_in remote_addr;

	// get a socket file descriptor
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd == -1) {
		cerr << "couldn't create inet socket";
		return 1;
	}

	my_addr.sin_family = AF_INET;         // host byte order
	my_addr.sin_port = htons(port);     // short, network byte order
	// inat_addr casts the given ip as char to 4 bytes IPv4
	my_addr.sin_addr.s_addr = inet_addr(host);
	//memset(&(my_addr.sin_zero), '\0', 8); // zero the rest of the struct

	// bind your socket. If e != 0 an error occures (if port is already in use)
	int e = bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr));

	if (e != 0) {
		cout << "could not bind to socket" << endl;
	}

	listen(sockfd, max_amount_of_connections);


	socklen_t sin_size = sizeof(struct sockaddr_in);
	int new_fd = accept(sockfd, (struct sockaddr *)&remote_addr, &sin_size);

	char buf[20];
	string dest = "";

	int nRec;
	while((nRec = ::recv(sockfd, buf, 21, 0)) != -1) {
	    buf[nRec] = '\0';
	    // Hier landen alle gesendeten Daten (also auch von mehreren send()-Aufrufen)
	    dest.append(buf);
	}

	delete [] buf;

	cout << dest << endl;

	return 1;
}
