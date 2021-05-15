#include <headers/useraccount.h>
std::string UserAccount::HashString(QString Password) {
  char HashedString[crypto_pwhash_STRBYTES];
  if (crypto_pwhash_str(HashedString, Password.toStdString().c_str(),
                        strlen(Password.toStdString().c_str()),
                        crypto_pwhash_OPSLIMIT_INTERACTIVE,
                        crypto_pwhash_MEMLIMIT_INTERACTIVE) != 0) {
    qCritical()
        << "Application ran out of memory while trying to hash a password!";
    exit(EXIT_FAILURE);
  }
  return HashedString;
}

bool UserAccount::MatchWithHash(std::string RawString,
                                std::string HashedString) {
  if (crypto_pwhash_str_verify(HashedString.c_str(), RawString.c_str(),
                               strlen(RawString.c_str())) != 0) {
    return false;
  }
  return true;
}
bool UserAccount::RegisterUser(QString Username, QString Password) {
  FileIO JsonWriterReader("users.json");
  if (JsonWriterReader.GetStringFromKey(Username.toStdString()).length() == 0) {
    JsonWriterReader.WriteStringToKey(Username.toStdString(),
                                      UserAccount::HashString(Password));
    return true;
  }
  return false;
}

bool UserAccount::AuthenticateUser(QString Username, QString Password) {
  FileIO JsonWriterReader("users.json");
  if (JsonWriterReader.GetStringFromKey(Username.toStdString()).length() != 0) {
    if (UserAccount::MatchWithHash(
            Password.toStdString(),
            JsonWriterReader.GetStringFromKey(Username.toStdString())))
      return true;
  }
  return false;
}
