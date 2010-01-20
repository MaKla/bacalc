#ifndef SERVER_TCP_SOURCE
#define SERVER_TCP_SOURCE
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main() {

    int s = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in sa;

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    sa.sin_port = 9735;

    int sas = sizeof(sa);

    bind(s, (struct sockaddr*) &sa, sas);

    char strg[300];

    listen(s, 5);

    struct sockaddr_in cla;

    int clas = sizeof(cla);

    int cls = accept(s, (struct sockaddr*) &cla, (socklen_t*) &clas);

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
