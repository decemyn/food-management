#include "headers/statisticsinterface.h"
std::vector<Product *>
StatisticsInterface::GetSoldProductsByDate(std::string DateString) {
  FileIO JsonWriterReader("sold_products.json");
  try {
    std::vector<std::string> SoldProductsRawArray = {};
    SoldProductsRawArray = JsonWriterReader.GetArrayFromKey(DateString);
    std::vector<Product *> SoldProductsArray = {};
    int JsonDataIterator = 1;
    for (auto JsonData : SoldProductsRawArray) {
      if (JsonDataIterator % (SaleInterface::ProductModulus) == 1) {
        SoldProductsArray.push_back(
            Product::LoadProductGenericInterface(std::stoi(JsonData)));
      }
      JsonDataIterator++;
    }
    return SoldProductsArray;
  } catch (...) {
    qCritical() << "Error ocurred while loading sold products from date"
                << QString::fromStdString(DateString);
    exit(EXIT_FAILURE);
  }
}
float StatisticsInterface::GetProfitFromProductArray(
    std::vector<Product *> SoldProductsArray) {
  int ProductPriceSum = 0;
  for (auto Product : SoldProductsArray) {
    ProductPriceSum += Product->getPrice();
  }
  return ProductPriceSum * StatisticsInterface::ProfitMargin;
}

std::string StatisticsInterface::GetMostProfitableDay() {
  FileIO JsonWriterReader("meta.json");
  float MaxProfitDay = 0.0;
  std::string MaxProfitDate = "";
  try {
    std::vector<std::string> SaleDates =
        JsonWriterReader.GetArrayFromKey("sale_dates");
    for (auto Date : SaleDates) {
      float DateCalculatedProfit =
          StatisticsInterface::GetProfitFromProductArray(
              StatisticsInterface::GetSoldProductsByDate(Date));
      if (DateCalculatedProfit > MaxProfitDay) {
        MaxProfitDay = DateCalculatedProfit;
        MaxProfitDate = Date;
      }
    }
  } catch (...) {
    qCritical() << "Error ocurred while loading the sale dates value from the "
                   "meta.json file";
    exit(EXIT_FAILURE);
  }
  if (MaxProfitDate.empty() == false) {
    return MaxProfitDate + " Profit: " + std::to_string(MaxProfitDay);
  } else {
    return "Nu există vânzări înregistrate!";
  }
}

Product *StatisticsInterface::GetMostSoldProduct() {
  FileIO JsonWriterReader("meta.json");
  std::map<int, int> ProductFreqMap = {};
  int MaxSoldProduct = 0;
  int MaxSoldProductID = -1;
  try {
    std::vector<std::string> SaleDates =
        JsonWriterReader.GetArrayFromKey("sale_dates");
    for (auto Date : SaleDates) {
      std::vector<Product *> SoldProductsArray =
          StatisticsInterface::GetSoldProductsByDate(Date);
      for (auto CurrentProduct : SoldProductsArray) {
        if (ProductFreqMap.count(CurrentProduct->getID()) == 1) {
          ProductFreqMap.at(CurrentProduct->getID()) += 1;
        } else {
          std::pair<int, int> ProductFreqPair = {CurrentProduct->getID(), 1};
          ProductFreqMap.insert(ProductFreqPair);
        }
      }
    }
    for (auto ProductFreqPair : ProductFreqMap) {
      if (ProductFreqPair.second > MaxSoldProduct) {
        MaxSoldProduct = ProductFreqPair.second;
        MaxSoldProductID = ProductFreqPair.first;
      }
    }
    if (MaxSoldProductID != -1) {
      return Product::LoadProductGenericInterface(MaxSoldProductID);
    } else
      return nullptr;
  } catch (...) {
    qCritical() << "Error ocurred while loading the sale dates value from the "
                   "meta.json file";
    exit(EXIT_FAILURE);
  }
}
