#ifndef MATERIALDB_H
#define MATERIALDB_H

#include"agendadb_global.h"
#include <material.h>
#include "DB.h"
class AGENDADBSHARED_EXPORT MaterialDB:virtual public DB<class model::Material>
{
public:
    MaterialDB();

    //DB interface
public:
    bool Insert(model::Material &material);
    bool Update(model::Material &material);
    bool Delete(int id);
    model::Material Select(int id);
    QList<model::Material> SelectAll();
    int Count();
};

#endif // MATERIALDB_H
