#ifndef USERDOMAIN_H
#define USERDOMAIN_H
#define EMPTY_USER ""
#define NOT_AUTHENTICATED false
#define AUTHENTICATED true
#include <QLabel>
#include <QPushButton>
#include <headers/useraccount.h>
class UserDomain : private UserAccount {
private:
  inline static std::string CurrentUser = EMPTY_USER;
  inline static bool AuthenticationState = NOT_AUTHENTICATED;

  static void ClearUserState();

  static void SetUserState(std::string);

public:
  static bool DynamicAuthenticateUser(QString, QString, bool);

  static bool GetUserState();

  static std::string GetUserName();

  static void UiSetUserName(QLabel *);

  static void UiButtonEnabler(QPushButton *);

  static void DeAuthenticateUser();
};

#endif // USERDOMAIN_H
