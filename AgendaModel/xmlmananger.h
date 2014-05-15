#ifndef XMLMANANGER_H
#define XMLMANANGER_H
#include<QString>
#include "requestmaterials.h"
#include "agendamodel_global.h"

class AGENDAMODELSHARED_EXPORT XMLMananger
{
public:
    XMLMananger();
    static QString BuildRequestMaterial(model::RequestMaterials request);
    static model::RequestMaterials ParseRequestMaterial(QString source);
};

#endif // XMLMANANGER_H
