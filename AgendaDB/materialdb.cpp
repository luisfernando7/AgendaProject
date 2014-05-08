#include "connectionfactory.h"
#include "materialdb.h"


#include <QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <qdebug.h>
#include <QException>
MaterialDB::MaterialDB()
{

}

bool MaterialDB::Insert(model::Material object)
{
    return true;
}

bool MaterialDB::Update(model::Material object)
{
    return true;
}

bool MaterialDB::Delete(int id)
{
    return true;
}

model::Material MaterialDB::Select(int id)
{
    model::Material m;
    return m;
}

QList<model::Material> MaterialDB::SelectAll()
{
    QList<model::Material> list;
    QSqlDatabase *db;

    db = ConnectionFactory::conectionInstance();
    if(db == NULL || !db->isOpen()) list;
    //TODO: implementar.

    QSqlQuery query = db->exec("SELECT [ID],[Name],[Price],[Unit] FROM [Material]");
    while (query.next())
    {
        model::Material m;
        m.setId(query.value(0).toInt());
        m.setName(query.value(1).toString());
        m.setPrince(query.value(2).toDouble());
        m.setUnity(query.value(3).toString());
        list.append(m);
    }
    return list;
}

int MaterialDB::Count()
{
    return 0;
}
