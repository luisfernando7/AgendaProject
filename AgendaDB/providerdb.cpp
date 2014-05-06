#include "providerdb.h"
#include "material.h"
#include "connectionfactory.h"


#include<QSqlDatabase>
#include<qdebug.h>
#include<QException>
ProviderDB::ProviderDB()
{

}

bool ProviderDB::AddProvider(model::Provider p)
{
    //MemCheck memChk;
    QSqlDatabase *db;

    db = ConnectionFactory::conectionInstance();
    if(db == NULL || !db->isOpen()) return false;
    //TODO: implementar.

    db->close();
    //memChk.Check();
    return true;
}
