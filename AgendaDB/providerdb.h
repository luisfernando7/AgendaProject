#include "material.h"
#include "provider_material.h"
#include "agendadb_global.h"
#include "DB.h"
#include <qobject.h>
#ifndef PROVIDERDB_H
#define PROVIDERDB_H
class AGENDADBSHARED_EXPORT ProviderDB:virtual public DB<class model::Provider>
{

public:
    ProviderDB();
    ~ProviderDB();
    // DB interface
public:
    bool Insert(model::Provider &object);
    bool Update(model::Provider &object);
    bool Delete(int id);
    model::Provider Select(int id);
    QList<model::Provider> SelectAll();
    int Count();
};
#endif

