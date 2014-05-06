#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "requestmaterials.h"
#include "providerdb.h"

#include <QToolBox>
#include <QMessageBox>
#define string QString
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->txtDate->setDate(QDate::currentDate());
  setCentralWidget(ui->toolBox);

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

MainWindow::~MainWindow()
{
  delete ui;
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


  QMessageBox::information(this,"Agenda da Obra","Fornecedor adicionado com sucesso.",QMessageBox::Ok);
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
    ProviderDB db;
    Provider p;
    bool result = db.AddProvider(p);
    ui->toolBox->setCurrentIndex(1);
}
