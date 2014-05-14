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

int RequestMaterials::qtd() const
{
    return _qtd;
}

void RequestMaterials::setQtd(int qtd)
{
    _qtd = qtd;
}

int RequestMaterials::id() const
{
    return _id;
}

void RequestMaterials::setId(int id)
{
    _id = id;
}
RequestMaterials::RequestMaterials()
{
}
