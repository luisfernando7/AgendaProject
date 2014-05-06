#include "provider.h"
#include "agendadb_global.h"
#include<qobject.h>

class AGENDADBSHARED_EXPORT ProviderDB
{

public:
    ProviderDB();
    bool AddProvider(Provider p);
};


