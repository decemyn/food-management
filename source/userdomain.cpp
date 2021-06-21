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

bool UserDomain::DynamicAuthenticateUser(QString Username, QString Password,
                                         bool Register) {
  if (UserDomain::AuthenticationState == NOT_AUTHENTICATED) {
    if (Register == true) {
      if (UserAccount::RegisterUser(Username, Password)) {
        UserDomain::SetUserState(Username.toStdString());
        return true;
      }
    } else if (UserAccount::AuthenticateUser(Username, Password)) {
      UserDomain::SetUserState(Username.toStdString());
      return true;
    }
    return false;
  } else
    return false;
}

void UserDomain::DeAuthenticateUser() { UserDomain::ClearUserState(); }

void UserDomain::UiSetUserName(QLabel *UsernameLabel) {
  if (UserDomain::AuthenticationState == AUTHENTICATED) {
    std::string UsernameText = "Salut, " + UserDomain::GetUserName() + "!";
    UsernameLabel->setText(QString::fromStdString(UsernameText));
  } else {
    std::string UsernameText = "Nu ești autentificat!";
    UsernameLabel->setText(QString::fromStdString(UsernameText));
  }
}

void UserDomain::UiButtonEnabler(QPushButton *ButtonLabel) {
  if (UserDomain::AuthenticationState == AUTHENTICATED) {
    ButtonLabel->setEnabled(true);
  } else {
    ButtonLabel->setEnabled(false);
  }
}
