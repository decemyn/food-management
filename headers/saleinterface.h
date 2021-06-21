#ifndef SALEINTERFACE_H
#define SALEINTERFACE_H
#include "headers/fileio.h"
#include "headers/product.h"
#include "headers/userdomain.h"
#include <QDate>
#include <string>
#include <vector>
class SaleInterface {
private:
  inline static const std::string QuantityFormatting = "Quantity:";
  inline static const std::string UsernameFormatting = "User:";
  int ProductModulus = 3;

public:
  static std::string GenerateCurrentDate();
  static void GenerateProductSale(Product *, int);
};
#endif // SALEINTERFACE_H
