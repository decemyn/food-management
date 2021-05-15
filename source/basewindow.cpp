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
}

BaseWindow::~BaseWindow() { delete ui; }
