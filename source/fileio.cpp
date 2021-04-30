#include <headers/fileio.h>
FileIO::FileIO(const std::string &FilePath) {
  this->JsonPath = FilePath;
  this->JsonFH.open(this->JsonPath);
  if (this->CheckFileStatus()) {
    this->RefreshDocument();
  } else {
    qCritical() << "Error occured while opening JSON file!";
    exit(EXIT_FAILURE);
  }
}

void FileIO::RefreshDocument() {
  try {
    if (this->CheckFileStatus() == true) {
      rapidjson::IStreamWrapper JsonISW =
          rapidjson::IStreamWrapper(this->JsonFH);
      this->JsonDocument.ParseStream(JsonISW);
      if (this->CheckForParseErrors()) {
        qCritical() << "Error occured while parsing JSON document!";
        exit(EXIT_FAILURE);
      }
    }
  } catch (...) {
    qCritical() << "Error occured while refreshing JSON document!";
    exit(EXIT_FAILURE);
  }
}

bool FileIO::CheckFileStatus() { return this->JsonFH.is_open(); }

bool FileIO::CheckForParseErrors() {
  return this->JsonDocument.HasParseError();
}

const std::string FileIO::getValueFromKey(const std::string key) {
  return this->JsonDocument[key.c_str()].GetString();
}

void FileIO::writeStringToKey(std::string key, std::string value) {
  rapidjson::StringBuffer buf{};
  rapidjson::Writer<rapidjson::StringBuffer> writer(buf);
  try {
    if (this->JsonDocument.HasMember(key.c_str())) {
      this->JsonFH.close();
      this->JsonOFH.open(this->JsonPath);
      rapidjson::Value InputValue;
      InputValue.SetString(rapidjson::StringRef(value));
      this->JsonDocument[key.c_str()] = InputValue;
      this->JsonDocument.Accept(writer);
      std::string JsonString(buf.GetString(), buf.GetSize());
      this->JsonOFH << JsonString;
      this->JsonOFH.flush();
      this->JsonOFH.close();
    } else {
      qCritical() << "Key doesn't exist in JSON file!";
      exit(EXIT_FAILURE);
    }
  } catch (...) {
    qCritical() << "Error occured while writing value in JSON!";
    exit(EXIT_FAILURE);
  }
  this->JsonFH.open(this->JsonPath);
  if (this->CheckFileStatus()) {
    this->RefreshDocument();
  } else {
    qCritical() << "Error occured while opening JSON file!";
    exit(EXIT_FAILURE);
  }
}
