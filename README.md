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

## UserDomain::DynamicAuthenticateUser(Username,Password)
#### This static method dynamicly authenticates the user (registers/authenticates).
## UserDomain::DeAuthenticateUser()
#### This static method deauthenticates the user.
## UserDomain::GetUserState()
#### This static method returns the current user's authenthication state (AUTHENTICATED/NOT_AUTHENTICATED).
## UserDomain::GetUserName()
#### This static method returns the current authenticated username.
