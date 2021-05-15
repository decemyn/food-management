#include <headers/userdomain.h>
void UserDomain::SetUserState(std::string Username) {
  UserDomain::CurrentUser = Username;
  UserDomain::AuthenticationState = AUTHENTICATED;
}

void UserDomain::ClearUserState() {
  UserDomain::CurrentUser = EMPTY_USER;
  UserDomain::AuthenticationState = NOT_AUTHENTICATED;
}

bool UserDomain::GetUserState() { return UserDomain::AuthenticationState; }

std::string UserDomain::GetUserName() { return UserDomain::CurrentUser; }

bool UserDomain::DynamicAuthenticateUser(QString Username, QString Password) {
  if (UserAccount::RegisterUser(Username, Password)) {
    UserDomain::SetUserState(Username.toStdString());
    return true;
  } else if (UserAccount::AuthenticateUser(Username, Password)) {
    UserDomain::SetUserState(Username.toStdString());
    return true;
  }
  return false;
}

void UserDomain::DeAuthenticateUser() { UserDomain::ClearUserState(); }
