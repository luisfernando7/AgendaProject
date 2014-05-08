#include<QString>
#include <QMetaType>
#include"agendamodel_global.h"
#ifndef PROVIDER_MATERIAL_H
#define PROVIDER_MATERIAL_H

namespace model {


class AGENDAMODELSHARED_EXPORT  Provider
{

  private:
    int id;
    QString _name;
    QString _street;
    int _number;
    QString _phoneNumber;
public:
    Provider();
    QString name() const;
    void setName(const QString &name);
    QString street() const;
    void setStreet(const QString &street);
    int number() const;
    void setNumber(int number);
    QString phoneNumber() const;
    void setPhoneNumber(const QString &phoneNumber);
    int getId() const;
    void setId(int value);
};
}
Q_DECLARE_METATYPE(model::Provider)
#endif // PROVIDER_MATERIAL_H


