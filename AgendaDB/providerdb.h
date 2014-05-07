#include "material.h"
#include "provider_material.h"
#include "agendadb_global.h"
#include "DB.h"
#include <qobject.h>

class AGENDADBSHARED_EXPORT ProviderDB:public DB<class model::Provider>
{

public:
    ProviderDB();
    // DB interface
public:
    bool Insert(model::Provider object);
    bool Update(model::Provider object);
    bool Delete(int id);
    model::Provider Select(int id);
    QList<model::Provider> SelectAll();
    int Count();
};


