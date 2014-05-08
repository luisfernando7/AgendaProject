#include "provider_material.h"

namespace model
{
QString model::Provider::name() const
{
    return _name;
}

void Provider::setName(const QString &name)
{
    _name = name;
}

QString Provider::street() const
{
    return _street;
}

void Provider::setStreet(const QString &street)
{
    _street = street;
}

int Provider::number() const
{
    return _number;
}

void Provider::setNumber(int number)
{
    _number = number;
}

QString Provider::phoneNumber() const
{
    return _phoneNumber;
}

void Provider::setPhoneNumber(const QString &phoneNumber)
{
    _phoneNumber = phoneNumber;
}

int Provider::getId() const
{
    return id;
}

void Provider::setId(int value)
{
    id = value;
}
Provider::Provider()
{
}
}
