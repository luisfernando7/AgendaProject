#include "requestmaterialsdb.h"
#include "connectionfactory.h"
#include "materialdb.h"
#include "providerdb.h"

#include <QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <qdebug.h>
#include <QException>

RequestMaterialsDB::RequestMaterialsDB()
{
}

bool RequestMaterialsDB::Insert(model::RequestMaterials &obj)
{
    /*Goto Implementation!*/
    QSqlDatabase *db;
    db = ConnectionFactory::conectionInstance();
    if(db == NULL || !db->isOpen()) -1;
    QSqlQuery query;
    query.prepare("INSERT INTO [REQUEST_MATERIAL]([ID_Material],[ID_Provider],[Date],[Qtd])"
                  "VALUES(:id_material,:id_provider,:date,:qtd); SELECT  @@IDENTITY as REQUEST_MATERIAL");

    QString string = obj.date().toString("yyyy-MM-dd");
    qDebug()<<string;
    query.bindValue(":id_material", obj.material().getId());
    query.bindValue(":id_provider", obj.provider().getId());
    query.bindValue(":date", obj.date().toString("yyyy-MM-dd"));
    query.bindValue(":qtd",obj.qtd());
    bool result = query.exec();
    if(!result) return false;
    int id;
    while (query.next()) {
        id = query.value(0).toInt();
    }
    obj.setId(id);
    return true;
}

bool RequestMaterialsDB::Update(model::RequestMaterials &obj)
{
    return true;
}

bool RequestMaterialsDB::Delete(int id)
{
    return true;
}

model::RequestMaterials RequestMaterialsDB::Select(int id)
{
    model::RequestMaterials request;
    /*QSqlDatabase *db;
    db = ConnectionFactory::conectionInstance();
    if(db == NULL || !db->isOpen()) -1;
    QSqlQuery query;
    query.prepare("SELECT [ID],[Name],[Price],[Unit] FROM [Material] where [ID] = :id");
    query.bindValue(":id", id);
    bool result = query.exec();
    if(!result) return m;
    while (query.next()) {
        m.setId(query.value(0).toInt());
        m.setName(query.value(1).toString());
        m.setPrince(query.value(2).toDouble());
        m.setUnity(query.value(3).toString());
    }*/

    return request;
}

QList<model::RequestMaterials> RequestMaterialsDB::SelectAll()
{
    QList<model::RequestMaterials> list;
    QSqlDatabase *db;

    MaterialDB materialDb;
    ProviderDB providerDB;
    db = ConnectionFactory::conectionInstance();
    if(db == NULL || !db->isOpen()) return list;


    QSqlQuery query = db->exec("SELECT [ID],[ID_Material],[ID_Provider],[Date],[Qtd] FROM [REQUEST_MATERIAL]");
    QStringList listS;

    while (query.next())
    {
        listS.append(QString::number(query.value(0).toInt()));
        listS.append(QString::number(query.value(1).toInt()));
        listS.append(QString::number(query.value(2).toInt()));
        listS.append(query.value(3).toString());
        listS.append(QString::number(query.value(4).toInt()));
        listS.append("*");
    }
    model::RequestMaterials *rm;
    for (int i = 0; i <= listS.count()-2; ++i)
    {

        if(i == 0)
            rm = new model::RequestMaterials;
        else if(listS.at(i) == "*")
        {
            ++i;
            rm = new model::RequestMaterials;
        }
        rm->setId(listS.at(i).toInt());
        rm->setMaterial(materialDb.Select(listS.at(++i).toInt()));
        rm->setProvider(providerDB.Select(listS.at(++i).toInt()));
        rm->setDate(QDate::fromString(listS.at(++i),"yyyy-MM-dd"));
        rm->setQtd(listS.at(++i).toInt());
        list.append(*rm);
    }
    return list;
}

int RequestMaterialsDB::Count()
{
    return 0;
}
