#include "connectionfactory.h"
#include <QException>
#include <QSqlQuery>
#include <QVariant>
ConnectionFactory::ConnectionFactory()
{
}


QSqlDatabase *ConnectionFactory::conectionInstance()
{
    QSqlDatabase *db =  new QSqlDatabase(QSqlDatabase::addDatabase("QODBC"));
    db->setDatabaseName("Driver={SQL Server};Server=.\\SQL;Database=dbagenda;");
    db->setUserName("sa");
    db->setPassword("P@ssw0rd");
    return db;
}

ConnectionFactory::~ConnectionFactory()
{

}
