#ifndef DIALOGREGISTER_H
#define DIALOGREGISTER_H

#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <headers/userdomain.h>
#include <ui_loginmenu.h>

namespace Ui {
class DialogRegister;
}

class DialogRegister : public QDialog {
  Q_OBJECT

public:
  explicit DialogRegister(QWidget *parent = nullptr,
                          Ui::LoginMenu *ui_parent = nullptr);
  ~DialogRegister();

protected:
  void closeEvent(QCloseEvent *event) override;

private slots:
  void on_pushButton_register_clicked();

private:
  Ui::DialogRegister *ui;
  Ui::LoginMenu *ui_parent;
  QWidget *parent;
};

#endif // DIALOGREGISTER_H
