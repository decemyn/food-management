#ifndef PRODUCT_H
#define PRODUCT_H
#include <QDebug>
#include <headers/fileio.h>
#include <string>
class Product {
protected:
  int ID, Price, KCal;
  std::string ProductName;
  std::string ProductType;

public:
  Product(int ID, int price = -1, int KCal = -1, std::string ProductName = "");

  static int GenerateProductID();

  static Product *LoadProductGenericInterface(int);

  virtual bool FlushProductJson();

  virtual void LoadProductJson();

  virtual void PrintProduct(QDebug) const;

  friend QDebug operator<<(QDebug debug, const Product &);

  int getID();

  void setID(int);

  int getPrice();

  void setPrice(int);

  int getKCal();

  void setKCal(int);

  std::string getProductName();

  void setProductName(std::string);

  std::string getProductType();

  void setProductType(std::string);
};

class Food : public Product {
protected:
  int Weight;

public:
  Food(int ID, int price = -1, int KCal = -1, std::string ProductName = "",
       int Weight = -1);

  bool FlushProductJson();

  void LoadProductJson();

  void PrintProduct(QDebug) const;

  int getWeight();

  void setWeight(int);
};

class Drink : public Product {
protected:
  int Volume;

public:
  Drink(int ID, int price = -1, int KCal = -1, std::string ProductName = "",
        int Volume = -1);

  bool FlushProductJson();

  void LoadProductJson();

  void PrintProduct(QDebug) const;

  int getVolume();

  void setVolume(int);
};

#endif // PRODUCT_H
