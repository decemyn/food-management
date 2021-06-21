#ifndef STATISTICSINTERFACE_H
#define STATISTICSINTERFACE_H
#include "headers/fileio.h"
#include "headers/product.h"
#include "headers/saleinterface.h"
#include <map>
#include <string>
#include <vector>
class StatisticsInterface {
private:
  inline static const float ProfitMargin = 0.2;

public:
  static std::vector<Product *> GetSoldProductsByDate(std::string);

  static float GetProfitFromProductArray(std::vector<Product *>);

  static std::string GetMostProfitableDay();

  static Product *GetMostSoldProduct();
};

#endif // STATISTICSINTERFACE_H
