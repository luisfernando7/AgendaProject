#include "requestmaterialsdb.h"

RequestMaterialsDB::RequestMaterialsDB()
{
}

bool RequestMaterialsDB::Insert(model::RequestMaterials &obj)
{
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
    return request;
}

QList<model::RequestMaterials> RequestMaterialsDB::SelectAll()
{
    QList<model::RequestMaterials> list;
    return list;
}

int RequestMaterialsDB::Count()
{
    return 0;
}
