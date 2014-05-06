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
    QString _description;
    QDate _date;
    model::Provider _provider;
public:
    RequestMaterials();
    model::Material material() const;
    void setMaterial(const model::Material &material);
    QString description() const;
    void setDescription(const QString &description);
    QDate date() const;
    void setDate(const QDate &date);
    model::Provider provider() const;
    void setProvider(const model::Provider &provider);
};
}
#endif // REQUESTMATERIALS_H
