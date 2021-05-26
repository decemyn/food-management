#ifndef LOGINMENU_H
#define LOGINMENU_H
#include "dialoglogin.h"
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

private:
  Ui::LoginMenu *ui;
  QWidget *parent;
  DialogLogin *dialogLogin;
};

#endif // LOGINMENU_H
