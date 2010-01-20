
#include <bacalc_server.h>
#include <bacalc_processor.h>
#include <iostream>
#include <sstream>

using namespace std;

Server::Server(QObject *parent): QObject(parent) {

    connect(
        &server,
        SIGNAL(newConnection()),
        this,
        SLOT(acceptConnection())
    );

    server.listen(QHostAddress::Any, 8888);
}

Server::~Server()
{
  server.close();
}

void Server::acceptConnection()
{
  client = server.nextPendingConnection();

  connect(client, SIGNAL(readyRead()),
    this, SLOT(startRead()));
}

void Server::startRead()
{
  char buffer[1024] = {0};
  client->read(buffer, client->bytesAvailable());
  printf("Incoming request: '%s'\n", buffer);
  char* result = processor.process(buffer);

  ostringstream o;
  o << result;

  client->write(o.str().c_str());

  //cout << buffer << endl;
  client->close();
}
