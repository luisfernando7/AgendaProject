#include<QString>
#include"agendamodel_global.h"
#ifndef PROVIDER_MATERIAL_H
#define PROVIDER_MATERIAL_H

namespace model {


class AGENDAMODELSHARED_EXPORT Provider
{
private:
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
};
}
#endif // PROVIDER_MATERIAL_H
