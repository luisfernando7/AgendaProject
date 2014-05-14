#include "server.h"
#include <Windows.h>

server::server(QObject *parent) :
  QObject(parent)
{
  tcpServer = new QTcpServer(this);

  connect(tcpServer, SIGNAL(newConnection()), this, SLOT(newConnection()));

  if(!tcpServer->listen(QHostAddress::Any, 1234))
    {
      qDebug() << "Server could not start!";
    }
  else
    {
      qDebug() << "Server started!";
    }
}

void server::newConnection()
{
  QTcpSocket *socket = tcpServer->nextPendingConnection();


  socket->write("Hello client");

  socket->waitForBytesWritten(6000);
  socket->waitForReadyRead(60000);
  QByteArray array = socket->readAll();
  qDebug()<< array;
  socket->flush();
  socket->close();
}
