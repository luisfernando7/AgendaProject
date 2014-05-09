#include "connectionfactory.h"
#include "materialdb.h"


#include <QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <qdebug.h>
#include <QException>
MaterialDB::MaterialDB()
{

}

bool MaterialDB::Insert(model::Material &material)
{
    /*Goto Implementation!*/
    QSqlDatabase *db;
    db = ConnectionFactory::conectionInstance();
    if(db == NULL || !db->isOpen()) -1;
    QSqlQuery query;
    query.prepare("INSERT INTO [Material]([Name],[Price],[Unit])"
                  "VALUES(:name,:price,:unit); SELECT  @@IDENTITY as Material");

    query.bindValue(":name", material.name());
    query.bindValue(":price", material.prince());
    query.bindValue(":unit", material.unity());
    bool result = query.exec();
    if(!result) return false;
    int id;
    while (query.next()) {
        id = query.value(0).toInt();
    }
    material.setId(id);
    return true;
}

bool MaterialDB::Update(model::Material &material)
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
    if(db == NULL || !db->isOpen()) return list;

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
