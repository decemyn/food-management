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
  ProductAdder *product_adder = new ProductAdder(this);
  product_adder->show();
}

void BaseWindow::on_pushButton_1_clicked() {
  SellRegister *sell_product = new SellRegister(this);
  sell_product->show();
}
