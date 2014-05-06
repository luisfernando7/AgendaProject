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

int Material::qtd() const
{
    return _qtd;
}

void Material::setQtd(int qtd)
{
    _qtd = qtd;
}

QString Material::unity() const
{
    return _unity;
}

void Material::setUnity(const QString &unity)
{
    _unity = unity;
}
Material::Material()
{
}

Material::~Material()
{
    
}
}
