#include "material.h"
#include "provider_material.h"
#include "agendadb_global.h"
#include <qobject.h>

class AGENDADBSHARED_EXPORT ProviderDB
{

public:
    ProviderDB();
    bool AddProvider(model::Provider p);
};


