#include "providerdb.h"
#include "material.h"
#include "connectionfactory.h"


#include <QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <qdebug.h>
#include <QException>

ProviderDB::ProviderDB()
{

}

ProviderDB::~ProviderDB()
{
    ConnectionFactory::conectionInstance()->close();
}

bool ProviderDB::Insert(model::Provider p)
{
    QSqlDatabase *db;

    db = ConnectionFactory::conectionInstance();
     if(db == NULL || !db->isOpen()) return false;
    //TODO: implementar.

    QSqlQuery query;
    query.prepare("INSERT INTO [Provider]([Name],[Street],[Number],[PhoneNumber])"
                  "VALUES(:name,:street,:number,:phoneNumber)");

    query.bindValue(":name", p.name());
    query.bindValue(":street", p.street());
    query.bindValue(":number", p.number());
    query.bindValue(":phoneNumber", p.phoneNumber());
    query.exec();


    return true;
}

bool ProviderDB::Update(model::Provider object)
{
    return true;
}

bool ProviderDB::Delete(int id)
{
    return true;
}

model::Provider ProviderDB::Select(int id)
{
    model::Provider p;
    return p;
}

QList<model::Provider> ProviderDB::SelectAll()
{
    QList<model::Provider> list;
    QSqlDatabase *db;

    db = ConnectionFactory::conectionInstance();
    if(db == NULL || !db->isOpen()) list;
    //TODO: implementar.

    QSqlQuery query = db->exec("SELECT [ID],[Name],[Street],[Number],[PhoneNumber] FROM [Provider]");
    while (query.next())
    {
        model::Provider p;
        p.setId(query.value(0).toInt());
        p.setName(query.value(1).toString());
        p.setStreet(query.value(2).toString());
        p.setNumber(query.value(3).toInt());
        p.setPhoneNumber(query.value(4).toString());
        list.append(p);
    }
    return list;
}

int ProviderDB::Count()
{
    return 0;
}
