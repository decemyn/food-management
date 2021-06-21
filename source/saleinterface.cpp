#include "headers/saleinterface.h"
std::string SaleInterface::GenerateCurrentDate() {
  std::string CurrentDate =
      QDate::currentDate().toString("dd/MM/yyyy").toStdString();
  FileIO JsonWriterReader("meta.json");
  try {
    std::vector<std::string> DatesArray =
        JsonWriterReader.GetArrayFromKey("sale_dates");
    if (DatesArray.size()) {
      bool FoundCurrentDate = false;
      for (auto Date : DatesArray) {
        if (Date == CurrentDate) {
          FoundCurrentDate = true;
          break;
        }
      }
      if (FoundCurrentDate == false) {
        DatesArray.push_back(CurrentDate);
        JsonWriterReader.WriteArrayToKey("sale_dates", DatesArray);
      }
    } else {
      std::vector<std::string> DatesArray = {};
      DatesArray.push_back(CurrentDate);
      JsonWriterReader.WriteArrayToKey("sale_dates", DatesArray);
    }
  } catch (...) {
    qCritical() << "Failed to write current date in the meta json!";
    exit(EXIT_FAILURE);
  }
  return CurrentDate;
}
bool SaleInterface::GenerateProductSale(Product *SoldProduct, int Quantity) {
  FileIO JsonWriterReader("sold_products.json");
  std::string CurrentDate = SaleInterface::GenerateCurrentDate();
  std::vector<std::string> SoldProductsFromCurrentDate =
      JsonWriterReader.GetArrayFromKey(CurrentDate);
  try {
    if (SoldProductsFromCurrentDate.size() == 0) {
      std::vector<std::string> ProductInformation = {};
      ProductInformation.push_back((std::to_string(SoldProduct->getID())));
      ProductInformation.push_back(SaleInterface::UsernameFormatting +
                                   UserDomain::GetUserName());
      ProductInformation.push_back(SaleInterface::QuantityFormatting +
                                   std::to_string(Quantity));
      JsonWriterReader.WriteArrayToKey(CurrentDate, ProductInformation);
    } else {
      SoldProductsFromCurrentDate.push_back(
          (std::to_string(SoldProduct->getID())));
      SoldProductsFromCurrentDate.push_back(SaleInterface::UsernameFormatting +
                                            UserDomain::GetUserName());
      SoldProductsFromCurrentDate.push_back(SaleInterface::QuantityFormatting +
                                            std::to_string(Quantity));
      JsonWriterReader.WriteArrayToKey(CurrentDate,
                                       SoldProductsFromCurrentDate);
    }
  } catch (...) {
    qCritical() << "Failed to generate product sale for product with ID "
                << SoldProduct->getID();
    exit(EXIT_FAILURE);
  }
  return true;
}
