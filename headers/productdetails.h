#ifndef PRODUCTDETAILS_H
#define PRODUCTDETAILS_H

#include "headers/product.h"
#include <QMainWindow>

namespace Ui {
class ProductDetails;
}

class ProductDetails : public QMainWindow {
  Q_OBJECT

public:
  explicit ProductDetails(QWidget *parent = nullptr,
                          Product *DisplayProduct = nullptr);
  ~ProductDetails();

private:
  Ui::ProductDetails *ui;
  Product *DisplayProduct;

  void UiLoadProductInformation();
};

#endif // PRODUCTDETAILS_H
