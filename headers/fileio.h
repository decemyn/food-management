#ifndef FILEIO_H
#define FILEIO_H
#include <QDebug>
#include <fstream>
#include <include/rapidjson/document.h>
#include <include/rapidjson/istreamwrapper.h>
#include <include/rapidjson/ostreamwrapper.h>
#include <include/rapidjson/reader.h>
#include <include/rapidjson/stringbuffer.h>
#include <include/rapidjson/writer.h>
#include <string>
class FileIO {
private:
  std::ifstream JsonFH;
  std::ofstream JsonOFH;
  std::string JsonPath;
  rapidjson::StringBuffer JsonBuffer{};
  rapidjson::Document JsonDocument{};

public:
  FileIO(const std::string &);

  bool CheckFileStatus();

  bool CheckForParseErrors();

  const std::string getValueFromKey(const std::string);

  void writeStringToKey(std::string, std::string);

  void RefreshDocument();
};

#endif // FILEIO_H
