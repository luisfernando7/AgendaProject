#include "agendamodel_global.h"
#include <QString>
#include <QDate>

#ifndef MATERIAL_H
#define MATERIAL_H
namespace model {


class AGENDAMODELSHARED_EXPORT Material
{
private:
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
    void setQtd(int qtd);
    QString unity() const;
    void setUnity(const QString &unity);
};
}
#endif // MATERIAL_H
