#ifndef USERACCOUNT_H
#define USERACCOUNT_H
#include <headers/fileio.h>
#include <sodium.h>
class UserAccount {
private:
  static bool MatchWithHash(std::string, std::string);

  static std::string HashString(QString);

protected:
  static bool RegisterUser(QString, QString);

  static bool AuthenticateUser(QString, QString);
};

#endif // USERACCOUNT_H
