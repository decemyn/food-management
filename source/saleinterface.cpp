#include "headers/saleinterface.h"
std::string SaleInterface::GenerateCurrentDate() {
  return QDate::currentDate().toString("dd/MM/yyyy").toStdString();
}
void SaleInterface::GenerateProductSale(Product *SoldProduct, int Quantity) {
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
}
