#include <headers/fileio.h>
FileIO::FileIO(QString FileName, bool Persistency) {
  this->Persistency = Persistency;
  this->JsonName = FileName;
  this->JsonPath = FileIO::GetJsonFile(FileName).toStdString();
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
  if (Persistency == false) {
    FileIO::RemoveJsonFile(this->JsonName);
  }
}

void FileIO::RefreshDocument() {
  try {
    if (this->CheckFileStatus() == true) {
      rapidjson::IStreamWrapper JsonISW =
          rapidjson::IStreamWrapper(this->JsonFH);
      this->JsonDocument.ParseStream(JsonISW);
      if (this->CheckForParseErrors()) {
        qDebug() << this->CheckForParseErrors();
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

const std::string FileIO::GetStringFromKey(std::string key) {
  return this->JsonDocument[key.c_str()].GetString();
}

void FileIO::WriteStringToKey(std::string key, std::string value) {
  rapidjson::StringBuffer buf{};
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buf);
  try {
    this->JsonFH.close();
    this->JsonOFH.open(this->JsonPath);
    rapidjson::Value KeyValue;
    KeyValue.SetString(rapidjson::StringRef(key.c_str()));
    rapidjson::Value InputValue;
    InputValue.SetString(rapidjson::StringRef(value),
                         this->JsonDocument.GetAllocator());
    if (this->JsonDocument.HasMember(KeyValue))
      this->JsonDocument[KeyValue] = InputValue;
    else
      this->JsonDocument.AddMember(KeyValue, InputValue,
                                   this->JsonDocument.GetAllocator());
    this->JsonDocument.Accept(writer);
    std::string JsonString(buf.GetString(), buf.GetSize());
    this->JsonOFH << JsonString;
    this->JsonOFH.flush();
    this->JsonOFH.close();
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

void FileIO::WriteArrayToKey(std::string key, std::vector<std::string> value) {
  rapidjson::StringBuffer buf{};
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buf);
  try {
    this->JsonFH.close();
    this->JsonOFH.open(this->JsonPath);
    rapidjson::Value KeyValue;
    KeyValue.SetString(rapidjson::StringRef(key.c_str()));
    rapidjson::Value InputValue;
    InputValue.SetArray();
    for (std::string &it : value) {
      rapidjson::Value StringValue;
      StringValue.SetString(rapidjson::StringRef(it));
      InputValue.PushBack(StringValue, this->JsonDocument.GetAllocator());
    }
    if (this->JsonDocument.HasMember(KeyValue))
      this->JsonDocument[KeyValue] = InputValue;
    else
      this->JsonDocument.AddMember(KeyValue, InputValue,
                                   this->JsonDocument.GetAllocator());
    this->JsonDocument.Accept(writer);
    std::string JsonString(buf.GetString(), buf.GetSize());
    this->JsonOFH << JsonString;
    this->JsonOFH.flush();
    this->JsonOFH.close();
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

std::vector<std::string> FileIO::GetArrayFromKey(std::string key) {
  std::vector<std::string> ReturnArray;
  for (rapidjson::SizeType itr = 0;
       itr < this->JsonDocument[key.c_str()].GetArray().Size(); itr++) {
    std::string UnpackedString =
        this->JsonDocument[key.c_str()].GetArray()[itr].GetString();
    ReturnArray.push_back(UnpackedString);
  }
  return ReturnArray;
}

void FileIO::RemoveKeyFromJson(std::string key) {
  rapidjson::StringBuffer buf{};
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buf);
  try {
    this->JsonFH.close();
    this->JsonOFH.open(this->JsonPath);
    rapidjson::Value KeyValue;
    KeyValue.SetString(rapidjson::StringRef(key.c_str()));
    if (this->JsonDocument.HasMember(KeyValue))
      this->JsonDocument.RemoveMember(KeyValue);
    this->JsonDocument.Accept(writer);
    std::string JsonString(buf.GetString(), buf.GetSize());
    this->JsonOFH << JsonString;
    this->JsonOFH.flush();
    this->JsonOFH.close();
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

// Static methods

void FileIO::GenStorageDirectory() {
  try {
    QDir StorageDirectory(
        QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    if (StorageDirectory.exists() == false) {
      StorageDirectory.mkpath(
          QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    }
  } catch (...) {
    qCritical() << "Error occured while generating the application storage "
                   "directory!";
    exit(EXIT_FAILURE);
  }
}

QDir FileIO::GetStorageDirectory() {
  try {
    QDir StorageDirectory(
        QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    if (StorageDirectory.exists()) {
      return StorageDirectory;
    } else {
      qCritical() << "Storage directory does not exist!";
      exit(EXIT_FAILURE);
    }
  } catch (...) {
    qCritical()
        << "Error occured while opening the application storage directory!";
    exit(EXIT_FAILURE);
  }
}

void FileIO::GenJsonFile(QString JsonName) {
  try {
    FileIO::GenStorageDirectory();
    QDir StorageDirectory = FileIO::GetStorageDirectory();
    QString FinalJsonPath = StorageDirectory.filePath(JsonName);
    QFile JsonFileHandle(FinalJsonPath);
    if (JsonFileHandle.exists() == false) {
      JsonFileHandle.open(QIODevice::WriteOnly);
      JsonFileHandle.write("{}");
      JsonFileHandle.close();
    }
  } catch (...) {
    qCritical() << "Error ocurred while generating json file!";
    exit(EXIT_FAILURE);
  }
}

QString FileIO::GetJsonFile(QString JsonName) {
  try {
    FileIO::GenJsonFile(JsonName);
    QDir StorageDirectory = FileIO::GetStorageDirectory();
    QString FinalJsonPath = StorageDirectory.filePath(JsonName);
    QFile JsonFileHandle(FinalJsonPath);
    if (JsonFileHandle.exists()) {
      return JsonFileHandle.fileName();
    } else {
      qCritical() << "File " << JsonName << " does not exist!";
      exit(EXIT_FAILURE);
    }
  } catch (...) {
    qCritical() << "Error ocurred while opening json file!";
    exit(EXIT_FAILURE);
  }
}

void FileIO::RemoveJsonFile(QString JsonName) {
  try {
    QDir StorageDirectory = FileIO::GetStorageDirectory();
    QString FinalJsonPath = StorageDirectory.filePath(JsonName);
    QFile JsonFileHandle(FinalJsonPath);
    if (JsonFileHandle.exists()) {
      JsonFileHandle.remove();
    } else {
      qCritical() << "File " << JsonName << " does not exist!";
      exit(EXIT_FAILURE);
    }
  } catch (...) {
    qCritical() << "Error ocurred while opening json file!";
    exit(EXIT_FAILURE);
  }
}
