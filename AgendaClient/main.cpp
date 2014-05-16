#include "mainwindow.h"
#include "xmlmananger.h"
#include "requestmaterialsdb.h"
#include <QApplication>
#include <qdebug.h>

int main(int argc, char *argv[])
{

    /*Several testes*/
    RequestMaterialsDB db;
    QString data = XMLMananger::BuildRequestMaterial(db.SelectAll()[0]);
    model::RequestMaterials rm = XMLMananger::ParseRequestMaterial(data);
    qDebug()<<" ID : "+ QString::number(rm.material().getId());
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
