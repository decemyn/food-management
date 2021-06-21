#include "headers/productdetails.h"
#include "ui_productdetails.h"

ProductDetails::ProductDetails(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ProductDetails) {
  ui->setupUi(this);
}

ProductDetails::~ProductDetails() { delete ui; }
