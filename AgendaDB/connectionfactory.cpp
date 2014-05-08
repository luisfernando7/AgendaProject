#include "connectionfactory.h"
#include <QException>
#include <QSqlQuery>
#include <QVariant>
ConnectionFactory::ConnectionFactory()
{
}


QSqlDatabase *ConnectionFactory::conectionInstance()
{
    static QSqlDatabase *db =  new QSqlDatabase(QSqlDatabase::addDatabase("QODBC"));//Skill +1 up.
    db->setDatabaseName("Driver={SQL Server};Server=.\\SQL;Database=dbagenda;");
    db->setUserName("sa");
    db->setPassword("P@ssw0rd");
    db->open();
    return db;
}

ConnectionFactory::~ConnectionFactory()
{

}
