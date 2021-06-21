#include "headers/loginmenu.h"
#include "ui_loginmenu.h"

LoginMenu::LoginMenu(QWidget *parent, Ui::BaseWindow *ui_parent)
    : QMainWindow(parent), ui(new Ui::LoginMenu) {
  ui->setupUi(this);
  ui->pushButton_logout->setVisible(false);
  this->parent = parent;
  this->ui_parent = ui_parent;
  this->UiSetButtonStates(true);
  parent->hide();
}

void LoginMenu::closeEvent(QCloseEvent *event) {
  this->parent->show();
  UserDomain::UiSetUserName(this->ui_parent->currentUsername);
  UserDomain::UiButtonEnabler(this->ui_parent->pushButton_1);
  UserDomain::UiButtonEnabler(this->ui_parent->pushButton_2);
  UserDomain::UiButtonEnabler(this->ui_parent->pushButton_3);
}

LoginMenu::~LoginMenu() { delete ui; }

void LoginMenu::on_pushButton_clicked() {
  dialogLogin = new DialogLogin(this, this->ui);
  this->UiDisableButtons(true);
  dialogLogin->show();
}

void LoginMenu::on_pushButton_2_clicked() {
  dialogRegister = new DialogRegister(this, this->ui);
  this->UiDisableButtons(true);
  dialogRegister->show();
}

void LoginMenu::on_pushButton_logout_clicked() {
  UserDomain::DeAuthenticateUser();
  this->UiSetButtonStates(true);
}

void LoginMenu::UiSetButtonStates(bool ActivationState) {
  if (ActivationState == true &&
      UserDomain::GetUserState() == NOT_AUTHENTICATED) {
    this->ui->pushButton->setVisible(true);
    this->ui->pushButton_2->setVisible(true);
    this->ui->pushButton_logout->setVisible(false);
  } else {
    this->ui->pushButton->setVisible(false);
    this->ui->pushButton_2->setVisible(false);
    this->ui->pushButton_logout->setVisible(true);
  }
}

void LoginMenu::UiDisableButtons(bool DisableState) {
  if (DisableState == true) {
    this->ui->pushButton->setEnabled(false);
    this->ui->pushButton_2->setEnabled(false);
  } else {
    this->ui->pushButton->setEnabled(true);
    this->ui->pushButton_2->setEnabled(true);
  }
}
