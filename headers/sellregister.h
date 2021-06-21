#ifndef SELLREGISTER_H
#define SELLREGISTER_H
#include <QMainWindow>
#include <headers/basewindow.h>

namespace Ui {
class SellRegister;
}

class SellRegister : public QMainWindow {
  Q_OBJECT

public:
  explicit SellRegister(QWidget *parent = nullptr);
  ~SellRegister();

private:
  Ui::SellRegister *ui;
  Ui::BaseWindow *ui_parent;
  QWidget *parent;
};

#endif // SELLREGISTER_H
