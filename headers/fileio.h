#ifndef FILEIO_H
#define FILEIO_H
#include <QDebug>
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
  std::ifstream JsonFH;
  std::ofstream JsonOFH;
  std::string JsonPath;
  rapidjson::StringBuffer JsonBuffer{};
  rapidjson::Document JsonDocument{};

public:
  FileIO(const std::string &);

  virtual ~FileIO();

  bool CheckFileStatus();

  bool CheckForParseErrors();

  const std::string getStringFromKey(std::string);

  void writeStringToKey(std::string, std::string);

  void writeArrayToKey(std::string, std::vector<std::string>);

  std::vector<std::string> getArrayFromKey(std::string);

  void RefreshDocument();
};

#endif // FILEIO_H
