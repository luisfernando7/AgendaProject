#include<QSqlDatabase>
#include "agendadb_global.h"
#ifndef CONNECTIONFACTORY_H
#define CONNECTIONFACTORY_H

class AGENDADBSHARED_EXPORT ConnectionFactory
{
public:
    ConnectionFactory();
    ~ConnectionFactory();
    static QSqlDatabase *conectionInstance();

};

#endif // CONNECTIONFACTORY_H
