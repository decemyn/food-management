#ifndef PRODUCTADDER_H
#define PRODUCTADDER_H
#include "headers/product.h"
#include <QMainWindow>
#include <QMessageBox>
#include <headers/basewindow.h>

namespace Ui {
class ProductAdder;
}

class ProductAdder : public QMainWindow {
  Q_OBJECT

public:
  explicit ProductAdder(QWidget *parent = nullptr,
                        Ui::BaseWindow *ui_parent = nullptr);
  ~ProductAdder();

  static bool isNumber(std::string);

protected:
  void closeEvent(QCloseEvent *event) override;

private slots:

  void on_drink_checkbox_clicked();

  void on_pushButton_addProd_clicked();

private:
  Ui::ProductAdder *ui;
  Ui::BaseWindow *ui_parent;
  QWidget *parent;
};

#endif // PRODUCTADDER_H
