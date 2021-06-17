#include "headers/dialogregister.h"
#include "headers/loginmenu.h"
#include "ui_dialogregister.h"

DialogRegister::DialogRegister(QWidget *parent, Ui::LoginMenu *ui_parent)
    : QDialog(parent), ui(new Ui::DialogRegister) {
  ui->setupUi(this);
  this->ui_parent = ui_parent;
  this->parent = parent;
}

DialogRegister::~DialogRegister() { delete ui; }

void DialogRegister::on_pushButton_register_clicked() {
  QString username = ui->lineEdit_username->text();
  QString password = ui->lineEdit_password->text();
  QString password_conf = ui->lineEdit_password2->text();

  if (password != password_conf) {
    QMessageBox::warning(this, "Register", "Parolele introduse nu coincid!");
    ui->lineEdit_password->setText(QString(""));
    ui->lineEdit_password2->setText(QString(""));
  } else {
    if (UserDomain::DynamicAuthenticateUser(username, password, true) == true) {
      QMessageBox::information(this, "Register",
                               "Te-ai inregistrat cu succes!");
      this->parent
          ->close(); // am adugat asta ca dupa register sa te bage direct in
                     // main menu si daca vrea da dea log ou trebuie sa intre
      LoginMenu *LoginMenuObj = qobject_cast<LoginMenu *>(this->parent);
      if (LoginMenuObj != 0) {
        LoginMenuObj->UiSetButtonStates(false);
      }
      this->close();
    } else {
      QMessageBox::warning(this, "Register",
                           "Acest nume de utlizator este luat!");
      ui->lineEdit_username->setText(QString(""));
      ui->lineEdit_password->setText(QString(""));
      ui->lineEdit_password2->setText(QString(""));
    }
  }
}

void DialogRegister::closeEvent(QCloseEvent *event) {
  LoginMenu *LoginMenuObj = qobject_cast<LoginMenu *>(this->parent);
  if (LoginMenuObj != 0) {
    LoginMenuObj->UiDisableButtons(false);
  }
}
