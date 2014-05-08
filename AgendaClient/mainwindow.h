#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <providerdb.h>
#include <materialdb.h>
namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit MainWindow(QWidget *parent = 0);
  bool validationFieldsRequest(QString *msg);
  bool validationFieldsProvider(QString *msg);
  void loadComboboxes();
  ~MainWindow();
  
private slots:
  void on_actionSair_triggered();

  void on_btnAddProvider_clicked();

  void on_btnAddRequest_clicked();

  void on_btnLinkAddProvider_clicked();

  void on_cmbMaterial_currentIndexChanged(int index);

private:
  Ui::MainWindow *ui;
  ProviderDB *providerDB;
  MaterialDB *materialDB;
};

#endif // MAINWINDOW_H
