# food-management
Sistem înregistrare vânzări fast-food
Aplicația oferă posibilitatea de a introduce manual fiecare vânzare efectuată, de exemplu: Kebab - 2 bucăți - 26 RON.
-Utilizatorul poate vizualiza la sfârșitul zilei istoricul vânzărilor efectuate și cantitatea de bani câștigată în
ziua respectivă. 
-Utilizatorul poate utiliza aplicația pentru a vizualiza un istoric al vânzărilor pentru o zi anume.
-Aplicația oferă posiblitatea afișării anumitor statistici, precum: 
  cea mai profitabilă zi, 
  cel mai bine vândut produs,
  media cantităților comandate pentru fiecare produs în parte etc.!

# Documentation
---
## UserDomain documentation
### Documentation for the UserDomain class.
---
## UserDomain::DynamicAuthenticateUser(Username,Password)
#### This static method dynamicly authenticates the user (registers/authenticates).
## UserDomain::DeAuthenticateUser()
#### This static method deauthenticates the user.z
## UserDomain::GetUserState()
#### This static method returns the current user's authenthication state (AUTHENTICATED/NOT_AUTHENTICATED).
## UserDomain::GetUserName()
#### This static method returns the current authenticated username.
## UserDomain::AUTHENTICATED
#### This static class attribute, probes in a conditional statement if the user state is authentiacted.
## UserDomain::NOT_AUTHENTICATED
#### This static class attribute, probes in a conditional statement if the user state is not authentiacted.
---
## Product documentation
### Documentation for the Product class.
---
## Product::GetNumberOfProducts()
#### This static method returns the number of products in the products.json file.
## Product::LoadProductGenericInterface(ID)
#### This static generic interface automatically determines the product type and returns the appropriate pointer type for the product.
## Product::GenerateProductID()
#### This static method automatically generates the next product ID, by reading the meta.json file.
## Product/Food/Drink::FlushProductJson() - VIRTUAL
#### This instanced method flushes the product information to the products json.
## Product/Food/Drink::LoadProductJson() - VIRTUAL
#### This instanced method loads the product information from the products json.
## Product/Food/Drink::PrintProduct(QT_STREAM) - VIRTUAL
#### This instanced method prints the product information to a supplied QT output stream.
---
## SaleInterface documentation
### Documentation for the SaleInterface class.
---
## SaleInterface::GenerateProductSale(Product*,Quantity)
#### This static method generates a product sale for the current date in the sold_products.json file.
## SaleInterface::GenerateCurrentDate()
#### This static method returns the date at the time of execution.
---
## StatisticsInferface documentation
### Documentation for the StatisticsInferface class.
---
## StatisticsInferface::GetSoldProductsByDate(DateString)
#### This static method returns a std::vector of sold products in a certain date from the sold_products.json file.
## StatisticsInferface::GetProfitFromProductArray(SoldProductsArray)
#### This static method returns a the profit of the sold products in a certain date from a sold products array.
## StatisticsInferface::GetMostProfitableDay()
#### This static method returns the most profitable day.
## StatisticsInferface::GetMostSoldProduct()
#### This static method returns the most sold product.
