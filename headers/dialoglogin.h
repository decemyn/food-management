#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <headers/userdomain.h>
#include <ui_loginmenu.h>

namespace Ui {
class DialogLogin;
}

class DialogLogin : public QDialog {
  Q_OBJECT

public:
  explicit DialogLogin(QWidget *parent = nullptr,
                       Ui::LoginMenu *ui_parent = nullptr);
  ~DialogLogin();

protected:
  void closeEvent(QCloseEvent *event) override;

private slots:
  void on_pushButton_clicked();

private:
  Ui::DialogLogin *ui;
  Ui::LoginMenu *ui_parent;
  QWidget *parent;
};

#endif // DIALOGLOGIN_H
