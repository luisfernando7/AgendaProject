#include<QString>
#include<QDate>
#include "material.h"
#include "provider.h"

#ifndef REQUESTMATERIALS_H
#define REQUESTMATERIALS_H

class RequestMaterials
{
private:
  Material _material;
  QString _description;
  QDate _date;
  Provider _provider;
public:
  RequestMaterials();
  Material material() const;
  void setMaterial(const Material &material);
  QString description() const;
  void setDescription(const QString &description);
  QDate date() const;
  void setDate(const QDate &date);
  Provider provider() const;
  void setProvider(const Provider &provider);
};

#endif // REQUESTMATERIALS_H
