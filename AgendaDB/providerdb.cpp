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

bool ProviderDB::Insert(model::Provider p)
{
    QSqlDatabase *db;

    db = ConnectionFactory::conectionInstance();
    bool ok = db->open() && db->isOpen();
    if(db == NULL || !db->isOpen()) return false;
    //TODO: implementar.


    QSqlQuery query = db->exec("SELECT name FROM Provider");
    QString name;
    while (query.next()) {
        name = query.value(0).toString();
    }
    db->close();

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
    return list;
}

int ProviderDB::Count()
{
    return 0;
}
