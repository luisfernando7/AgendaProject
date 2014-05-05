#include<QString>
#ifndef PROVIDER_H
#define PROVIDER_H

class Provider
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

#endif // PROVIDER_H
