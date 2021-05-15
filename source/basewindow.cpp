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
  FileIO fio_instance("test2.json");
  std::vector<std::string> array{"testing", "testedddd"};
  fio_instance.WriteArrayToKey("test", array);
  fio_instance.WriteStringToKey("test", "replaced");
  fio_instance.WriteStringToKey("test", "replacedd");
  fio_instance.WriteStringToKey("test", "replaceddddd");
  fio_instance.WriteArrayToKey("test1", array);
  fio_instance.WriteArrayToKey("test2", array);
  fio_instance.WriteArrayToKey("test3", array);
  fio_instance.WriteStringToKey("test4", "replaceddddd");
  fio_instance.RemoveKeyFromJson("test4");
  fio_instance.RemoveKeyFromJson("test33232");
}

BaseWindow::~BaseWindow() { delete ui; }
