#include "material.h"

namespace model {


QString Material::name() const
{
    return _name;
}

void Material::setName(const QString &name)
{
    _name = name;
}

double Material::prince() const
{
    return _prince;
}

void Material::setPrince(double prince)
{
    _prince = prince;
}

QString Material::unity() const
{
    return _unity;
}

void Material::setUnity(const QString &unity)
{
    _unity = unity;
}

int Material::getId() const
{
    return id;
}

void Material::setId(int value)
{
    id = value;
}
Material::Material()
{
}

Material::~Material()
{
    
}
}
