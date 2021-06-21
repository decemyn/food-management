#include "headers/basewindow.h"
#include "ui_basewindow.h"

BaseWindow::BaseWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::BaseWindow) {
  ui->setupUi(this);
  UserDomain::UiSetUserName(this->ui->currentUsername);
}

BaseWindow::~BaseWindow() { delete ui; }

void BaseWindow::on_pushButton_clicked() {
  LoginMenu *login = new LoginMenu(this, this->ui);
  login->show();
}

void BaseWindow::on_pushButton_3_clicked() {
  this->ui->pushButton_3->setEnabled(false);
  this->ui->pushButton->setEnabled(false);
  ProductAdder *product_adder = new ProductAdder(this, this->ui);
  product_adder->show();
}

void BaseWindow::on_pushButton_1_clicked() {
  this->ui->pushButton_1->setEnabled(false);
  this->ui->pushButton->setEnabled(false);
  SellRegister *sell_product = new SellRegister(this, this->ui);
  sell_product->show();
}

void BaseWindow::on_pushButton_2_clicked() {
  this->ui->pushButton_2->setEnabled(false);
  this->ui->pushButton->setEnabled(false);
  StatisticsMenu *statistics_menu = new StatisticsMenu(this, this->ui);
  statistics_menu->show();
}
