#include "headers/sellregister.h"
#include "ui_sellregister.h"

SellRegister::SellRegister(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SellRegister) {
  ui->setupUi(this);
}

SellRegister::~SellRegister() { delete ui; }

void SellRegister::on_pushButton_clicked() {
  if (isNumber(this->ui->lineEdit->text().toStdString())) {
    for (auto Product : this->ProductArray) {
      if ((Product->getProductName() +
           " ID:" + std::to_string(Product->getID())) ==
          this->ui->comboBox->currentText().toStdString()) {
        if (SaleInterface::GenerateProductSale(
                Product, std::stoi(this->ui->lineEdit->text().toStdString()))) {
          QMessageBox::warning(this, "Vânzare produse",
                               "Vânzare efectuată cu succes!");
          this->ui->lineEdit->setText("");
          break;
        }
      }
    }
  } else {
    if (this->ui->lineEdit->text().isEmpty()) {
      QMessageBox::warning(this, "Vânzare produse",
                           "Câmpul 'cantitate' nu poate să fie gol!");
    } else {
      QMessageBox::warning(this, "Vânzare produse",
                           "Câmpul 'cantiate' trebuie să fie un număr!");
    }
  }
}

void SellRegister::LoadProductsComboBox() {
  this->ui->comboBox->clear();
  int NumberOfProducts = Product::GetNumberOfProducts();
  if (NumberOfProducts) {
    std::vector<Product *> ProductArray = {};
    if (NumberOfProducts) {
      for (int ID = 0; ID < NumberOfProducts; ID++) {
        Product *LoadedProduct = Product::LoadProductGenericInterface(ID);
        ProductArray.push_back(LoadedProduct);
      }
    }
    this->ProductArray = ProductArray;
    for (auto Product : ProductArray) {
      if (this->ui->checkBox->isChecked()) {
        if (dynamic_cast<Drink *>(Product)) {
          this->ui->comboBox->addItem(
              QString::fromStdString(Product->getProductName()) + " ID:" +
              QString::fromStdString(std::to_string(Product->getID())));
        }
      } else {
        if (dynamic_cast<Food *>(Product)) {
          this->ui->comboBox->addItem(
              QString::fromStdString(Product->getProductName()) + " ID:" +
              QString::fromStdString(std::to_string(Product->getID())));
        }
      }
    }
  } else {
    this->ui->comboBox->addItem("Nu există produse!");
    QMessageBox::warning(this, "Vânzare produse",
                         "Nu există produse in baza de date!");
    this->ui->pushButton->setEnabled(false);
  }
}

void SellRegister::showEvent(QShowEvent *event) {
  this->LoadProductsComboBox();
}

void SellRegister::on_checkBox_clicked() { this->LoadProductsComboBox(); }

bool SellRegister::isNumber(std::string s) {
  return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) {
                         return !std::isdigit(c);
                       }) == s.end();
}
