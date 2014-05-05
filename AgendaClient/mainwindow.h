#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
  ~MainWindow();
  
private slots:
  void on_actionSair_triggered();

  void on_btnAddProvider_clicked();

  void on_btnAddRequest_clicked();

  void on_btnLinkAddProvider_clicked();

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
