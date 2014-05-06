#include "providerdb.h"
#include<QSqlDatabase>

ProviderDB::ProviderDB()
{

}

bool ProviderDB::AddProvider()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName(".\\SQLEXPRESS");
    db.setDatabaseName("DBAgenda");
    db.setUserName("sa");
    db.setPassword("");
    bool ok = db.open();
    if(!ok) return false;
    return true;
    //Adicionar objeto no banco
}
