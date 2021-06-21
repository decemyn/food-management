#include <headers/product.h>

// Constructors
Product::Product(int ID, int price, int KCal, std::string ProductName) {
  this->ID = ID;
  this->Price = price;
  this->KCal = KCal;
  this->ProductName = ProductName;
  this->ProductType = "Product";
}

Food::Food(int ID, int price, int KCal, std::string ProductName, int Weight)
    : Product(ID, price, KCal, ProductName) {
  this->Weight = Weight;
  this->ProductType = "Food";
}

Drink::Drink(int ID, int price, int KCal, std::string ProductName, int Volume)
    : Product(ID, price, KCal, ProductName) {
  this->Volume = Volume;
  this->ProductType = "Drink";
}

// Getter and setters
int Product::getID() { return this->ID; }

void Product::setID(int ID) { this->ID = ID; }

int Product::getPrice() { return this->Price; }

void Product::setPrice(int Price) { this->Price = Price; }

int Product::getKCal() { return this->KCal; }

void Product::setKCal(int KCal) { this->KCal = KCal; }

std::string Product::getProductName() { return this->ProductName; }

void Product::setProductName(std::string ProductName) {
  this->ProductName = ProductName;
}

std::string Product::getProductType() { return this->ProductType; }

void Product::setProductType(std::string ProductType) {
  this->ProductType = ProductType;
}

int Food::getWeight() { return this->Weight; }

void Food::setWeight(int Weight) { this->Weight = Weight; }

int Drink::getVolume() { return this->Volume; }

void Drink::setVolume(int Volume) { this->Volume = Volume; }

// Output, Input and Overloading

void Product::PrintProduct(QDebug debug) const {
  debug << this->ID << " " << this->Price << " "
        << QString::fromStdString(this->ProductName) << " " << this->KCal
        << '\n';
}

void Food::PrintProduct(QDebug debug) const {
  debug << this->ID << " " << this->Price << " "
        << QString::fromStdString(this->ProductName) << " " << this->KCal
        << this->Weight << '\n';
}

void Drink::PrintProduct(QDebug debug) const {
  debug << this->ID << " " << this->Price << " "
        << QString::fromStdString(this->ProductName) << " " << this->KCal
        << this->Volume << '\n';
}

QDebug operator<<(QDebug debug, const Product &obj) { obj.PrintProduct(debug); }

bool Product::FlushProductJson() {
  FileIO JsonWriterReader("products.json");
  try {
    std::vector<std::string> ProductInformation = {};
    ProductInformation.push_back(std::to_string(this->Price));
    ProductInformation.push_back(std::to_string(this->KCal));
    ProductInformation.push_back(this->ProductName);
    ProductInformation.push_back(this->ProductType);
    JsonWriterReader.WriteArrayToKey(std::to_string(this->ID),
                                     ProductInformation);
  } catch (...) {
    qCritical() << "Error while flushing product with ID " << this->ID;
    exit(EXIT_FAILURE);
  }
  return true;
}

bool Food::FlushProductJson() {
  FileIO JsonWriterReader("products.json");
  try {
    std::vector<std::string> ProductInformation = {};
    ProductInformation.push_back(std::to_string(this->Price));
    ProductInformation.push_back(std::to_string(this->KCal));
    ProductInformation.push_back(this->ProductName);
    ProductInformation.push_back(std::to_string(this->Weight));
    ProductInformation.push_back(this->ProductType);
    JsonWriterReader.WriteArrayToKey(std::to_string(this->ID),
                                     ProductInformation);
  } catch (...) {
    qCritical() << "Error while flushing product with ID " << this->ID;
    exit(EXIT_FAILURE);
  }
  return true;
}

bool Drink::FlushProductJson() {
  FileIO JsonWriterReader("products.json");
  try {
    std::vector<std::string> ProductInformation = {};
    ProductInformation.push_back(std::to_string(this->Price));
    ProductInformation.push_back(std::to_string(this->KCal));
    ProductInformation.push_back(this->ProductName);
    ProductInformation.push_back(std::to_string(this->Volume));
    ProductInformation.push_back(this->ProductType);
    JsonWriterReader.WriteArrayToKey(std::to_string(this->ID),
                                     ProductInformation);
  } catch (...) {
    qCritical() << "Error while flushing product with ID " << this->ID;
    exit(EXIT_FAILURE);
  }
  return true;
}

void Product::LoadProductJson() {
  FileIO JsonWriterReader("products.json");
  std::vector<std::string> ProductInformation =
      JsonWriterReader.GetArrayFromKey(std::to_string(this->ID));
  try {
    this->Price = std::stoi(ProductInformation.at(0).c_str());
    this->KCal = std::stoi(ProductInformation.at(1).c_str());
    this->ProductName = ProductInformation.at(2);
  } catch (...) {
    qCritical() << "Product with ID" << this->ID << "does not exist!";
    exit(EXIT_FAILURE);
  }
}

void Food::LoadProductJson() {
  FileIO JsonWriterReader("products.json");
  std::vector<std::string> ProductInformation =
      JsonWriterReader.GetArrayFromKey(std::to_string(this->ID));
  try {
    this->Price = std::stoi(ProductInformation.at(0).c_str());
    this->KCal = std::stoi(ProductInformation.at(1).c_str());
    this->ProductName = ProductInformation.at(2);
    this->Weight = std::stoi(ProductInformation.at(3).c_str());
  } catch (...) {
    qCritical() << "Product with ID" << this->ID << "does not exist!";
    exit(EXIT_FAILURE);
  }
}

void Drink::LoadProductJson() {
  FileIO JsonWriterReader("products.json");
  std::vector<std::string> ProductInformation =
      JsonWriterReader.GetArrayFromKey(std::to_string(this->ID));
  try {
    this->Price = std::stoi(ProductInformation.at(0).c_str());
    this->KCal = std::stoi(ProductInformation.at(1).c_str());
    this->ProductName = ProductInformation.at(2);
    this->Volume = std::stoi(ProductInformation.at(3).c_str());
  } catch (...) {
    qCritical() << "Product with ID" << this->ID << "does not exist!";
    exit(EXIT_FAILURE);
  }
}

int Product::GenerateProductID() {
  FileIO JsonWriterReader("meta.json");
  if (JsonWriterReader.GetStringFromKey("number_of_products").empty()) {
    JsonWriterReader.WriteStringToKey("number_of_products", "0");
    return 0;
  } else {
    int NumberOfProducts =
        std::stoi(JsonWriterReader.GetStringFromKey("number_of_products")) + 1;
    JsonWriterReader.WriteStringToKey("number_of_products",
                                      std::to_string(NumberOfProducts));
    return NumberOfProducts;
  }
}

Product *Product::LoadProductGenericInterface(int ID) {
  Product *GenericProduct;
  FileIO JsonWriterReader("products.json");
  std::vector<std::string> ProductInformation =
      JsonWriterReader.GetArrayFromKey(std::to_string(ID));
  try {
    int ProductInformationLength = ProductInformation.size();
    std::string ProductType =
        ProductInformation.at(ProductInformationLength - 1);
    if (ProductType == "Food") {
      GenericProduct = new Food(ID);
    } else if (ProductType == "Drink") {
      GenericProduct = new Drink(ID);
    }
    GenericProduct->LoadProductJson();
  } catch (...) {
    qCritical() << "Product with ID" << ID << "does not exist!";
    exit(EXIT_FAILURE);
  }
  return GenericProduct;
}

int Product::GetNumberOfProducts() {
  FileIO JsonWriterReader("meta.json");
  std::string NumberOfProducts =
      JsonWriterReader.GetStringFromKey("number_of_products");
  if (NumberOfProducts.empty()) {
    return 0;
  } else {
    return std::stoi(NumberOfProducts) + 1;
  }
}
