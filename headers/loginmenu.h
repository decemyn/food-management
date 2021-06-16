#ifndef LOGINMENU_H
#define LOGINMENU_H
#include "headers/dialoglogin.h"
#include "headers/dialogregister.h"
#include <QDialog>
#include <QMainWindow>
#include <QWidget>

namespace Ui {
class LoginMenu;
}

class LoginMenu : public QMainWindow {
  Q_OBJECT

public:
  explicit LoginMenu(QWidget *parent = nullptr);
  ~LoginMenu();

protected:
  void closeEvent(QCloseEvent *event) override;

private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

private:
  Ui::LoginMenu *ui;
  QWidget *parent;
  DialogLogin *dialogLogin;
  DialogRegister *dialogRegister;
};

#endif // LOGINMENU_H
