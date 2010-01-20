#include "client.h"
#include <QHostAddress>
#include <iostream>

using namespace std;

Client::Client(QObject* parent): QObject(parent)
{
  connect(&client, SIGNAL(connected()),
    this, SLOT(startTransfer()));
}

Client::~Client()
{
  client.close();
}

void Client::start(QString address, quint16 port)
{
  QHostAddress addr(address);
  client.connectToHost(addr, port);
}

void Client::startTransfer()
{
  client.write(data, ((int)sizeof data)+1);

  char buffer[1024] = {0};
  client.read(buffer, client->bytesAvailable());

  cout << buffer << endl;
}
