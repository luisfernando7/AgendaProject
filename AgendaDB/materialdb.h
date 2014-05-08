#ifndef MATERIALDB_H
#define MATERIALDB_H

#include"agendadb_global.h"
#include <material.h>
#include "DB.h"
class AGENDADBSHARED_EXPORT MaterialDB: public DB<class model::Material>
{
public:
    MaterialDB();

    //DB interface
public:
    bool Insert(model::Material object);
    bool Update(model::Material object);
    bool Delete(int id);
    model::Material Select(int id);
    QList<model::Material> SelectAll();
    int Count();
};

#endif // MATERIALDB_H
