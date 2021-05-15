#ifndef FILEIO_H
#define FILEIO_H
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QStandardPaths>
#include <fstream>
#include <include/rapidjson/document.h>
#include <include/rapidjson/istreamwrapper.h>
#include <include/rapidjson/ostreamwrapper.h>
#include <include/rapidjson/prettywriter.h>
#include <include/rapidjson/reader.h>
#include <include/rapidjson/stringbuffer.h>
#include <string>
#include <vector>
class FileIO {
private:
  bool Persistency;
  std::ifstream JsonFH;
  std::ofstream JsonOFH;
  std::string JsonPath;
  QString JsonName;
  rapidjson::StringBuffer JsonBuffer{};
  rapidjson::Document JsonDocument{};

  static void GenStorageDirectory();

  static QDir GetStorageDirectory();

public:
  FileIO(QString, bool Persistency = true);

  virtual ~FileIO();

  bool CheckFileStatus();

  bool CheckForParseErrors();

  void RemoveKeyFromJson(std::string);

  const std::string GetStringFromKey(std::string);

  void WriteStringToKey(std::string, std::string);

  void WriteArrayToKey(std::string, std::vector<std::string>);

  std::vector<std::string> GetArrayFromKey(std::string);

  void RefreshDocument();

  static void GenJsonFile(QString);

  static QString GetJsonFile(QString);

  static void RemoveJsonFile(QString);
};

#endif // FILEIO_H
