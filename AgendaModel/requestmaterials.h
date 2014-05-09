#include<QString>
#include<QDate>
#include "material.h"
#include "provider_material.h"
#include "agendamodel_global.h"

#ifndef REQUESTMATERIALS_H
#define REQUESTMATERIALS_H

namespace model {


class AGENDAMODELSHARED_EXPORT RequestMaterials
{
private:
    model::Material _material;
    QDate _date;
    int _qtd;
    model::Provider _provider;
public:
    RequestMaterials();
    model::Material material() const;
    void setMaterial(const model::Material &material);
    QDate date() const;
    void setDate(const QDate &date);
    model::Provider provider() const;
    void setProvider(const model::Provider &provider);
    int qtd() const;
    void setQtd(int qtd);
};
}
#endif // REQUESTMATERIALS_H
