
#include "client.h"
#include <QHostAddress>
#include <iostream>

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
  printf("Sending data");
  int r = client.write("Kack mich an", 13);
  printf("%i", r);
}
