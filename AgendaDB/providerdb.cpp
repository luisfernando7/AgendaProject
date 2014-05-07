#include "providerdb.h"
#include "material.h"
#include "connectionfactory.h"


#include<QSqlDatabase>
#include<qdebug.h>
#include<QException>
ProviderDB::ProviderDB()
{

}

bool ProviderDB::Insert(model::Provider p)
{
    QSqlDatabase *db;

    db = ConnectionFactory::conectionInstance();
    if(db == NULL || !db->isOpen()) return false;
    //TODO: implementar.


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
