#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "requestmaterials.h"
#include "providerdb.h"

#include <QMetaType>
#include <QToolBox>
#include <QMessageBox>
#define string QString
#define List QList

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    providerDB = new ProviderDB;
    materialDB = new MaterialDB;
    ui->setupUi(this);
    ui->txtDate->setDate(QDate::currentDate());
    setCentralWidget(ui->toolBox);
    loadComboboxes();
}

bool MainWindow::validationFieldsRequest(QString *msg)
{
    if(ui->txtMaterialName->text().isEmpty())
    {
        *msg = "Por favor, preencha o campo \"Nome\".";
        ui->txtMaterialName->setFocus();
        ui->txtMaterialName->setStyleSheet("QLineEdit { background-color: rgb(210,1,20) }");
        return false;
    }
    else
        ui->txtMaterialName->setStyleSheet("QLineEdit { background-color: white }");

    if(ui->txtUnitType->text().isEmpty())
    {
        *msg = "Por favor, preencha o campo \"Tipo de unidade\".";
        ui->txtUnitType->setFocus();
        ui->txtUnitType->setStyleSheet("QLineEdit { background-color: rgb(210,1,20) }");
        return false;
    }
    else ui->txtUnitType->setStyleSheet("QLineEdit { background-color: white }");

    if(ui->txtPrice->text().replace(",",".").toDouble() <= 0.0)
    {
        *msg = "Por favor, preencha o campo \"Preço\".";
        ui->txtPrice->setFocus();
        ui->txtPrice->setStyleSheet("QLineEdit { background-color: red }");
        return false;
    }
    else ui->txtPrice->setStyleSheet("QLineEdit { background-color: white }");

    if(ui->txtQtd->text().isEmpty())
    {
        *msg = "Por favor, preencha o campo \"Quantidade\".";
        ui->txtQtd->setFocus();
        ui->txtQtd->setStyleSheet("QLineEdit { background-color: red }");
        return false;
    }
    else ui->txtQtd->setStyleSheet("QLineEdit { background-color: white }");

    if(ui->txtDate->text().isEmpty())
    {
        *msg = "Por favor, informe o campo \"Data\".";
        ui->txtDate->setFocus();
        ui->txtDate->setStyleSheet("QLineEdit { background-color: red }");
        return false;
    }
    else ui->txtDate->setStyleSheet("QLineEdit { background-color: white }");

    if(ui->cmbProvider->currentIndex() <= 0)
    {
        //TODO: finalizar
    }

    return true;
}

bool MainWindow::validationFieldsProvider(QString *msg)
{
    if(ui->txbProviderName->text().isEmpty())
    {
        *msg = "Por favor, preencha o campo \"Nome\".";
        ui->txbProviderName->setFocus();
        ui->txbProviderName->setStyleSheet("QLineEdit { background-color: rgb(210,1,20) }");
        return false;
    }
    else
        ui->txbProviderName->setStyleSheet("QLineEdit { background-color: white }");

    if(ui->txbPhone->text().length()<8)
    {
        *msg = "Por favor, preencha o campo \"Telefone\".";
        ui->txbPhone->setFocus();
        ui->txbPhone->setStyleSheet("QLineEdit { background-color: rgb(210,1,20) }");
        return false;
    }
    else
        ui->txbPhone->setStyleSheet("QLineEdit { background-color: white }");

    if(ui->txbNumber->text().toInt() <=0)
    {
        *msg = "Por favor, preencha o campo \"Número\".";
        ui->txbNumber->setFocus();
        ui->txbNumber->setStyleSheet("QLineEdit { background-color: rgb(210,1,20) }");
        return false;
    }
    else
        ui->txbNumber->setStyleSheet("QLineEdit { background-color: white }");

    if(ui->txbStreet->text().isEmpty())
    {
        *msg = "Por favor, preencha o campo \"Rua\".";
        ui->txbStreet->setFocus();
        ui->txbStreet->setStyleSheet("QLineEdit { background-color: rgb(210,1,20) }");
        return false;
    }
    else
        ui->txbStreet->setStyleSheet("QLineEdit { background-color: white }");

    return true;
}

void MainWindow::loadComboboxes()
{
    //Carregar materiais
    //TODO: implementar rápido essa parada

    ui->cmbMaterial->setCurrentIndex(-1);
    List<model::Material> materials =  materialDB->SelectAll();
    if(materials.count() <= 0) return;
    foreach (model::Material m, materials)
    {
        ui->cmbMaterial->addItem(m.name(),QVariant::fromValue(m));
    }




    //Carregar Fornecedores
    List<model::Provider> providers =  providerDB->SelectAll();
    if(providers.count() <= 0) return;
    foreach (model::Provider p, providers)
    {
        ui->cmbProvider->addItem(p.name(),QVariant::fromValue(p));
    }
    //model::Provider pr = ui->cmbProvider->itemData(0).value<model::Provider>(); //Adicionar objeto ao combo.
    ui->cmbProvider->setCurrentIndex(-1);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete providerDB;
}

void MainWindow::on_actionSair_triggered()
{
    exit(0);
}

void MainWindow::on_btnAddProvider_clicked()
{
    string *message = new string;
    if(!validationFieldsProvider(message))
    {
        ui->lblInfoProvider->setText(*message);
        return;
    }
    delete message;

    model::Provider p;
    p.setName(ui->txbProviderName->text());
    p.setNumber(ui->txbNumber->text().toInt());
    p.setPhoneNumber(ui->txbPhone->text());
    p.setStreet(ui->txbStreet->text());
    if(providerDB->Insert(p))
    {
        QMessageBox::information(this,"Agenda da Obra","Fornecedor adicionado com sucesso.",QMessageBox::Ok);
        ui->brnClearFieldProvider->click();
    }
    else
        QMessageBox::information(this,"Agenda da Obra","Erro ao adicionar Fornecedor.",QMessageBox::Ok);
}

void MainWindow::on_btnAddRequest_clicked()
{
    string *message = new string;
    if(!validationFieldsRequest(message))
    {
        ui->lblInformation->setText(*message);
        return;
    }
    ui->lblInformation->setText("");
    delete message;
    QMessageBox::information(this,"Agenda da Obra","Adicionado com sucesso",QMessageBox::Ok);

}

void MainWindow::on_btnLinkAddProvider_clicked()
{
    ui->toolBox->setCurrentIndex(1);
}

void MainWindow::on_cmbMaterial_currentIndexChanged(int index)
{

    if(ui->cmbMaterial->currentIndex() > -1)
    {
        model::Material m = ui->cmbMaterial->itemData(index).value<model::Material>();
        ui->txtMaterialName->setText(m.name());
        ui->txtUnitType->setText(m.unity());
        ui->txtPrice->setText(QString::number(m.prince()));
        //Deixo os campos readOnly
        ui->txtMaterialName->setReadOnly(true);
        ui->txtUnitType->setReadOnly(true);
        ui->txtPrice->setReadOnly(true);
    }
}
