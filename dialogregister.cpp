#include "dialogregister.h"
#include "ui_dialogregister.h"
#include <QMessageBox>

DialogRegister::DialogRegister(QWidget *parent)
    : QDialog(parent), ui(new Ui::DialogRegister) {
  ui->setupUi(this);
}

DialogRegister::~DialogRegister() { delete ui; }

void DialogRegister::on_pushButton_register_clicked() {
  QString username = ui->lineEdit_username->text();
  QString password = ui->lineEdit_password->text();
  QString password_conf = ui->lineEdit_password2->text();

  if (password != password_conf) {
    QMessageBox::warning(this, "Register", "The passwords don't match.");
  } else {
  }
}
