#include "headers/basewindow.h"
#include "headers/product.h"
#include "headers/userdomain.h"
#include "ui_basewindow.h"
BaseWindow::BaseWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::BaseWindow) {
  ui->setupUi(this);
  Product test(Product::GenerateProductID(), 50, 500, "Produs de tip produs");
  test.FlushProductJson();
  Product test_load(0);
  test_load.LoadProductJson();
  qDebug() << test_load;
  Drink test_drink(0, 50, 500, "Produs de tip drink", 30);
  test_drink.FlushProductJson();
  Drink test_load_drink(0);
  test_load_drink.LoadProductJson();
  qDebug() << test_load_drink;
}
BaseWindow::~BaseWindow() { delete ui; }
