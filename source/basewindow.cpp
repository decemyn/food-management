#include "headers/basewindow.h"
#include "ui_basewindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <headers/fileio.h>
#include <headers/product.h>
#include <string>
#include <vector>
BaseWindow::BaseWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::BaseWindow) {
  ui->setupUi(this);
  FileIO fio_instance("/home/decemyn/GitProjects/test.json");
  fio_instance.writeArrayToKey("name", std::vector<std::string>{"da", "yess"});
  // fio_instance.writeStringToKey("name", "test2");
  for (std::string i : fio_instance.getArrayFromKey("name")) {
    qDebug() << QString::fromStdString(i);
  }
}

BaseWindow::~BaseWindow() { delete ui; }
