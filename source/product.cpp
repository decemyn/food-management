#include <headers/product.h>

// Constructors
Product::Product(int ID, int price, int KCal, std::string ProductName) {
  this->ID = ID;
  this->Price = price;
  this->KCal = KCal;
  this->ProductName = ProductName;
}

Food::Food(int ID, int price, int KCal, std::string ProductName, int Weight)
    : Product(ID, price, KCal, ProductName) {
  this->Weight = Weight;
}

Drink::Drink(int ID, int price, int KCal, std::string ProductName, int Volume)
    : Product(ID, price, KCal, ProductName) {
  this->Volume = Volume;
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

int Food::getWeight() { return this->Weight; }

void Food::setWeight(int Weight) { this->Weight = Weight; }

int Drink::getVolume() { return this->Volume; }

void Drink::setVolume(int Volume) { this->Volume = Volume; }

// Output overloading

QDebug operator<<(QDebug debug, const Product &obj) { debug << "works?"; }
