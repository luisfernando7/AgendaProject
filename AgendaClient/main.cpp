#include "mainwindow.h"
#include "xmlmananger.h"
#include "requestmaterialsdb.h"
#include <QApplication>


int main(int argc, char *argv[])
{

    /*Several testes*/
    RequestMaterialsDB db;
    QString data = XMLMananger::BuildRequestMaterial(db.SelectAll()[0]);
    XMLMananger::ParseRequestMaterial(data);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
