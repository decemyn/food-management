#include "headers/productadder.h"
#include "ui_productadder.h"

ProductAdder::ProductAdder(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ProductAdder) {
  ui->setupUi(this);
}

ProductAdder::~ProductAdder() { delete ui; }
