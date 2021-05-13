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

FileIO::~FileIO() {
  if (this->JsonFH.is_open())
    this->JsonFH.close();
  if (this->JsonOFH.is_open())
    this->JsonOFH.close();
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

const std::string FileIO::getStringFromKey(std::string key) {
  return this->JsonDocument[key.c_str()].GetString();
}

void FileIO::writeStringToKey(std::string key, std::string value) {
  rapidjson::StringBuffer buf{};
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buf);
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

void FileIO::writeArrayToKey(std::string key, std::vector<std::string> value) {
  rapidjson::StringBuffer buf{};
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buf);
  try {
    if (this->JsonDocument.HasMember(key.c_str())) {
      this->JsonFH.close();
      this->JsonOFH.open(this->JsonPath);
      rapidjson::Value InputValue;
      InputValue.SetArray();
      for (std::string it : value) {
        rapidjson::Value StringValue;
        StringValue.SetString(rapidjson::StringRef(it));
        InputValue.PushBack(StringValue, this->JsonDocument.GetAllocator());
      }
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

std::vector<std::string> FileIO::getArrayFromKey(std::string key) {
  std::vector<std::string> ReturnArray;
  for (rapidjson::SizeType itr = 0;
       itr < this->JsonDocument[key.c_str()].GetArray().Size(); itr++) {
    std::string UnpackedString =
        this->JsonDocument[key.c_str()].GetArray()[itr].GetString();
    ReturnArray.push_back(UnpackedString);
  }
  return ReturnArray;
}
