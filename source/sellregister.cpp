#include "headers/sellregister.h"
#include "ui_sellregister.h"

SellRegister::SellRegister(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SellRegister) {
  ui->setupUi(this);
}

SellRegister::~SellRegister() { delete ui; }
