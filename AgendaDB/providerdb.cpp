#include "providerdb.h"
#include<QSqlDatabase>
#include<qdebug.h>
ProviderDB::ProviderDB()
{

}

bool ProviderDB::AddProvider(Provider p)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={SQL Server};Server=.\\SQL;Database=dbservent;");
    db.setUserName("sa");
    db.setPassword("P@ssw0rd");
    bool ok = db.open();


    return ok;
}
