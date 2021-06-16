#ifndef LOGINMENU_H
#define LOGINMENU_H
#include "headers/dialoglogin.h"
#include "headers/dialogregister.h"
#include "ui_basewindow.h"
#include <QCloseEvent>
#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QWidget>
#include <QtGui>
#include <headers/userdomain.h>

namespace Ui {
class LoginMenu;
}

class LoginMenu : public QMainWindow {
  Q_OBJECT

public:
  explicit LoginMenu(QWidget *parent = nullptr,
                     Ui::BaseWindow *ui_parent = nullptr);
  ~LoginMenu();

public slots:
  void UiSetButtonStates(bool);

  void UiDisableButtons(bool);

protected:
  void closeEvent(QCloseEvent *event) override;

private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_logout_clicked();

private:
  Ui::LoginMenu *ui;
  Ui::BaseWindow *ui_parent;
  QWidget *parent;
  DialogLogin *dialogLogin;
  DialogRegister *dialogRegister;
};

#endif // LOGINMENU_H
