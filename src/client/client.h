#ifndef CLIENT_H
#define CLIENT_H

#include <QtNetwork>
#include <QObject>
#include <QString>
#include <QTcpSocket>

class Client: public QObject
{
Q_OBJECT
public:
  Client(QObject* parent = 0);
  ~Client();
  void start(QString address, quint16 port);
  char* data;
public slots:
  void startTransfer();
private:
  QTcpSocket client;
};

#endif // CLIENT_H
