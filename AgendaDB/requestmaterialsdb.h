#include "agendadb_global.h"
#include "DB.h"
#include "requestmaterials.h"
#include <qobject.h>

#ifndef REQUESTMATERIALSDB_H
#define REQUESTMATERIALSDB_H
class AGENDADBSHARED_EXPORT RequestMaterialsDB: virtual public DB<class model::RequestMaterials>
{
public:
    RequestMaterialsDB();

    // DB interface
public:
    bool Insert(model::RequestMaterials &obj);
    bool Update(model::RequestMaterials &obj);
    bool Delete(int id);
    model::RequestMaterials Select(int id);
    QList<model::RequestMaterials> SelectAll();
    int Count();
};

#endif // REQUESTMATERIALSDB_H
