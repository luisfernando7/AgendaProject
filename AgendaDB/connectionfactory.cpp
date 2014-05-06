#include "connectionfactory.h"
#include <QException>

ConnectionFactory::ConnectionFactory()
{
}


QSqlDatabase *ConnectionFactory::conectionInstance()
{
    QSqlDatabase *db =  &QSqlDatabase::addDatabase("QODBC");
    db->setDatabaseName("Driver={SQL Server};Server=.\\SQL;Database=dbservent;");
    db->setUserName("sa");
    db->setPassword("P@ssw0rd_");
    if(!db->open()) return NULL;
    else return db;
}

ConnectionFactory::~ConnectionFactory()
{

}
