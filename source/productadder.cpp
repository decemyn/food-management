#include "headers/productadder.h"
#include "ui_productadder.h"

ProductAdder::ProductAdder(QWidget *parent, Ui::BaseWindow *ui_parent)
    : QMainWindow(parent), ui(new Ui::ProductAdder) {
  ui->setupUi(this);
  this->ui_parent = ui_parent;
}

ProductAdder::~ProductAdder() { delete ui; }

void ProductAdder::on_drink_checkbox_clicked() {
  if (this->ui->drink_checkbox->isChecked()) {
    this->ui->label_size->setText("Ml :");
  } else {
    this->ui->label_size->setText("Gramaj :");
  }
}

void ProductAdder::on_pushButton_addProd_clicked() {
  bool InputOk = true;
  if (this->ui->lineEdit_nume->text().isEmpty() ||
      this->ui->lineEdit_calorii->text().isEmpty() ||
      this->ui->lineEdit_pret->text().isEmpty() ||
      this->ui->lineEdit_size->text().isEmpty()) {
    QMessageBox::warning(this, "Editare produse",
                         "Unul sau mai multe câmpuri este gol!");
    InputOk = false;
  }
  if (InputOk && ProductAdder::isNumber(
                     this->ui->lineEdit_pret->text().toStdString()) == false) {
    QMessageBox::warning(this, "Editare produse",
                         "Câmpul 'preț' trebuie să fie un număr!");
    InputOk = false;
  }
  if (InputOk &&
      ProductAdder::isNumber(
          this->ui->lineEdit_calorii->text().toStdString()) == false) {
    QMessageBox::warning(this, "Editare produse",
                         "Câmpul 'calorii' trebuie să fie un număr!");
    InputOk = false;
  }
  if (InputOk && ProductAdder::isNumber(
                     this->ui->lineEdit_size->text().toStdString()) == false) {
    QMessageBox::warning(this, "Editare produse",
                         "Câmpul de dimensiune trebuie să fie un număr!");
    InputOk = false;
  }
  if (InputOk) {
    if (this->ui->drink_checkbox->isChecked()) {
      Drink TempProduct(
          Product::GenerateProductID(),
          std::stoi(this->ui->lineEdit_pret->text().toStdString()),
          std::stoi(this->ui->lineEdit_calorii->text().toStdString()),
          this->ui->lineEdit_nume->text().toStdString(),
          std::stoi(this->ui->lineEdit_size->text().toStdString()));
      if (TempProduct.FlushProductJson()) {
        QMessageBox::information(this, "Editare produse",
                                 "Produsul a fost adaugat cu succes!");
        this->ui->lineEdit_calorii->setText("");
        this->ui->lineEdit_nume->setText("");
        this->ui->lineEdit_pret->setText("");
        this->ui->lineEdit_size->setText("");
      }
    } else {
      Food TempProduct(
          Product::GenerateProductID(),
          std::stoi(this->ui->lineEdit_pret->text().toStdString()),
          std::stoi(this->ui->lineEdit_calorii->text().toStdString()),
          this->ui->lineEdit_nume->text().toStdString(),
          std::stoi(this->ui->lineEdit_size->text().toStdString()));
      if (TempProduct.FlushProductJson()) {
        QMessageBox::information(this, "Editare produse",
                                 "Produsul a fost adaugat cu succes!");
        this->ui->lineEdit_calorii->setText("");
        this->ui->lineEdit_nume->setText("");
        this->ui->lineEdit_pret->setText("");
        this->ui->lineEdit_size->setText("");
      }
    }
  }
}

bool ProductAdder::isNumber(std::string s) {
  return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) {
                         return !std::isdigit(c);
                       }) == s.end();
}

void ProductAdder::closeEvent(QCloseEvent *event) {
  this->ui_parent->pushButton_3->setEnabled(true);
}
