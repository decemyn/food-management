#ifndef SELLREGISTER_H
#define SELLREGISTER_H
#include "headers/product.h"
#include "headers/saleinterface.h"
#include <QMainWindow>
#include <QMessageBox>
#include <headers/basewindow.h>
#include <string>
#include <vector>

namespace Ui {
class SellRegister;
}

class SellRegister : public QMainWindow {
  Q_OBJECT

public:
  explicit SellRegister(QWidget *parent = nullptr);
  ~SellRegister();

  void LoadProductsComboBox();

  static bool isNumber(std::string);

protected:
  void showEvent(QShowEvent *event) override;

private slots:
  void on_pushButton_clicked();

  void on_checkBox_clicked();

private:
  Ui::SellRegister *ui;
  Ui::BaseWindow *ui_parent;
  QWidget *parent;
  std::vector<Product *> ProductArray;
};

#endif // SELLREGISTER_H
