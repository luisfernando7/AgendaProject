#include "socket.h"
#include <QXmlStreamWriter>
#include <string>

Socket::Socket(QObject *parent) :
  QObject(parent)
{
}

Socket::~Socket()
{
    delete socket;
}

void Socket::Connect()
{
  socket = new QTcpSocket(this);
  socket->connectToHost("ndd-desk-dev038", 1234);

  if(socket->waitForConnected(3000))
    {
      qDebug() << "Connected!";

      socket->waitForBytesWritten(1000);
      socket->waitForReadyRead(3000);
      qDebug() << "Reading: " << socket->bytesAvailable();


      QString output;
      QXmlStreamWriter stream(&output);
      stream.setAutoFormatting(false);
      stream.writeStartDocument();

      stream.writeStartElement("bookmark");
      stream.writeAttribute("href", "http://qt.nokia.com/");
      stream.writeTextElement("title", "Qt Home");
      stream.writeEndElement();
      stream.writeEndDocument();

      socket->bytesToWrite();
      size_t packgeLenght = strlen(output.toStdString().c_str());
      socket->write(output.toStdString().c_str(),packgeLenght);
      socket->close();
    }
  else
    {
      qDebug() << "Not connected!";
    }

}
