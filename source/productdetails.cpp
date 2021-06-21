#include "headers/productdetails.h"
#include "ui_productdetails.h"


ProductDetails::ProductDetails(QWidget *parent, Product *DisplayProduct)
    : QMainWindow(parent), ui(new Ui::ProductDetails) {
  ui->setupUi(this);
  this->DisplayProduct = DisplayProduct;
  this->UiLoadProductInformation();
}

ProductDetails::~ProductDetails() { delete ui; }

void ProductDetails::UiLoadProductInformation() {
  if (dynamic_cast<Drink *>(this->DisplayProduct)) {
    this->ui->label_size_text->setText("Volum produs :");
    this->ui->label_size_type->setText("Ml");
    this->ui->label_size->setText(QString::fromStdString(std::to_string(
        dynamic_cast<Drink *>(this->DisplayProduct)->getVolume())));
  } else {
    this->ui->label_size_text->setText("Gramaj produs :");
    this->ui->label_size_type->setText("g");
    this->ui->label_size->setText(QString::fromStdString(std::to_string(
        dynamic_cast<Food *>(this->DisplayProduct)->getWeight())));
  }
  this->ui->label_name->setText(
      QString::fromStdString(this->DisplayProduct->getProductName()));
  this->ui->label_price->setText(
      QString::fromStdString(std::to_string(this->DisplayProduct->getPrice())));
  this->ui->label_calorii->setText(
      QString::fromStdString(std::to_string(this->DisplayProduct->getKCal())));
  this->ui->label_ID->setText(
      QString::fromStdString(std::to_string(this->DisplayProduct->getID())));
}
