#ifndef SERVER_H

#define SERVER_H

#include <QObject>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <bacalc_processor.h>

class Server: public QObject {
    Q_OBJECT
public:
    Server(QObject *parent = 0);
    ~Server();


public slots:
  void acceptConnection();
  void startRead();
private:
  QTcpServer server;
  QTcpSocket* client;
  Processor processor;

};

#endif // SERVER_H
