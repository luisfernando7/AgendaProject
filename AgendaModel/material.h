#include "agendamodel_global.h"
#include <QString>
#include <QDate>

#ifndef MATERIAL_H
#define MATERIAL_H
namespace model {


class AGENDAMODELSHARED_EXPORT Material
{
private:
    int id;
    QString _name;
    double _prince;
    QString _unity;

public:
    Material();
    ~Material();

    QString name() const;
    void setName(const QString &name);
    double prince() const;
    void setPrince(double prince);
    QString unity() const;
    void setUnity(const QString &unity);
    int getId() const;
    void setId(int value);
};
}
Q_DECLARE_METATYPE(model::Material)
#endif // MATERIAL_H
