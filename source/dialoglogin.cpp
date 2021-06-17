#include "headers/dialoglogin.h"
#include "headers/loginmenu.h"
#include "ui_dialoglogin.h"

DialogLogin::DialogLogin(QWidget *parent, Ui::LoginMenu *ui_parent)
    : QDialog(parent), ui(new Ui::DialogLogin) {
  ui->setupUi(this);
  this->parent = parent;
  this->ui_parent = ui_parent;
}

DialogLogin::~DialogLogin() { delete ui; }

void DialogLogin::on_pushButton_clicked() {
  QString username = ui->lineEdit_username->text();
  QString password = ui->lineEdit_password->text();
  if (UserDomain::DynamicAuthenticateUser(username, password, false) == true) {
    QMessageBox::information(this, "Login", "Te-ai autentificat cu succes!");
    LoginMenu *LoginMenuObj = qobject_cast<LoginMenu *>(this->parent);
    if (LoginMenuObj != 0) {
      LoginMenuObj->UiSetButtonStates(false);
    }
    this->close();
    this->parent->close(); // same here :3
  } else {
    QMessageBox::warning(this, "Login", "Eroare la autentificare!");
    ui->lineEdit_username->setText(QString(""));
    ui->lineEdit_password->setText(QString(""));
  }
}

void DialogLogin::closeEvent(QCloseEvent *event) {
  LoginMenu *LoginMenuObj = qobject_cast<LoginMenu *>(this->parent);
  if (LoginMenuObj != 0) {
    LoginMenuObj->UiDisableButtons(false);
  }
}
