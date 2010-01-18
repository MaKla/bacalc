#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

using namespace std;

const int port = 2000;
const char *host = "127.0.0.1";


class InetClient {
public:

	int sockfd;

	void _connect(const char* host, const int &port) {
		struct sockaddr_in dest_addr;

		// get a socket file descriptor
		sockfd = socket(AF_INET, SOCK_STREAM, 0);

		if (sockfd == -1) {
			cerr << "couldn't create inet socket";
		}


		dest_addr.sin_family = AF_INET;          // host byte order
		dest_addr.sin_port = htons(port);   // short, network byte order
		dest_addr.sin_addr.s_addr = inet_addr(host);

		int connection_status = connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr));

		if (connection_status == -1) {
			perror("Connection could not be established");
		}

	}

	void _send(const char* msg) {
		//int len = sizeof msg;
		int len = 20;

		char buf[20] = "hallo";
		int bytes_sent = send(sockfd, buf, len, 0);
	}

};

int main() {

	InetClient *client = new InetClient();

	client->_connect("127.0.0.1", 2000);
	client->_send("hallo");




	return 0;
}
