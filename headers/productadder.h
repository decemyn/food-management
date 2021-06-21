#ifndef PRODUCTADDER_H
#define PRODUCTADDER_H
#include <QMainWindow>
#include <headers/basewindow.h>

namespace Ui {
class ProductAdder;
}

class ProductAdder : public QMainWindow {
  Q_OBJECT

public:
  explicit ProductAdder(QWidget *parent = nullptr);
  ~ProductAdder();

private:
  Ui::ProductAdder *ui;
  Ui::BaseWindow *ui_parent;
  QWidget *parent;
};

#endif // PRODUCTADDER_H
