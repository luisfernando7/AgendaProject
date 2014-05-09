#include<QList>
#ifndef DB_H
#define DB_H
template <typename T>
class DB
{
public:
    virtual bool Insert(T &obj)=0;
    virtual bool Update(T &obj)=0;
    virtual bool Delete(int id)=0;
    virtual T Select(int id)=0;
    virtual QList<T> SelectAll()=0;
    virtual int Count()=0;
};
#endif // DB_H
