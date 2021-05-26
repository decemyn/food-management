#include "headers/loginmenu.h"
#include "ui_loginmenu.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <QtGui>

LoginMenu::LoginMenu(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::LoginMenu) {
  ui->setupUi(this);
  this->parent = parent;
  parent->hide();
}

void LoginMenu::closeEvent(QCloseEvent *event) { this->parent->show(); }

LoginMenu::~LoginMenu() { delete ui; }

void LoginMenu::on_pushButton_clicked() {
  /*
   * Dialog example but you also need to declare the instace in
   DialogLogin dialogLogin;
   dialogLogin.setModal(true);
   dialogLogin.exec();
   *
   */
  dialogLogin = new DialogLogin(this);
  dialogLogin->show();
  // dialogLogin->close();
}

void LoginMenu::on_pushButton_2_clicked() {
  dialogRegister = new DialogRegister(this);
  dialogRegister->show();
}
