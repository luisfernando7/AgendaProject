#include "requestmaterials.h"
using namespace model;

Material RequestMaterials::material() const
{
  return _material;
}

void RequestMaterials::setMaterial(const Material &material)
{
  _material = material;
}

QString RequestMaterials::description() const
{
  return _description;
}

void RequestMaterials::setDescription(const QString &description)
{
  _description = description;
}

QDate RequestMaterials::date() const
{
  return _date;
}

void RequestMaterials::setDate(const QDate &date)
{
  _date = date;
}

Provider RequestMaterials::provider() const
{
  return _provider;
}

void RequestMaterials::setProvider(const Provider &provider)
{
  _provider = provider;
}
RequestMaterials::RequestMaterials()
{
}
