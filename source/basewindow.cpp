#include "headers/basewindow.h"
#include "ui_basewindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <headers/fileio.h>
#include <headers/product.h>
#include <string>
BaseWindow::BaseWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::BaseWindow) {
  ui->setupUi(this);
  /*FileIO fio_instance("/home/decemyn/GitProjects/test.json");
  fio_instance.writeStringToKey("name", "test1 spaces!!");
  QString file_status1 =
      QString("%1").arg(fio_instance.getValueFromKey("name").c_str());

  QMessageBox::information(this, tr("Application Name"), file_status1);
  fio_instance.writeStringToKey("name", "test2");
  QString file_status2 =
      QString("%1").arg(fio_instance.getValueFromKey("name").c_str());

  QMessageBox::information(this, tr("Application Name"), file_status2);*/
  Product test(1);
  qDebug() << test;
}

BaseWindow::~BaseWindow() { delete ui; }
